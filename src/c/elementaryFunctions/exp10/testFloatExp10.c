/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2006-2008 - INRIA - Arnaud TORSET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#include "testExp10.h"

#define SOURCE {0.3796988371759653091431f,0.3062356826849281787872f,0.3880051793530583381653f,\
0.1047293278388679027557f,0.7603831812739372253418f,0.0340930395759642124176f,\
0.1423966242000460624695f,0.5554559468291699886322f,0.8031897451728582382202f,\
0.5183992316015064716339f,0.1518561029806733131409f,0.5884730662219226360321f,\
0.2545093484222888946533f,0.9992679939605295658112f,0.6398976957425475120544f,\
0.5506716123782098293304f,0.4607007671147584915161f,0.5933007937856018543243f,\
0.6538193570449948310852f,0.4168340521864593029022f,0.9910155385732650756836f,\
0.3720780410803854465485f,0.7061824081465601921082f,0.5780865414999425411224f,\
0.602319641038775444031f,0.5715096746571362018585f,0.0549629041925072669983f,\
0.1205854485742747784f,0.0143620483577251434326f,0.0257951230742037296295f,\
0.8411248764023184776306f,0.4381882525049149990082f,0.4643401596695184707642f,\
0.4197426405735313892365f,0.8023654492571949958801f,0.5228588166646659374237f,\
0.5095121040940284729004f,0.4531980180181562900543f,0.7817818326875567436218f,\
0.776557037141174077988f,0.0466059204190969467163f,0.5113326688297092914581f,\
0.7502101892605423927307f,0.6883628661744296550751f,0.0167756117880344390869f,\
0.9345410899259150028229f,0.5609863763675093650818f,0.2205847105942666530609f,\
0.7648540753871202468872f,0.4816976976580917835236f,0.1558785634115338325500f,\
0.2476022052578628063202f,0.5216529071331024169922f,0.0805230387486517429352f,\
0.4409417239949107170105f,0.8911933614872395992279f,0.9780590813606977462769f,\
0.4588093762286007404327f,0.5510440031066536903381f,0.0960960905067622661591f,\
0.4196785055100917816162f,0.7502556503750383853912f,0.7218149593099951744080f,\
0.2895541018806397914886f,0.3907764498144388198853f,0.6686618146486580371857f,\
0.4877656819298863410950f,0.4685971769504249095917f,0.3562648519873619079590f,\
0.3442325466312468051910f,0.4253307832404971122742f,0.5588058172725141048431f,\
0.3304864969104528427124f,0.4157403339631855487823f,0.1595822656527161598206f,\
0.3883102680556476116180f,0.9415460713207721710205f,0.4722979352809488773346f,\
0.8533652639016509056091f,0.1207739165984094142914f,0.8999380934983491897583f,\
0.4384902161546051502228f,0.8976056622341275215149f,0.4911110657267272472382f,\
0.3402217179536819458008f,0.9966153600253164768219f,0.0215395865961909294128f,\
0.6876890822313725948334f,0.0044924151152372360229f,0.6397854541428387165070f,\
0.5416147718206048011780f,0.2247649203054606914520f,0.7364005260169506072998f,\
0.4496364505030214786530f,0.9678138038143515586853f,0.6489060199819505214691f,\
0.2544666919857263565063f,0.1923975017853081226349f,0.6861492367461323738098f,\
0.4231455805711448192596f,0.6734441593289375305176f,0.8270696722902357578278f,\
0.9360805852338671684265f,0.8326222090981900691986f,0.7424779590219259262085f,\
0.0194640238769352436066f,0.8016031915321946144104f,0.2554539437405765056610f,\
0.2688109613955020904541f,0.7558490769006311893463f,0.4347589677199721336365f,\
0.6425966522656381130219f,0.6957868058234453201294f,0.6499576461501419544220f,\
0.2303190128877758979797f,0.5504368054680526256561f,0.3038997054100036621094f,\
0.0371030517853796482086f,0.1703881053254008293152f,0.5698686256073415279388f,\
0.0036411266773939132690f,0.4491547052748501300812f,0.0576810697093605995178f,\
0.4956056098453700542450f,0.1888933442533016204834f,0.5641230703331530094147f,\
0.8562210192903876304626f,0.0794764286838471889496f,0.6196198705583810806274f,\
0.2241039988584816455841f,0.8582094730809330940247f,0.7114551994018256664276f,\
0.8026027604937553405762f,0.6153324418701231479645f,0.8958183480426669120789f,\
0.8721761344932019710541f,0.8389767911285161972046f,0.2040955354459583759308f,\
0.3166538262739777565002f,0.7006825651042163372040f,0.2073105163872241973877f,\
0.5222550616599619388580f,0.9416420971974730491638f,0.52116033947095274925f,\
0.4509841967374086380005f,0.3961292845197021961212f,0.7240869747474789619446f,\
0.6724055963568389415741f,0.2386146038770675659180f,0.7124841609038412570953f,\
0.3286493895575404167175f,0.4837769134901463985443f,0.7662767004221677780151f,\
0.3153839264996349811554f,0.3489987561479210853577f,0.7413818310014903545380f,\
0.9702721945941448211670f,0.1276510567404329776764f,0.3828862151131033897400f,\
0.4882477498613297939301f,0.5191949699074029922485f,0.0906856027431786060333f,\
0.6833897503092885017395f,0.5022272053174674510956f,0.0540433898568153381348f,\
0.0163939022459089756012f,0.6050811810418963432312f,0.2953875153325498104095f,\
0.6451294776052236557007f,0.9449766655452549457550f,0.5638650292530655860901f,\
0.9786348040215671062469f,0.9345349706709384918213f,0.1023264364339411258698f,\
0.7292392617091536521912f,0.8353224000893533229828f,0.9328642506152391433716f,\
0.0507844281382858753204f,0.1677279071882367134094f,0.9475936102680861949921f,\
0.9390441477298736572266f,0.1270067342557013034821f,0.6562355486676096916199f,\
0.7192088677547872066498f,0.5519206207245588302612f,0.7606899146921932697296f,\
0.8840736905112862586975f,0.6386072556488215923309f,0.2424023114144802093506f,\
0.7679059565998613834381f,0.2624090006574988365173f,0.1259524053893983364105f,\
0.4549009744077920913696f,0.2127966103143990039825f,0.0598834278061985969543f,\
0.8079127701930701732635f,0.7068187817931175231934f,0.9313771002925932407379f,\
0.0831561936065554618835f,0.0639262734912335872650f}

#define RESULT {2.3971700177038997026102f,2.0241173275316319823958f,2.4434596929789558217294f,\
1.2727096230040590985055f,5.7594787634974791146192f,1.0816656533775219628524f,\
1.3880228773309635226241f,3.5929894899598955326780f,6.3560857138200033134012f,\
3.2991285007258008832309f,1.4185874159639277891642f,3.8767970491010381728358f,\
1.7968397576993500042164f,9.9831591347336789965539f,4.3641301682226361080552f,\
3.5536251298653307451048f,2.8886888633814562510338f,3.9201329280029257873252f,\
4.506292282304419138939f,2.6111634148093250118450f,9.7952503109731186015097f,\
2.3554725153952857930051f,5.0837291957799548569596f,3.7851800417010572630261f,\
4.0023921772430028909184f,3.7282899025795783742865f,1.1349138714412994044523f,\
1.3200350064956956064322f,1.033622723333016191205f,1.0611948240957502775927f,\
6.9362522133054556050524f,2.7427628125876060138921f,2.9129978203666571090480f,\
2.6287097779191044288893f,6.3440332316119087963102f,3.3331803790647938079417f,\
3.232303288716906752853f,2.8392132821292248578970f,6.0503685885843978553567f,\
5.97801550527315583849f,1.1132838793654469267125f,3.245881561190152808649f,\
5.6261355226100322468596f,4.879360051235307693673f,1.0393830059871540516525f,\
8.600844382521195541358f,3.6390362044693791432337f,1.6618227902609816748480f,\
5.8190766171103653903174f,3.0317800975513509165182f,1.4317874896288145247780f,\
1.7684883582783652578030f,3.3239379437878064926792f,1.2037132434952326764943f,\
2.7602074516612016275019f,7.7838303437469935630588f,9.5073412259646765676280f,\
2.876135722709581621359f,3.5566735327883938211357f,1.2476595365735951848052f,\
2.6283216080771176770270f,5.626724486525223944966f,5.2700527142503661437445f,\
1.947843685866482488223f,2.4591014722412456450229f,4.6629613384726322777851f,\
3.0744375934314547293980f,2.941691847776138235560f,2.2712495380631962937912f,\
2.2091873443061853521385f,2.6627523904580243652163f,3.620810677149941980701f,\
2.1403583776871992760960f,2.60459578833533411668f,1.44405011565138674534f,\
2.4451768086326421958177f,8.7406971172900771449576f,2.9668660249388048022468f,\
7.1345282822869320327186f,1.3206079780376647203610f,7.9421501528532889579992f,\
2.7446705104699793409395f,7.899610206034289205945f,3.0982115292188217026137f,\
2.188878814912672332582f,9.9223686842029490406958f,1.050847236808647444661f,\
4.8717958623764170411619f,1.0103978539346472054206f,4.3630024226971446665857f,\
3.4802846963616036468636f,1.6778955425132806578148f,5.4500504945081766905446f,\
2.8160246398239912046790f,9.2856819400663770380788f,4.4555982016116564281560f,\
1.7966632806306144232167f,1.5573904303972738727424f,4.8545528865355054293218f,\
2.6493880955344351058045f,4.7145924820058668913703f,6.715365764647851953839f,\
8.6313869205483300106607f,6.8017741785747647398352f,5.5268535777229557126589f,\
1.0458370517364794505255f,6.3329081834648581761371f,1.8007521573290650174215f,\
1.8569959706339840277423f,5.6996616704912836937069f,2.7211906353565828986518f,\
4.39133583975054442305f,4.9634860523035060353436f,4.4664003219774368602657f,\
1.6994915629457518768675f,3.5517043359266669000363f,2.0132592604656482926373f,\
1.089188511318553986840f,1.4804307775633922528158f,3.7142285642082217833604f,\
1.0084192481976341770888f,2.8129026699324310989425f,1.142039354028792752516f,\
3.1304416262076188992580f,1.5448749964710146720392f,3.6654143041103313116480f,\
7.181596810407055997416f,1.200815897009761545888f,4.1650466551411478022260f,\
1.6753440162955879344509f,7.21455374553604489307f,5.1458272136838258958846f,\
6.3475007446385660614396f,4.1241309049764449667919f,7.8671666160643907161898f,\
7.450340721306332625318f,6.9020291813359317956156f,1.5999099356849897368704f,\
2.0732602743658210542321f,5.0197555099972408498843f,1.6117976431404783532741f,\
3.3285498202301311287954f,8.7426299668587681424015f,3.3201701404059416056214f,\
2.824777184045289768477f,2.4895983330428896884712f,5.297695284941288385028f,\
4.7033315715610184426509f,1.7322660897889763376156f,5.1580335293393115847493f,\
2.1313235787699511547544f,3.0463297621649392254994f,5.8381695091926415486228f,\
2.0672068075526839336931f,2.2335658257207593457849f,5.5129217858217156589262f,\
9.3383940240121710019139f,1.3416865210022335119788f,2.414828068089148516151f,\
3.0778521213560718905455f,3.3051788871815572790069f,1.2322124790790967008292f,\
4.8238050773970124751600f,3.1785365175695079464901f,1.1325135056912927211670f,\
1.038469874168215900667f,4.0279231974946911876145f,1.97418348876764548905f,\
4.4170211379151878006155f,8.8100153590470213771368f,3.663237102755284801958f,\
9.5199529943728755654320f,8.6007231965720354338600f,1.2656873409568392130353f,\
5.3609192017188229684166f,6.8441954007674699056452f,8.5676999890922083125133f,\
1.1240468894427289026083f,1.471390362736320067683f,8.8632624680127776173322f,\
8.690487669968261386089f,1.3396974608773437598330f,4.5314328497492990521778f,\
5.2385231533328031616747f,3.5638598811998751791918f,5.7635480038278910086547f,\
7.6572652334911666116568f,4.351182064426246220989f,1.7474401555184173595592f,\
5.8601125417902917291713f,1.8298226565740485227707f,1.336449046213224356450f,\
2.8503682671020214023372f,1.6322873327021125700043f,1.1478454784492588824918f,\
6.4255864384701686375934f,5.0911838672535516536755f,8.538411872415464287656f,\
1.211033602346728965671f,1.1585806569998515769271f}

#define CSOURCER {0.0521394181996583938599f,0.4229906541295349597931f,0.9028727160766720771790f,\
0.270216043572872877121f,0.4369520992040634155273f,0.0152578153647482395172f,\
0.6548111913725733757019f,0.0449309810064733028412f,0.2133925389498472213745f,\
0.5342523609288036823273f,0.7069207737222313880920f,0.2409008811227977275848f,\
0.2901745550334453582764f,0.7550916881300508975983f,0.2289740880951285362244f,\
0.4858699417673051357269f,0.6168978903442621231079f,0.8581895199604332447052f,\
0.9484143527224659919739f,0.2478762450627982616425f,0.3616605177521705627441f,\
0.4686846160329878330231f,0.0340223712846636772156f,0.5221414058469235897064f,\
0.3054678197950124740601f,0.2017288585193455219269f,0.4932554000988602638245f,\
0.3831945951096713542938f,0.9221886433660984039307f,0.8073847130872309207916f,\
0.3020078903064131736755f,0.2459809384308755397797f,0.1128082294017076492310f,\
0.5088820648379623889923f,0.9855441050603985786438f,0.1797042894177138805389f,\
0.0627280175685882568359f,0.6279844292439520359039f,0.8693526117131114006042f,\
0.1181543781422078609467f,0.1908623259514570236206f,0.0912145380862057209015f,\
0.7186726490035653114319f,0.310268334578722715378f,0.6592819057404994964600f,\
0.9106893003918230533600f,0.9854423692449927330017f,0.8546765870414674282074f,\
0.4121543709188699722290f,0.2333141383714973926544f,0.3814189555123448371887f,\
0.6619831356219947338104f,0.212731502950191497803f,0.0520866983570158481598f,\
0.9962206138297915458679f,0.6885302006267011165619f,0.6471334304660558700562f,\
0.1732599367387592792511f,0.6790404403582215309143f,0.7853972460143268108368f,\
0.5636796839535236358643f,0.5331145809032022953033f,0.9027821635827422142029f,\
0.0063843778334558010101f,0.9165171254426240921021f,0.4580909651704132556915f,\
0.8293677615001797676086f,0.7187301176600158214569f,0.4822947531938552856445f,\
0.9620302417315542697906f,0.7949669538065791130066f,0.3603135510347783565521f,\
0.4186353813856840133667f,0.6742749665863811969757f,0.9338985690847039222717f,\
0.18709085090085864067f,0.1331541948020458221436f,0.4923790604807436466217f,\
0.1599537869915366172791f,0.8545161760412156581879f,0.4317741785198450088501f,\
0.5531771448440849781036f,0.2238912554457783699036f,0.1766969445161521434784f,\
0.4150884225964546203613f,0.6159632527269423007965f,0.0658540828153491020203f,\
0.9070334821008145809174f,0.0915193017572164535522f,0.4515289147384464740753f,\
0.1814587051048874855042f,0.8840930457226932048798f,0.1760245300829410552979f,\
0.3308106199838221073151f,0.2203056281432509422302f,0.3864682218991219997406f,\
0.0431000906974077224731f,0.2068966520018875598907f,0.5356620447710156440735f,\
0.0403697001747786998749f,0.3028300404548645019531f,0.6841432997025549411774f,\
0.9040663270279765129089f,0.1237034215591847896576f,0.9687331896275281906128f,\
0.3681504433043301105499f,0.1336043933406472206116f,0.6103821019642055034637f,\
0.6861566565930843353271f,0.6903465152718126773834f,0.779607950709760189056f,\
0.7986211306415498256683f,0.9899662975221872329712f,0.8009328362531960010529f,\
0.6865246118977665901184f,0.8669688436202704906464f,0.0602840110659599304199f,\
0.6239373260177671909332f,0.5747098876163363456726f,0.2018211721442639827728f,\
0.9450219180434942245483f,0.6681275893934071063995f,0.3908910537138581275940f,\
0.8401706661097705364227f,0.7179634161293506622314f,0.6875333772040903568268f,\
0.6410528933629393577576f,0.8713398925028741359711f,0.5411411095410585403442f,\
0.7853284222073853015900f,0.4244953142479062080383f,0.1414492088370025157928f,\
0.1002616137266159057617f,0.0548216500319540500641f,0.3878128407523036003113f,\
0.1043689115904271602631f,0.3819272350519895553589f,0.3513077651150524616241f,\
0.3175459811463952064514f,0.1629057596437633037567f,0.2614045254886150360107f,\
0.2885272116400301456451f,0.5902544697746634483337f,0.3439738727174699306488f,\
0.8696897123008966445923f,0.0534855094738304615021f,0.1987623842433094978333f,\
0.6515000048093497753143f,0.2086210027337074279785f,0.1333819651044905185699f,\
0.5733251376077532768250f,0.9408131926320493221283f,0.9827877636998891830444f,\
0.5483977575786411762238f,0.9164683455601334571838f,0.6582687790505588054657f,\
0.1169865764677524566650f,0.6840933994390070438385f,0.2702485686168074607849f,\
0.2898568115197122097015f,0.9279741663485765457153f,0.3171655726619064807892f,\
0.0346859293058514595032f,0.8625448155216872692f,0.4192672073841094970703f,\
0.9283133395947515964508f,0.1561186043545603752136f,0.3421049430035054683685f,\
0.6677390020340681076050f,0.8959637288935482501984f,0.7042291918769478797913f,\
0.2711754958145320415497f,0.7707630358636379241943f,0.6646066964603960514069f,\
0.0564929535612463951111f,0.4913068241439759731293f,0.3226534072309732437134f,\
0.4814894613809883594513f,0.4087979318574070930481f,0.2927415999583899974823f,\
0.8891521319746971130371f,0.7954202168621122837067f,0.8309869421645998954773f,\
0.8356794654391705989838f,0.4487133231014013290405f,0.9114312161691486835480f,\
0.5860714400187134742737f,0.186776056420058012009f,0.2693342454731464385986f,\
0.9950512335635721683502f,0.9318672632798552513123f,0.8146264008246362209320f,\
0.1896832454949617385864f,0.0199374002404510974884f,0.1238022493198513984680f,\
0.8879826921038329601288f,0.7732745558023452758789f,0.7526164152659475803375f,\
0.8376457272097468376160f,0.2204564376734197139740f}

#define CSOURCEI {0.3044399749487638473511f,0.3680851315148174762726f,0.7309098849073052406311f,\
0.2054549823515117168427f,0.0948474220931529998779f,0.7900205166079103946686f,\
0.3616730114445090293884f,0.5851024067960679531097f,0.0693163666874170303345f,\
0.3493489888496696949005f,0.1835746141150593757629f,0.3968948009423911571503f,\
0.0996801331639289855957f,0.8549251281656324863434f,0.8357324106618762016296f,\
0.9418399124406278133392f,0.0554450806230306625366f,0.6700697620399296283722f,\
0.4463311964645981788635f,0.1178311700932681560516f,0.0399966575205326080322f,\
0.8887174264527857303619f,0.1686335867270827293396f,0.9620060822926461696625f,\
0.781102331355214118958f,0.2049232018180191516876f,0.6681626336649060249329f,\
0.7458390104584395885468f,0.6444613933563232421875f,0.5694789239205420017242f,\
0.7798063186928629875183f,0.4667183174751698970795f,0.2390516381710767745972f,\
0.2273887698538601398468f,0.0535939196124672889709f,0.0797578911297023296356f,\
0.0830229185521602630615f,0.2299542189575731754303f,0.4078942527994513511658f,\
0.3135930425487458705902f,0.2988875750452280044556f,0.0152183887548744678497f,\
0.6087857903912663459778f,0.4139107796363532543182f,0.8067577406764030456543f,\
0.1505197458900511264801f,0.7943486524745821952820f,0.6584644555114209651947f,\
0.9843795206397771835327f,0.8309051920659840106964f,0.7626284742727875709534f,\
0.9873227919451892375946f,0.2627140469849109649658f,0.2271525249816477298737f,\
0.242022148333489894867f,0.5921032777987420558929f,0.6258154083043336868286f,\
0.2771522742696106433868f,0.8628354417160153388977f,0.8079399424605071544647f,\
0.4837554544210433959961f,0.0143989124335348606110f,0.0487624881789088249207f,\
0.1519355042837560176849f,0.8873454760760068893433f,0.0273414407856762409210f,\
0.5470371553674340248108f,0.8518478940241038799286f,0.5534047596156597137451f,\
0.1433433503843843936920f,0.8160062870010733604431f,0.7087611532770097255707f,\
0.6693260166794061660767f,0.9310019579716026782990f,0.9888748200610280036926f,\
0.6374907079152762889862f,0.9456876888871192932129f,0.1145771169103682041168f,\
0.6323727769777178764343f,0.7284730165265500545502f,0.8856631275266408920288f,\
0.4942793031223118305206f,0.0190941328182816505432f,0.1748895938508212566376f,\
0.7399766482412815093994f,0.4661670760251581668854f,0.1322575574740767478943f,\
0.9087754092179238796234f,0.11615646071732044220f,0.7354039144702255725861f,\
0.1216390328481793403625f,0.2898616599850356578827f,0.7108344733715057373047f,\
0.3166244276799261569977f,0.4294263450428843498230f,0.6909029199741780757904f,\
0.1338429730385541915894f,0.4151599411852657794952f,0.3047454515472054481506f,\
0.323238662909716367722f,0.2928581796586513519287f,0.2828734577633440494537f,\
0.9256087234243750572205f,0.1463391608558595180511f,0.3073406759649515151978f,\
0.6423539933748543262482f,0.8470350624993443489075f,0.2050857576541602611542f,\
0.4205227121710777282715f,0.7732202881015837192535f,0.9940918935462832450867f,\
0.2385355173610150814056f,0.87819238565862178802f,0.8542838920839130878448f,\
0.9186090314760804176331f,0.9039202476851642131805f,0.2430246956646442413330f,\
0.6553216264583170413971f,0.5383144235238432884216f,0.4596298984251916408539f,\
0.1132094729691743850708f,0.1722074192948639392853f,0.0771417664363980293274f,\
0.2509303349070250988007f,0.7141261845827102661133f,0.2991535165347158908844f,\
0.4254599986597895622253f,0.8421654864214360714f,0.3318156134337186813354f,\
0.1318110679276287555695f,0.6389746675267815589905f,0.1391938696615397930145f,\
0.0569984130561351776123f,0.9949800879694521427155f,0.7950511714443564414978f,\
0.3458094871602952480316f,0.8083905372768640518188f,0.7886787918396294116974f,\
0.9252098770812153816223f,0.0978971007280051708221f,0.1040655449032783508301f,\
0.7463223063386976718903f,0.2425431115552783012390f,0.6190718798898160457611f,\
0.5496137794107198715210f,0.1987607558257877826691f,0.3828040296211838722229f,\
0.2415534253232181072235f,0.5118484236299991607666f,0.4379267231561243534088f,\
0.8779173558577895164490f,0.1360241672955453395844f,0.9468084294348955154419f,\
0.2738420856185257434845f,0.5806620018556714057922f,0.5942221391014754772186f,\
0.8508083224296569824219f,0.378734225872904062271f,0.2592755584046244621277f,\
0.7080181255005300045013f,0.3032848816365003585815f,0.0120116178877651691437f,\
0.0807306626811623573303f,0.7887271861545741558075f,0.5701906941831111907959f,\
0.2198487878777086734772f,0.2014332404360175132751f,0.3704045540653169155121f,\
0.2366845849901437759399f,0.103130650240927934647f,0.1840926231816411018372f,\
0.1408759090118110179901f,0.8378689214587211608887f,0.2475062184967100620270f,\
0.4595135403797030448914f,0.6442520259879529476166f,0.9563237931579351425171f,\
0.9093016912229359149933f,0.552059986628592014313f,0.0986777986399829387665f,\
0.2551880665123462677002f,0.0510429129935801029205f,0.287540963850915431976f,\
0.1730656377039849758148f,0.4155373144894838333130f,0.8203372103162109851837f,\
0.7022680984809994697571f,0.0665632444433867931366f,0.4468086212873458862305f,\
0.5658646025694906711578f,0.8720351336523890495300f,0.7345057590864598751068f,\
0.3390222620218992233276f,0.9842283879406750202179f,0.3797692963853478431702f,\
0.6046022842638194561005f,0.5255502574145793914795f,0.4914151043631136417389f,\
0.6406045397743582725525f,0.6271067834459245204926f}

#define CRESULTR {0.8616789149319691309969f,1.7528026973616770423092f,-0.8951576871785223987743f,\
1.65839939772781952421f,2.670002318435218402470f,-0.2545370391954314692740f,\
3.0388538062879217882539f,0.2458549627872582132859f,1.613753544958956620547f,\
2.373140931257777808128f,4.6441801233654604885714f,1.0634345748771927286924f,\
1.8994737292284431529055f,-2.2038440203063891509316f,-0.5865941523645769040129f,\
-1.7230123422001577537799f,4.1053385752577806755426f,0.2012772387479372093733f,\
4.5889850773872540301568f,1.7048706561180972940406f,2.2898980543543361321213f,\
-1.3470616397449584056289f,1.000979918376255772827f,-1.998745505240199671348f,\
-0.4562266859878671976247f,1.4173389563254865652908f,0.1005345377926576272420f,\
-0.3529055360142766550879f,0.7252834368660135977436f,1.6469252220572825340383f,\
-0.4467771279955162211373f,0.8387209999987794706300f,1.1050928340202259558822f,\
2.7952258554924300781863f,9.5990623048041356923932f,1.4870960004060611581167f,\
1.1343408485170072275139f,3.664612325782657276108f,4.3703600670610898148993f,\
0.9850722877732481785884f,1.1986551091809227731488f,1.2329567566066641504108f,\
0.8800935914266996284994f,1.1832797973754654030643f,-1.2910350436339537161246f,\
7.6571266019263468649569f,-2.4697863053099986530015f,0.3907140975028082774401f,\
-1.655858606271026545187f,-0.5746050598208488624508f,-0.4432229757632685229751f,\
-2.9672355970693655713433f,1.3424314109887605095395f,0.9766924789772336579219f,\
8.4134496859782270661299f,1.0052614992336186272581f,0.5743785834192948192012f,\
1.1969550027714319639927f,-1.929705102086765711178f,-1.7419725915375741109870f,\
1.6154412531361730387403f,3.4109538321538344085582f,7.9439933441705683492273f,\
0.9533381558732610949747f,-3.7544424962625675412653f,2.8656935239804841586420f,\
2.0671417342103679537502f,-1.992605711686495695290f,0.8871291147322790671126f,\
8.6682584526683399417379f,-1.8914875129526329544660f,-0.1401839917101320720505f,\
0.0776428549278006530088f,-2.560598020200964608506f,-5.5730608716054170770349f,\
0.1580601872370170912774f,-0.7747638844786981504598f,2.9997587850927698305270f,\
0.1654170760372596638010f,-0.7609360918468449641594f,-1.2203777718239325889016f,\
1.4986628046871217634362f,1.6729053694884241654250f,1.381936351079181113377f,\
-0.3450348611667466425246f,1.9706824980594530583033f,1.1101876800122791877357f,\
-4.0234586128898426338196f,1.1906849924222373537930f,-0.3456983902450189716227f,\
1.459474884821820195313f,6.0143936939361175575414f,-0.0988538832443286719087f,\
1.597480633260187854461f,0.9129179205342567993142f,-0.0488550375477847867445f,\
1.0523032581716083022627f,0.9288642069528815214952f,2.6218635570145862878633f,\
0.8072263924219229558332f,1.5687383989731884526009f,3.842899231404802939949f,\
-4.2624261266025849081984f,1.2547786671163203564561f,7.0708952400269708959968f,\
0.2138025786160810681746f,-0.5039897261739162415140f,3.6311482225254705369366f,\
2.7511697563589119219785f,-1.0199337285771719052718f,-3.9613785741953506658319f,\
5.3644844232216355450760f,-4.261894060044243204288f,-2.440577323716713653567f,\
-2.5162841502447741426352f,-3.5973154891472156613474f,0.9736685483701841281601f,\
0.2600685777468328963025f,1.2216142738714919069309f,0.7803738463829824612006f,\
8.5132680918277277015704f,4.2958732896863782713126f,2.4210488328114880829389f,\
5.79755622526757630197f,-0.3837915438103189358365f,3.75964173341358565139f,\
2.4386368546342671592697f,-2.6776116153796971630641f,2.5102046010802867570533f,\
5.821177306248865868099f,0.2640059162189042352153f,1.31446884371506267364f,\
1.2488505950260830879017f,-0.7482976046844636019983f,-0.6275966789165404735584f,\
0.8893791469828959961319f,-0.6903683581860716733658f,-0.5450973252013330272447f,\
-1.1028092549899868313190f,1.4183297900536229185775f,1.773434980128008042755f,\
-0.2859252183654940604463f,3.3012839410905678860786f,0.3197431184385559066463f,\
2.2263782918939738487f,1.0146592610810074575056f,1.0051892636742449926857f,\
3.8066700246852320788093f,0.6179593115281443171938f,0.7249522760637888696422f,\
-1.6307732738859830323719f,8.3014440376437921287334f,-5.5006403965152692592255f,\
2.8552972304138433123910f,1.9111692714948702587208f,0.9158531650125845136046f,\
-0.4956155140563224259509f,3.1079184772588979157604f,1.5408715933614589577161f,\
-0.1158617194706384467828f,6.4886221326459514457952f,2.0749108619541400955200f,\
1.0644832532013759340828f,-1.769719547358157507588f,0.6696790607045245424800f,\
7.4150575771959807980238f,1.2812290258043323998294f,1.4461251309266722753222f,\
3.9789946052408695642555f,7.6489498856535602655526f,4.6130068144799594165306f,\
1.7697609579312818528507f,-2.069533011859056692572f,3.8895055335340873448047f,\
0.5587033140125831076617f,0.2704103697575463982616f,-1.2405136002402707973147f,\
-1.5134557095053997599621f,0.7566012248243810800474f,1.9117596963451992664318f,\
6.447932326957059423478f,6.2003146906774571078813f,5.344469754581457898723f,\
6.3131049040564706231748f,1.6189521464425622454542f,-2.550619599252561098268f,\
-0.1781945407584817342439f,1.5193399835582135359857f,0.9590574537903557850171f,\
2.6165522176992435099407f,-3.6188103766399173366608f,-0.7842216609502735691350f,\
1.0995885822264845899099f,-0.6708497380942372023682f,0.8529889923514888394607f,\
1.3729938244229744626068f,2.0937757207972880202362f,2.4059764571152468803916f,\
0.6578397026948303860650f,0.2101416292188336421010f}

#define CRESULTI {0.7272548245748866602156f,1.9854303798419310478351f,7.9457339679995211412233f,\
0.8488412125630352411676f,0.5925642663233093854203f,1.0039936024574043216262f,\
3.3414071705695578273776f,1.081403318108233868600f,0.2597757190370896807075f,\
2.4651157060741901716483f,2.0890001084665330566281f,1.3789900497554921088295f,\
0.4437915251064282751159f,5.2455794258294652365748f,1.5894481231762551676212f,\
2.5300661616939024156636f,0.5269825145414556155643f,7.2114139192406465639351f,\
7.6023759189514121814568f,0.474253708603649237752f,0.2114880398457448518190f,\
2.615809838094426353905f,0.40946194724304191270f,2.660538085383924222782f,\
1.96836124960102032411f,0.7232671662286862535041f,3.111923291962274351619f,\
2.3906358097335185242116f,8.3281383621146503060118f,6.2028635418634419096406f,\
1.9540840065283944237962f,1.5494625392422922693925f,0.678202414336372183534f,\
1.6137618479690827300033f,1.1906180579664376040228f,0.2762165158082148241903f,\
0.2195296884715036700442f,2.1446447456633843664520f,5.9741482912408789829328f,\
0.867597682821533044972f,0.9856997170507159067299f,0.0432225133986508733286f,\
5.157507023966152459593f,1.6654420749486735786604f,4.3768952511866894283799f,\
2.7654687058579336955688f,9.3496470896606780343063f,7.1454288620924977237792f,\
1.9826603369952136013410f,1.6118978629668390123442f,2.3655185893491501580854f,\
3.5043054723514432957643f,0.9281385166491339377970f,0.5631636514321668451899f,\
5.2429430139302253266465f,4.7766052326802679317552f,4.4001190809809767046090f,\
0.8877792684794596489439f,4.368513033448009785786f,5.8469722698220429890625f,\
3.2860624631665138473124f,0.1131306785331901154645f,0.8957170057781025374055f,\
0.3478275260751592101727f,7.3475483360254925102595f,0.1806513152317329173879f,\
6.4267295981620362610442f,4.8385133662587431757629f,2.9034462647978491744993f,\
2.9696777404396668131881f,5.9431363200854443462617f,2.288232180725223052775f,\
2.6208664370161969259243f,3.9693733894002809492463f,6.5342907486237020719955f,\
1.5303355006050158859665f,1.1162736854609731640409f,0.8102944693911555695820f,\
1.4357885386399356075771f,7.1128736564949752718690f,2.4113210957685655699834f,\
3.2448135685253003401840f,0.0735981604163226527104f,0.5886735706121437594618f,\
2.5776994154551164939448f,3.629648394334391792171f,0.3489446690644626425382f,\
6.9989048057282028381110f,0.3262782224609265258053f,2.8071160078618211386470f,\
0.4198114062820728631387f,4.7398318369933782889802f,1.4965081339145251959621f,\
1.4268961804460684739126f,1.3873315379595159146930f,2.4343374430326063517782f,\
0.3349767990169579268134f,1.3153540511429153703205f,2.2160059373349834110911f,\
0.7434370339011254769090f,1.253936082334201174149f,2.929523877257661279572f,\
6.7911802335851190193239f,0.4395719515095502516466f,6.0491461603781946365643f,\
2.324454495134102849363f,1.263389181071626898856f,1.8546860110985297076525f,\
3.9998192433092101261f,4.7944107664763828680066f,4.5331878790851858340716f,\
3.2834478309428574149820f,8.7932187934310537258398f,5.8331542843869588210737f,\
4.1564133542481211947006f,6.4227435117275550879867f,0.6098783468239901139896f,\
4.1986123528738117371972f,3.5516439676096513977654f,1.3871043178012487651074f,\
2.2708618645232787613963f,1.7986812579372670750644f,0.4346204841779990335482f,\
3.7800771946382365484851f,5.2094034804655127146589f,3.0955575196143279015359f,\
3.6332179827516117853747f,6.9371912371180162182327f,2.4051741186173338782339f,\
1.8230887730163647386661f,2.6444893659134645069742f,0.4363389413001144689908f,\
0.1648513733929060642858f,0.8527852017899220093966f,2.3603668450398678224644f,\
0.9089049761135811200674f,2.308482167770112614136f,2.1783058145209865941183f,\
1.760657933306752465086f,0.3252423522775149677955f,0.4332745364849133751228f,\
1.922093093505325978043f,2.0627370874500741138036f,2.184596685297794049774f,\
7.065327858525169979487f,0.4997624596555385045882f,1.2195103000378291202566f,\
2.3664724579469695875389f,1.4939021538810592915070f,1.1500903795661745476764f,\
3.3700776947908237524132f,2.6885676432811540514933f,7.8817788746511769915060f,\
2.0842223123540501994455f,8.0258609977666459656120f,4.459626216287859712395f,\
1.211699888667206126414f,3.6993867326108555992903f,1.0474037470444790276503f,\
1.9457553430070655409168f,5.4468957190088280739815f,0.0574020495019843535189f,\
0.200187099983916316770f,7.068768975957844702407f,2.5390022146337085651169f,\
4.1109611351982495719426f,0.6408861046921948689814f,1.6557914176531909333789f,\
2.4121782951381569581883f,1.8513041911556680219064f,2.0815970551782250197448f,\
0.5950929849744456268112f,5.5238367721873160576251f,2.4925246722707656843454f,\
0.9924655082402137340480f,3.0877905115051524909120f,1.6970418763867407552226f,\
2.6253251426459978112860f,2.4490847102298514137431f,0.4420113886405674930025f,\
4.2948005817238108505762f,0.7321010758042626465070f,4.1657752085548631626466f,\
2.6579704039050806585465f,2.2968127063505034968216f,7.7460044759776618406022f,\
3.851297516891551087070f,0.2347062006554227753252f,1.5927846479405329827017f,\
9.5341720234343370066199f,7.7442521101341821321284f,6.478396320140080710814f,\
1.0891470158039435744968f,0.8038176255057727370712f,1.0202487324661473344634f,\
7.6035293179001266494765f,5.5512724543076572558675f,5.1202912658114749788751f,\
6.849389505178533177343f,1.6479880468591965314573f}




void sexp10sTest(void) {
	float in[]=SOURCE;
	float res[]=RESULT;
	float out;
	int i;

	for (i=0;i<200;i++){
		out=sexp10s(in[i]);
		assert(( (fabs(out-res[i]))/(fabs(out)) )<1e-6);
	}
}

void cexp10sTest(void) {
	float inR[]=CSOURCER;
	float inI[]=CSOURCEI;
	float resR[]=CRESULTR;
	float resI[]=CRESULTI;
	floatComplex in,out;
	int i;

	for (i=0;i<200;i++){
		in=FloatComplex(inR[i],inI[i]);
		out=cexp10s(in);
		assert(( (fabs(creals(out)-resR[i]))/(fabs(creals(out))) )<8e-6);	
		assert(( (fabs(cimags(out)-resI[i]))/(fabs(cimags(out))) )<1e-6);			
	}
}

void sexp10aTest(void) {
	float in[]=SOURCE;
	float res[]=RESULT;
	float out[200];
	int i,j;
	j=1;
	sexp10a(in,200,out);
	for (i=0;i<200;i++){
		assert(( (fabs(out[i]-res[i]))/(fabs(out[i])) )<1e-6);
	}
}

void cexp10aTest(void) {
	float inR[]=CSOURCER;
	float inI[]=CSOURCEI;
	float resR[]=CRESULTR;
	float resI[]=CRESULTI;
	floatComplex *in,out[200];
	int i;

	in=FloatComplexMatrix(inR,inI,200);
	cexp10a(in,200,out);

	for (i=0;i<200;i++){
		assert(( (fabs(creals(out[i])-resR[i]))/(fabs(creals(out[i]))) )<8e-6);	
		assert(( (fabs(cimags(out[i])-resI[i]))/(fabs(cimags(out[i]))) )<1e-6);			
	}
}

int testExp10(void) {
  printf("\n>>>> Float 10-Base Exponential Tests\n");
  sexp10sTest();
  cexp10sTest();
  sexp10aTest();
  cexp10aTest();
  return 0;
}

int main(void) {
  assert(testExp10() == 0);
  return 0;
}
