REAL8 tmp5=coeffs->KK*eta;
REAL8 tmp48=-1.+tmp5;
REAL8 tmp57=(1.0/(x->data[0]*x->data[0]));
REAL8 tmp60=1/x->data[0];
REAL8 tmp56=sigmaKerr->data[2]*sigmaKerr->data[2];
REAL8 tmp145=x->data[0]*x->data[0];
REAL8 tmp53=(1.0/(tmp48*tmp48));
REAL8 tmp54=1.*tmp53;
REAL8 tmp58=1.*tmp56*tmp57;
REAL8 tmp59=1/tmp48;
REAL8 tmp81=2.*tmp59*tmp60;
REAL8 tmp82=tmp54+tmp58+tmp81;
REAL8 tmp153=coeffs->k0*eta;
REAL8 tmp156=1./(x->data[0]*x->data[0]*x->data[0]*x->data[0]);
REAL8 tmp157=1.*coeffs->k4*tmp156;
REAL8 tmp158=1./(x->data[0]*x->data[0]*x->data[0]);
REAL8 tmp159=1.*coeffs->k3*tmp158;
REAL8 tmp160=1.*coeffs->k2*tmp57;
REAL8 tmp161=1.*coeffs->k1*tmp60;
REAL8 tmp164=pow(x->data[0],-5.);
REAL8 tmp165=1.*tmp60;
REAL8 tmp166=log(tmp165);
REAL8 tmp167=coeffs->k5l*tmp166;
REAL8 tmp168=coeffs->k5+tmp167;
REAL8 tmp169=1.*tmp164*tmp168;
REAL8 tmp170=1.+tmp157+tmp159+tmp160+tmp161+tmp169;
REAL8 tmp190=log(tmp170);
REAL8 tmp191=eta*tmp190;
REAL8 tmp192=1.+tmp153+tmp191;
REAL8 tmp149=0.+tmp145;
REAL8 tmp152=1/tmp149;
REAL8 tmp206=-3.*eta;
REAL8 tmp196=tmp145+tmp56;
REAL8 tmp212=26.+tmp206;
REAL8 tmp213=2.*eta*tmp158*tmp212;
REAL8 tmp214=6.*eta*tmp57;
REAL8 tmp215=1.+tmp213+tmp214;
REAL8 tmp216=log(tmp215);
REAL8 tmp217=1.+tmp216;
REAL8 tmp218=tmp82*tmp82;
REAL8 tmp219=(x->data[0]*x->data[0]*x->data[0]*x->data[0]);
REAL8 tmp220=tmp192*tmp192;
REAL8 tmp221=tmp217*tmp218*tmp219*tmp220;
REAL8 tmp208=1.*p->data[0];
REAL8 tmp209=0.+tmp208;
REAL8 tmp222=1./sqrt(tmp221);
REAL8 tmp223=1/tmp196;
REAL8 tmp224=sqrt(tmp221);
REAL8 tmp225=tmp223*tmp224;
REAL8 tmp226=-1.+tmp225;
REAL8 tmp207=4.+tmp206;
REAL8 tmp237=1.*e3z;
REAL8 tmp238=0.+tmp237;
REAL8 tmp198=tmp196*tmp196;
REAL8 tmp201=-(tmp145*tmp192*tmp56*tmp82);
REAL8 tmp202=tmp198+tmp201;
REAL8 tmp229=-(tmp196*tmp209*tmp222*tmp226);
REAL8 tmp230=p->data[0]+tmp229;
REAL8 tmp231=1.*tmp230;
REAL8 tmp232=0.+tmp231;
REAL8 tmp257=sqrt(tmp56);
REAL8 tmp250=1/tmp202;
REAL8 tmp227=-(tmp196*tmp222*tmp226);
REAL8 tmp228=1.+tmp227;
REAL8 tmp261=(x->data[0]*x->data[0]*x->data[0]);
REAL8 tmp267=eta*eta;
REAL8 tmp271=pow(x->data[0],6.);
REAL8 tmp272=(1.0/(tmp149*tmp149));
REAL8 tmp273=tmp217*tmp217;
REAL8 tmp274=(tmp232*tmp232*tmp232);
REAL8 tmp239=1.*tmp238;
REAL8 tmp240=0.+tmp239;
REAL8 tmp241=0.+p->data[2];
REAL8 tmp242=tmp240*tmp241;
REAL8 tmp243=0.+tmp242;
REAL8 tmp244=tmp243*tmp243;
REAL8 tmp245=1.*tmp145*tmp152*tmp244;
REAL8 tmp246=0.+p->data[1];
REAL8 tmp247=tmp238*tmp246;
REAL8 tmp248=0.+tmp247;
REAL8 tmp249=tmp248*tmp248;
REAL8 tmp251=1.*tmp145*tmp149*tmp249*tmp250;
REAL8 tmp252=tmp232*tmp232;
REAL8 tmp253=1.*tmp145*tmp152*tmp192*tmp217*tmp252*tmp82;
REAL8 tmp276=-16.*eta;
REAL8 tmp277=21.*tmp267;
REAL8 tmp278=tmp276+tmp277;
REAL8 tmp282=0.+tmp245+tmp251+tmp253;
REAL8 tmp296=-6.*eta;
REAL8 tmp297=39.*tmp267;
REAL8 tmp298=tmp296+tmp297;
REAL8 tmp310=sqrt(tmp149);
REAL8 tmp262=-66.*sigmaKerr->data[2]*tmp152*tmp192*tmp217*tmp228*tmp232*tmp261*tmp82;
REAL8 tmp263=-52.*sigmaStar->data[2]*tmp152*tmp192*tmp217*tmp228*tmp232*tmp261*tmp82;
REAL8 tmp264=tmp262+tmp263;
REAL8 tmp265=0.08333333333333333*eta*tmp264*tmp60;
REAL8 tmp266=103.*eta;
REAL8 tmp268=-60.*tmp267;
REAL8 tmp269=tmp266+tmp268;
REAL8 tmp270=-4.*tmp152*tmp192*tmp217*tmp228*tmp232*tmp261*tmp269*tmp82;
REAL8 tmp275=1440.*tmp218*tmp220*tmp228*tmp267*tmp271*tmp272*tmp273*tmp274;
REAL8 tmp279=-12.*tmp218*tmp220*tmp228*tmp271*tmp272*tmp273*tmp274*tmp278;
REAL8 tmp280=3.*eta;
REAL8 tmp281=23.+tmp280;
REAL8 tmp283=-4.*eta*tmp152*tmp192*tmp217*tmp219*tmp228*tmp232*tmp281*tmp282*tmp82;
REAL8 tmp284=-47.*eta;
REAL8 tmp285=54.*tmp267;
REAL8 tmp286=tmp278*tmp282*x->data[0];
REAL8 tmp287=tmp284+tmp285+tmp286;
REAL8 tmp288=-12.*tmp152*tmp192*tmp217*tmp228*tmp232*tmp261*tmp287*tmp82;
REAL8 tmp289=tmp270+tmp275+tmp279+tmp283+tmp288;
REAL8 tmp290=0.013888888888888888*sigmaStar->data[2]*tmp289*tmp57;
REAL8 tmp291=-109.*eta;
REAL8 tmp292=51.*tmp267;
REAL8 tmp293=tmp291+tmp292;
REAL8 tmp294=8.*tmp152*tmp192*tmp217*tmp228*tmp232*tmp261*tmp293*tmp82;
REAL8 tmp295=3240.*tmp218*tmp220*tmp228*tmp267*tmp271*tmp272*tmp273*tmp274;
REAL8 tmp299=-12.*tmp218*tmp220*tmp228*tmp271*tmp272*tmp273*tmp274*tmp298;
REAL8 tmp300=-180.*eta*tmp152*tmp192*tmp217*tmp219*tmp228*tmp232*tmp282*tmp82;
REAL8 tmp301=16.*eta;
REAL8 tmp302=147.*tmp267;
REAL8 tmp303=tmp282*tmp298*x->data[0];
REAL8 tmp304=tmp301+tmp302+tmp303;
REAL8 tmp305=-12.*tmp152*tmp192*tmp217*tmp228*tmp232*tmp261*tmp304*tmp82;
REAL8 tmp306=tmp294+tmp295+tmp299+tmp300+tmp305;
REAL8 tmp307=0.006944444444444444*sigmaKerr->data[2]*tmp306*tmp57;
REAL8 tmp308=tmp265+tmp290+tmp307;
REAL8 tmp333=(tmp232*tmp232*tmp232*tmp232);
REAL8 tmp336=tmp282*tmp282;
REAL8 tmp311=tmp145*tmp192*tmp82;
REAL8 tmp312=sqrt(tmp311);
REAL8 tmp313=-tmp312;
REAL8 tmp314=tmp145*tmp149*tmp192*tmp250*tmp82;
REAL8 tmp315=sqrt(tmp314);
REAL8 tmp316=1.*tmp310*tmp315;
REAL8 tmp317=tmp313+tmp316;
REAL8 tmp318=1.+tmp245+tmp251+tmp253;
REAL8 tmp321=1.*coeffs->d1v2*eta*sigmaKerr->data[2]*tmp158;
REAL8 tmp322=-8.*sigmaKerr->data[2];
REAL8 tmp323=14.*sigmaStar->data[2];
REAL8 tmp324=-36.*sigmaKerr->data[2]*tmp152*tmp192*tmp217*tmp252*tmp261*tmp82;
REAL8 tmp325=-30.*sigmaStar->data[2]*tmp152*tmp192*tmp217*tmp252*tmp261*tmp82;
REAL8 tmp326=3.*sigmaKerr->data[2]*tmp282*x->data[0];
REAL8 tmp327=4.*sigmaStar->data[2]*tmp282*x->data[0];
REAL8 tmp328=tmp322+tmp323+tmp324+tmp325+tmp326+tmp327;
REAL8 tmp329=0.08333333333333333*eta*tmp328*tmp60;
REAL8 tmp330=27.*eta;
REAL8 tmp331=-353.+tmp330;
REAL8 tmp332=-2.*eta*tmp331;
REAL8 tmp334=360.*tmp218*tmp220*tmp267*tmp271*tmp272*tmp273*tmp333;
REAL8 tmp335=-2.*tmp269*tmp282*x->data[0];
REAL8 tmp337=-(eta*tmp145*tmp281*tmp336);
REAL8 tmp338=-6.*tmp152*tmp192*tmp217*tmp252*tmp261*tmp287*tmp82;
REAL8 tmp339=tmp332+tmp334+tmp335+tmp337+tmp338;
REAL8 tmp340=0.013888888888888888*sigmaStar->data[2]*tmp339*tmp57;
REAL8 tmp341=8.+tmp280;
REAL8 tmp342=-112.*eta*tmp341;
REAL8 tmp343=810.*tmp218*tmp220*tmp267*tmp271*tmp272*tmp273*tmp333;
REAL8 tmp344=4.*tmp282*tmp293*x->data[0];
REAL8 tmp345=-45.*eta*tmp145*tmp336;
REAL8 tmp346=-6.*tmp152*tmp192*tmp217*tmp252*tmp261*tmp304*tmp82;
REAL8 tmp347=tmp342+tmp343+tmp344+tmp345+tmp346;
REAL8 tmp348=0.006944444444444444*sigmaKerr->data[2]*tmp347*tmp57;
REAL8 tmp349=0.+sigmaStar->data[2]+tmp321+tmp329+tmp340+tmp348;
REAL8 tmp83=1/tmp82;
REAL8 tmp193=1/tmp192;
REAL8 tmp356=tmp145*tmp192*tmp217*tmp82;
REAL8 tmp357=sqrt(tmp356);
REAL8 tmp358=sqrt(tmp318);
REAL8 tmp351=1./sqrt(tmp149);
REAL8 tmp361=-2.*tmp145*tmp192*tmp82;
REAL8 tmp362=1/tmp170;
REAL8 tmp363=2.*coeffs->k2;
REAL8 tmp364=3.*coeffs->k3;
REAL8 tmp365=4.*coeffs->k4;
REAL8 tmp366=5.*tmp168*tmp60;
REAL8 tmp367=tmp365+tmp366;
REAL8 tmp368=1.*tmp367*tmp60;
REAL8 tmp369=tmp364+tmp368;
REAL8 tmp370=1.*tmp369*tmp60;
REAL8 tmp371=tmp363+tmp370;
REAL8 tmp372=1.*tmp371*tmp60;
REAL8 tmp373=coeffs->k1+tmp372;
REAL8 tmp374=-(eta*tmp362*tmp373*tmp82);
REAL8 tmp375=1.*tmp59;
REAL8 tmp376=1.*tmp56*tmp60;
REAL8 tmp377=tmp375+tmp376;
REAL8 tmp378=-2.*tmp192*tmp377;
REAL8 tmp379=2.*tmp192*tmp82*x->data[0];
REAL8 tmp380=tmp374+tmp378+tmp379;
REAL8 tmp381=tmp357*tmp380;
REAL8 tmp382=tmp361+tmp381;
REAL8 tmp319=1./sqrt(tmp318);
REAL8 tmp388=1.*tmp152*x->data[0];
REAL8 tmp389=-4.*tmp192*tmp261*tmp82;
REAL8 tmp390=tmp196*tmp380;
REAL8 tmp391=tmp389+tmp390;
REAL8 tmp392=0.5*tmp193*tmp196*tmp250*tmp391*tmp57*tmp83;
REAL8 tmp393=tmp388+tmp392;
REAL8 tmp385=tmp240*tmp349;
REAL8 tmp386=0.+tmp385;
REAL8 tmp258=0.;
REAL8 tmp259=2.*tmp257*x->data[0];
REAL8 tmp260=tmp258+tmp259;
REAL8 tmp383=1.+tmp358;
REAL8 tmp359=1.+tmp245+tmp251+tmp253+tmp358;
REAL8 tmp233=2.*tmp145*tmp152*tmp192*tmp217*tmp228*tmp232*tmp82;
REAL8 tmp403=1./sqrt(tmp311);
REAL8 tmp404=1./sqrt(tmp314);
REAL8 tmp405=(1.0/(tmp202*tmp202));
REAL8 tmp406=2.*tmp257;
REAL8 tmp407=0.;
REAL8 tmp408=0.+tmp406+tmp407;
REAL8 tmp409=tmp202*tmp408;
REAL8 tmp410=-4.*tmp196*x->data[0];
REAL8 tmp411=1.*tmp380*tmp56;
REAL8 tmp412=tmp410+tmp411;
REAL8 tmp413=tmp260*tmp412;
REAL8 tmp414=tmp409+tmp413;
REAL8 tmp416=tmp149*tmp149;
REAL8 tmp428=pow(tmp149,-2.5);
REAL8 tmp352=(1.0/sqrt(tmp318*tmp318*tmp318));
REAL8 tmp415=1/tmp383;
REAL8 tmp431=1.*tmp192*tmp219*tmp249*tmp250*tmp386*tmp416*tmp82;
REAL8 tmp432=-(tmp145*tmp192*tmp217*tmp252*tmp386*tmp82);
REAL8 tmp433=tmp149*tmp359*tmp386;
REAL8 tmp434=0.+tmp432+tmp433;
REAL8 tmp435=1.*tmp145*tmp192*tmp434*tmp82;
REAL8 tmp436=0.+tmp431+tmp435;
REAL8 tmp421=1.*tmp145*tmp152*tmp192*tmp217*tmp228*tmp232*tmp319*tmp82;
REAL8 tmp422=tmp233+tmp421;
REAL8 tmp394=2.*tmp358;
REAL8 tmp395=1.+tmp394;
REAL8 tmp204=tmp152*tmp193*tmp202*tmp57*tmp83;
REAL8 tmp205=1./sqrt(tmp204);
REAL8 tmp235=(tmp209*tmp209*tmp209*tmp209);
REAL8 tmp236=2.*eta*tmp207*tmp235*tmp57;
REAL8 tmp254=1.+tmp236+tmp245+tmp251+tmp253;
REAL8 tmp353=e3z*tmp349;
REAL8 tmp354=0.+tmp353;
REAL8 tmp402=(1.0/sqrt(tmp149*tmp149*tmp149));
REAL8 tmp360=1/tmp359;
REAL8 tmp440=-0.5*tmp222*tmp248*tmp310*tmp315*tmp382*tmp383*tmp386*x->data[0];
REAL8 tmp441=1.*tmp248*tmp310*tmp315*tmp386*tmp393*tmp395*x->data[0];
REAL8 tmp442=0.+tmp441;
REAL8 tmp443=tmp312*tmp442;
REAL8 tmp444=tmp440+tmp443;
REAL8 tmp445=tmp357*tmp444;
REAL8 tmp446=0.+tmp445;
REAL8 dHdp0=(1.*eta*(1.*e3z*tmp250*tmp260*tmp308-tmp158*tmp308*tmp349-tmp192*tmp217*tmp228*tmp232*tmp248*tmp250*tmp261*tmp317*tmp351*tmp352*tmp354*tmp82-0.5*tmp145*tmp192*tmp217*tmp228*tmp232*tmp352*tmp357*tmp403*tmp404*tmp405*tmp414*tmp415*tmp428*tmp436*tmp82+0.5*tmp319*tmp357*tmp402*tmp403*tmp404*tmp405*tmp414*tmp415*(1.*tmp192*tmp219*tmp240*tmp249*tmp250*tmp308*tmp416*tmp82+1.*tmp145*tmp192*tmp82*(tmp149*tmp240*tmp308*tmp359+tmp149*tmp386*tmp422-tmp145*tmp192*tmp217*tmp240*tmp252*tmp308*tmp82-2.*tmp145*tmp192*tmp217*tmp228*tmp232*tmp386*tmp82))+1.*e3z*tmp248*tmp250*tmp308*tmp310*tmp317*tmp319*x->data[0]+1.*tmp152*tmp193*tmp315*tmp357*tmp360*tmp57*tmp83*(-0.5*tmp192*tmp217*tmp222*tmp228*tmp232*tmp248*tmp261*tmp315*tmp319*tmp351*tmp382*tmp386*tmp82-0.5*tmp222*tmp240*tmp248*tmp308*tmp310*tmp315*tmp382*tmp383*x->data[0]+tmp312*(2.*tmp192*tmp217*tmp228*tmp232*tmp248*tmp261*tmp315*tmp319*tmp351*tmp386*tmp393*tmp82+1.*tmp240*tmp248*tmp308*tmp310*tmp315*tmp393*tmp395*x->data[0]))-tmp152*tmp193*tmp315*tmp422*tmp446*tmp57*tmp83*(1.0/(tmp359*tmp359))-(0.5*tmp145*tmp192*tmp217*tmp228*tmp232*tmp357*tmp403*tmp404*tmp405*tmp414*tmp428*tmp436*tmp82*(1.0/(tmp383*tmp383)))/tmp318+(0.5*tmp205*(tmp233+8.*eta*tmp207*tmp57*(tmp209*tmp209*tmp209)))/sqrt(tmp254)))/sqrt(1.+2.*eta*(-1.+1.*tmp250*tmp260*tmp354+0.5*tmp319*tmp357*tmp402*tmp403*tmp404*tmp405*tmp414*tmp415*tmp436+1.*tmp152*tmp193*tmp315*tmp360*tmp446*tmp57*tmp83+1.*tmp248*tmp250*tmp260*x->data[0]+1.*tmp248*tmp250*tmp310*tmp317*tmp319*tmp354*x->data[0]+1.*coeffs->dheffSSv2*eta*tmp156*(s1Vec->data[2]*s1Vec->data[2]+s2Vec->data[2]*s2Vec->data[2])-0.5*tmp158*(0.+tmp349*tmp349)+tmp205*sqrt(tmp254)));
