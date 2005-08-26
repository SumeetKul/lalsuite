/*-----------------------------------------------------------------------
 *
 * File Name: NormalizeSFTRndMed.c
 *
 * Authors: Krishnan, B and Sintes, A
 *
 * Revision: $Id$
 *
 * History: Created by B. Krishnan Aug, 2004
 *       Taken from SFTbin.c and PeakSelect.c from hough dir in lalapps
 * 
 *-----------------------------------------------------------------------
 */

/************************************ <lalVerbatim file="NormalizeSFTRngMedCV">
Author: Krishnan, B.
$Id$
************************************* </lalVerbatim> */

/* <lalLaTeX>  *******************************************************
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\section{Module \texttt{NormalizeSFTRngMed.c}}
\label{ss:NormalizeSFTRngMed.c}


Normalizing SFTs using the Running median

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\subsubsection*{Prototypes}
\vspace{0.1in}
\input{NormalizeSFTRngMedD}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\subsubsection*{Description}

Normalizing SFTs using the Running Median


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\subsubsection*{Uses}
\begin{verbatim}
LALHO()
\end{verbatim}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\subsubsection*{Notes}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\vfill{\footnotesize\input{NormalizeSFTRngMedCV}}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

*********************************************** </lalLaTeX> */


#include <lal/NormalizeSFTRngMed.h>



NRCSID (NORMALIZESFTRNGMEDC, "$Id$");

/*
 * The functions that make up the guts of this module
 */


/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/********************************* <lalVerbatim file="NormalizeSFTRngMedD"> */
void LALSFTtoPeriodogram (LALStatus    *status,
			  REAL8FrequencySeries    *periodo,
			  COMPLEX8FrequencySeries *SFT)
{/*   *********************************************  </lalVerbatim> */
 /* Calculates the periodogram for a given SFT */

  INT4     length, j;
  REAL8    *out, re, im, factor;
  COMPLEX8 *in;

  INITSTATUS (status, "LALSFTtoPeriodogram", NORMALIZESFTRNGMEDC);
  ATTATCHSTATUSPTR (status);

  /* check argments are not NULL */
  ASSERT (periodo, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (periodo->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (periodo->data->length > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL); 
  ASSERT (periodo->data->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (SFT, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL);  
  ASSERT (SFT->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (SFT->data->length > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL);  
  ASSERT (SFT->data->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 

  /* copy values from SFT */
  periodo->epoch.gpsSeconds = SFT->epoch.gpsSeconds;
  periodo->epoch.gpsNanoSeconds = SFT->epoch.gpsNanoSeconds;
  periodo->f0 = SFT->f0;
  periodo->deltaF = SFT->deltaF;

  /* check lengths are same */
  length = SFT->data->length;
  ASSERT (length == periodo->data->length, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL);  

  factor = periodo->deltaF; /* normalization factor */
  out = periodo->data->data;
  in = SFT->data->data;

  for (j=0; j<length; j++) {
    re = in->re;
    im = in->im;
    *out = (re*re + im*im) * factor;
    ++out;
    ++in;
  }

  DETATCHSTATUSPTR (status);
  /* normal exit */
  RETURN (status);
}




/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
/* *******************************  <lalVerbatim file="NormalizeSFTRngMedD"> */
/* calculates running median for a periodogram */
void LALPeriodoToPSDRngMed (LALStatus  *status,
			    REAL8FrequencySeries  *psd,
			    REAL8FrequencySeries  *periodo,
			    INT4                  blockSize)
{/*   *********************************************  </lalVerbatim> */
  INT4 blocks2, j, length;
  LALRunningMedianPar rngMedPar;
  REAL8Sequence mediansV, inputV;
  REAL8 *medians, medianBias;

  INITSTATUS (status, "LALPeriodoToPSDRngMed", NORMALIZESFTRNGMEDC);
  ATTATCHSTATUSPTR (status);

  /* check argments are not NULL */
  ASSERT (periodo, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (periodo->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (periodo->data->length > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL); 
  ASSERT (periodo->data->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (psd, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL);  
  ASSERT (psd->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (psd->data->length > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL);  
  ASSERT (psd->data->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (blockSize > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL); 


  /* copy values from the periodogram */
  psd->epoch.gpsSeconds = periodo->epoch.gpsSeconds;
  psd->epoch.gpsNanoSeconds = periodo->epoch.gpsNanoSeconds;
  psd->f0 = periodo->f0;
  psd->deltaF = periodo->deltaF;

  /* check lengths are same */
  length = periodo->data->length;
  ASSERT (length == psd->data->length, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL);  

  blocks2 = blockSize/2;

  rngMedPar.blocksize = (UINT4)blockSize;
  inputV.length = length;
  inputV.data = periodo->data->data;
  mediansV.length= length - blockSize + 1;
  mediansV.data = psd->data->data + blocks2;    

  TRY( LALDRunningMedian2(status->statusPtr, &mediansV, &inputV, rngMedPar), status);

  for (j=0; j<blocks2; j++)
    psd->data->data[j] = psd->data->data[blocks2];

  for (j=blocks2+length-blockSize+1; j<length; j++)
    psd->data->data[j] = psd->data->data[blocks2 + length-blockSize];


  /* get the bias factor */
  TRY ( LALRngMedBias( status->statusPtr, &medianBias, blockSize ), status);

  /* normalize by the bias factor */
  for (j=0; j<length; j++)
    psd->data->data[j] /= medianBias;

  /* normalize according to RngMedBias */

  DETATCHSTATUSPTR (status);
  /* normal exit */
  RETURN (status);
}




/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
/* *******************************  <lalVerbatim file="NormalizeSFTRngMedD"> */
/* normalizes a sft based on RngMed */
void LALNormalizeSFT (LALStatus  *status,
		      SFTtype  *sft,
		      INT4     blockSize)
{/*   *********************************************  </lalVerbatim> */
  INT4 j, length;
  REAL8FrequencySeries *psd=NULL, *periodo=NULL;

  INITSTATUS (status, "LALNormalizeSFT", NORMALIZESFTRNGMEDC);
  ATTATCHSTATUSPTR (status);

  /* check argments are not NULL and other sanity checks*/
  ASSERT (sft, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (sft->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (sft->data->length > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL); 
  ASSERT (sft->data->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (blockSize > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL); 

  length = sft->data->length;
  
  psd = (REAL8FrequencySeries *)LALMalloc(sizeof(REAL8FrequencySeries));
  psd->data = NULL;
  psd->data = (REAL8Sequence *)LALMalloc(sizeof(REAL8Sequence));
  psd->data->length = length;
  psd->data->data = (REAL8 *)LALMalloc( length * sizeof(REAL8));

  periodo = (REAL8FrequencySeries *)LALMalloc(sizeof(REAL8FrequencySeries));
  periodo->data = NULL;
  periodo->data = (REAL8Sequence *)LALMalloc(sizeof(REAL8Sequence));
  periodo->data->length = length;
  periodo->data->data = (REAL8 *)LALMalloc( length * sizeof(REAL8));

  /* calculate the periodogram */
  TRY (LALSFTtoPeriodogram (status->statusPtr, periodo, sft), status);

  /* calculate the psd */
  TRY (LALPeriodoToPSDRngMed (status->statusPtr, psd, periodo, blockSize), status);

  /* loop over sft and normalize */
  for (j=0; j<length; j++) {
    REAL8 Sn;
    Sn = psd->data->data[j]; 
    sft->data->data[j].re *= sft->deltaF/sqrt(Sn); /* check */
    sft->data->data[j].im *= sft->deltaF/sqrt(Sn); /* check */
  }

  LALFree(psd->data->data);
  LALFree(psd->data);
  LALFree(psd);
  LALFree(periodo->data->data);
  LALFree(periodo->data);
  LALFree(periodo);

  DETATCHSTATUSPTR (status);
  /* normal exit */
  RETURN (status);
}



/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
/* *******************************  <lalVerbatim file="NormalizeSFTRngMedD"> */
void LALNormalizeSFTVect (LALStatus  *status,
			  SFTVector  *sftVect,
			  INT4     blockSize)
{/*   *********************************************  </lalVerbatim> */
  /* normalizes a sft vector using RngMed */
  INT4 j, length;

  INITSTATUS (status, "LALNormalizeSFT", NORMALIZESFTRNGMEDC);
  ATTATCHSTATUSPTR (status);

  /* check argments are not NULL and other sanity checks*/
  ASSERT (sftVect, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (sftVect->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
  ASSERT (sftVect->length > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL); 
  ASSERT (blockSize > 0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL); 


  length = sftVect->length;
  /* loop over sfts and normalize them */
  for (j=0; j<length; j++) {
    SFTtype *sft;
    
    ASSERT (sftVect->data + j, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
    sft = sftVect->data + j;
    ASSERT (sft->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
    ASSERT (sft->data->length>0, status, NORMALIZESFTRNGMEDH_EVAL, NORMALIZESFTRNGMEDH_MSGEVAL); 
    ASSERT (sft->data->data, status, NORMALIZESFTRNGMEDH_ENULL, NORMALIZESFTRNGMEDH_MSGENULL); 
    TRY (LALNormalizeSFT (status->statusPtr, sft, blockSize), status);
  }

  DETATCHSTATUSPTR (status);
  /* normal exit */
  RETURN (status);
}















