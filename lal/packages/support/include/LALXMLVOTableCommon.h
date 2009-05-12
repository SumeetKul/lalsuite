/*
*  Copyright (C) 2009 Oliver Bock
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with with program; see the file COPYING. If not, write to the
*  Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
*  MA  02111-1307  USA
*/

/**
 * \file
 * \ingroup XML
 * \brief Header file declaring the public common VOTable XML API
 */

#include <libxml/tree.h>


/**
 * \brief List of all supported LAL parameters with a VOTable \c PARAM element attribute mapping
 *
 * This enumeration contains all supported LAL parameters that are mapped to their corresponding
 * VOTable \c PARAM element attributes. Note: this parameter list only contains non-structured members.\n
 * \b Important: the actual LAL<->VOTable type map is maintained in \ref XLALGetLALVOTableParamMapEntry
 * and \b must be in sync with this enumeration!
 *
 * \sa XLALGetLALVOTableParamMapEntry
 *
 * \todo The type map should be implemented as an associative array (hash map, enum wouldn't be needed)!
 *
 * \author Oliver Bock\n
 * Albert-Einstein-Institute Hannover, Germany
 */
typedef enum {
    ENUM_BEGIN,
    LIGOTimeGPS_gpsSeconds,
    LIGOTimeGPS_gpsNanoSeconds,
    BinaryOrbitParams_argp,
    BinaryOrbitParams_asini,
    BinaryOrbitParams_ecc,
    BinaryOrbitParams_period,
    PulsarDopplerParams_Alpha,
    PulsarDopplerParams_Delta,
    PulsarDopplerParams_fkdot,
    ENUM_END
} LAL_VOTABLE_PARAM;


INT4 XLALGetLALVOTableParamMapEntry(const LAL_VOTABLE_PARAM type,
                                    const char **const structure,
                                    const char **const member,
                                    const char **const unit,
                                    const char **const datatype,
                                    const char **const arraysize);

xmlNodePtr XLALCreateVOTableCustomParamNode(const char *name,
                                            const char *unit,
                                            const char *datatype,
                                            const char *arraysize,
                                            const char *value);

xmlNodePtr XLALCreateVOTableTypedParamNode(const LAL_VOTABLE_PARAM type, const char *value);

xmlNodePtr XLALCreateVOTableResourceNode(const char *type,
                                         const char *identifier,
                                         const xmlNodePtr *children,
                                         const INT4 childCount);

xmlDocPtr XLALCreateVOTableXMLFromTree(const xmlNodePtr xmlTree);

INT4 XLALCreateVOTableStringFromTree(const xmlNodePtr xmlTree, xmlChar **xmlStringBuffer, INT4 *xmlStringBufferSize);
