/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2008-2008 - INRIA - Allan SIMON
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */


#include <assert.h>
#include <stdio.h>
#include "matrixDivision.h"


#define  LINES  2
#define  COLUMNS1 2
#define  COLUMNS2 2

#define ZLINES 2
#define ZCOLUMNS1 1
#define ZCOLUMNS2 2


static void sldivaTest ( void ){
    int i = 0;
    
  	float in1[] =    { 4.0f , 3.0f , 8.0f , 9.0f } ;
	float in2[] =    { 1.0f , 3.0f , 2.0f , 4.0f } ;
	float result[] = { -1.25f , 0.75f , -1.166666666666666f ,0.83333333333333333f };
	
	
	float out [(COLUMNS2)*(LINES)] ;

	sldiva(  in1 , LINES , COLUMNS1 , in2 , LINES , COLUMNS2 , out ) ;	
	for ( i = 0 ; i < LINES *COLUMNS2  ; i++ )
	{
		printf ( "\t\t %d out : %e\tresult : %e\tassert : %e \n" , i , out[i] , result[i] , fabs ( out[i] - result[i] ) / fabs( out[i]) ) ;
		
			assert ( fabs ( out[i] - result[i] ) / fabs( out[i]) < 1e-06 ) ;
	}
	  
    
    
}


static void dldivaTest ( void )
{
	int i = 0 ; 
/* here the matrixes are linearized in the wrong way so need to transpose them */
/*	double in1[] =
{0.84155184263363481,0.26385784195736051,0.52570608118548989,0.54653349192813039,
 0.62128817522898316,0.98085420625284314,0.74896081397309899,0.01432593585923314,
 0.23678414756432176,0.70614896761253476,0.27255953708663583,0.06706167431548238,
 0.43117330456152558,0.7741842647083104,0.57694048294797540,0.26086253346875310,
 0.14094856614246964,
0.40620247554033995,0.52535630855709314,0.99312098976224661,0.98854076582938433,
 0.34549844544380903,0.81870661024004221,0.94149570073932409,0.81914897728711367,
 0.70153435599058867,0.67878311965614557,0.34376550372689962,0.76511315722018480,
 0.61453847866505384,0.79220082703977823,0.39386960770934820,0.36363423336297274,
 0.67591095995157957,
0.40948254754766822,0.53762298030778766,0.64885628735646605,0.73956565884873271,
 0.70648676296696067,0.42568723810836673,0.21240556007251143,0.13049928424879909,
 0.12025266280397773,0.41329363686963916,0.20337020372971892,0.04173615900799632,
 0.92589621385559440,0.55046048713847995,0.68885837262496352,0.17466178117319942,
 0.45126775791868567,
0.87841258011758327,0.11999255046248436,0.99231909401714802,0.00371731072664261,
 0.52114724926650524,0.24615605548024178,0.57950199581682682,0.96820035576820374,
 0.82874121330678463,0.14022908732295036,0.30119446106255054,0.34382718056440353,
 0.09938172809779644,0.40850437059998512,0.97023218311369419,0.92341394722461700,
 0.75430292449891567,
0.11383596854284406,0.2256303490139544,0.05004197778180242,0.59005728596821427,
 0.28704008506610990,0.92295324662700295,0.26281475694850087,0.6561381467618048,
 0.31610729591920972,0.49523561308160424,0.27625959040597081,0.1970167332328856,
 0.42805786477401853,0.72174380579963326,0.85157642932608724,0.76051409030333161,
 0.13702143030241132,
0.19983377400785685,0.62740930821746588,0.74855065811425447,0.3096467358991504,
 0.65027950797230005,0.10007458087056875,0.43609866220504045,0.24455389659851789,
 0.53051907662302256,0.41948772873729467,0.29445307422429323,0.21228986512869596,
 0.94318309519439936,0.47685358580201864,0.33933044690638781,0.56402041297405958,
 0.66082405392080545,
0.56186607433483005,0.76084325974807143,0.41040589986369014,0.25522057106718421,
 0.08813347620889544,0.46782181179150939,0.91105451015755534,0.52831235667690635,
 0.57151748193427920,0.86262222891673446,0.57180739520117640,0.31403985014185309,
 0.03273952705785632,0.63930579042062163,0.87725317804142833,0.37970651825889945,
 0.38900542212650180,
0.58961773291230202,0.04855662025511265,0.60845263302326202,0.62518793903291225,
 0.44987633451819420,0.39504976756870747,0.80826673656702042,0.84689256362617016,
 0.04780154302716255,0.28575096465647221,0.21417701244354248,0.78216253779828548,
 0.92132670804858208,0.99638652987778187,0.11314024776220322,0.87762261740863323,
 0.70018205419182777,
0.68539796629920602,0.67239497276023030,0.85442108893766999,0.11574173765257001,
 0.72272530803456903,0.03661171020939946,0.81026530498638749,0.78766220854595304,
 0.82486197212710977,0.25121363671496511,0.68954616272822022,0.05409323470667005,
 0.94490244099870324,0.15747882844880223,0.5264128320850432,0.82174257980659604,
 0.91680057207122445,
0.89062247332185507,0.20171726960688829,0.06426467280834913,0.61170040909200907,
 0.89767962601035833,0.51753685344010592,0.25904283951967955,0.12620826158672571,
 0.5798843121156096,0.33891015965491533,0.58555728476494551,0.91902069095522165,
 0.900706990621984,0.53506936598569155,0.52973940502852201,0.67870581243187189,
 0.21228999551385641,
0.50422128057107329,0.39115739194676280,0.82790829380974174,0.67839562846347690,
 0.24278218811377883,0.83254515705630183,0.41390872886404395,0.78838609857484698,
 0.27918082987889647,0.39219759730622172,0.42041230341419578,0.46035157097503543,
 0.80943161016330123,0.21290646074339747,0.92917560925707221,0.08220098121091723,
 0.26978330826386809,
0.34936154074966908,0.83003165572881699,0.92623437754809856,0.33200952783226967,
 0.43377211131155491,0.61048321425914764,0.35999277792870998,0.34530424699187279,
 0.95451109297573566,0.46815521270036697,0.42775720171630383,0.29926850274205208,
 0.02519542910158634,0.55914506316184998,0.97654302977025509,0.25527314469218254,
 0.31998893804848194,
0.38737787725403905,0.58787201577797532,0.56672112690284848,0.02587099233642220,
 0.96770532103255391,0.18711117887869477,0.69127879338338971,0.26598573336377740,
 0.90711546363309026,0.33616027468815446,0.31845858739688993,0.00291663268581033,
 0.00196450622752309,0.43049659812822938,0.62254639761522412,0.74444567272439599,
 0.02321802498772740,
0.92228986788541079,0.48291792999953032,0.57116389367729425,0.51744682248681784,
 0.50685344357043505,0.01895748358219862,0.76568587962538004,0.97098186518996954,
 0.33601493109017611,0.53368766140192747,0.57618944440037012,0.89934705849736929,
 0.50752213317900896,0.02280548494309187,0.98225832823663950,0.22695036139339209,
 0.72654472757130861,
0.94881842611357570,0.22328650346025825,0.81601104838773608,0.39168732380494475,
 0.52329764096066356,0.84335647663101554,0.35726496530696750,0.88752476638182998,
 0.11756130633875728,0.20390639593824744,0.42549022240564227,0.83879271661862731,
 0.40760429529473186,0.57614597817882895,0.75429888023063540,0.68369307881221175,
 0.15340585587546229,
0.34353372454643250,0.84008856676518917,0.05689279362559319,0.24135384149849415,
 0.5596947595477104,0.07485948316752911,0.76933998242020607,0.20667528547346592,
 0.92537237703800201,0.15899897180497646,0.97619816288352013,0.43437494523823261,
 0.84080461412668228,0.71491303853690624,0.54547880962491035,0.93650726415216923,
 0.23552638292312622,
0.37601187312975526,0.12059959070757031,0.55959366867318749,0.50644348980858922,
 0.56173070007935166,0.85328151332214475,0.54776339093223214,0.85251609655097127,
 0.72636712575331330,0.01818151073530316,0.25189600000157952,0.77678761305287480,
 0.5017265700735152,0.93216359661892056,0.72860160330310464,0.50530174048617482,
 0.08797382796183228,
0.73409405630081892,0.28553641680628061,0.12493403162807226,0.42361020017415285,
 0.46817600261420012,0.01245901081711054,0.09622887428849936,0.67446978110820055,
 0.90094979386776686,0.40983706060796976,0.43911290075629950,0.13953176606446505,
 0.91287807654589415,0.12326993141323328,0.02525969501584768,0.25248145777732134,
 0.71059537213295698,
0.26157614728435874,0.86075146449729800,0.72792222863063216,0.28937275288626552,
 0.77945467224344611,0.18675393564626575,0.95611717319115996,0.91528743831440806,
 0.39489932497963309,0.01058345986530185,0.07593036955222487,0.11506372271105647,
 0.44357294728979468,0.28655522270128131,0.40251684701070189,0.68188397912308574,
 0.68887275597080588,
0.49934938363730907,0.84941016510128975,0.26777664758265018,0.08879321813583374,
 0.79010718129575253,0.49205840751528740,0.22074085660278797,0.02848597615957260,
 0.56551797501742840,0.19653097167611122,0.25593801774084568,0.53554199635982513,
 0.59837839566171169,0.01247995719313622,0.09831319935619831,0.28363681584596634,
 0.65953194908797741};

		
	double in2[] = 
{0.18151161121204495,0.77340125897899270,0.25145971449092031,0.37096222722902894,
 0.46179189579561353,0.47909884760156274,0.66919379355385900,0.06942595774307847,
 0.56079538213089108,0.69204960623756051,0.99401472182944417,0.00291080260649323,
0.3904965976253152,0.4244190966710448,0.38433500844985247,0.30322382133454084,
 0.62512917164713144,0.28169692959636450,0.20426016021519899,0.11522095929831266,
 0.94247916433960199,0.70065794046968222,0.18287624139338732,0.30681814532727003,
0.15869047446176410,0.72621259605512023,0.43964602379128337,0.95195201179012656,
 0.70597065938636661,0.23800977831706405,0.8310431349091232,0.48626806726679206,
 0.68177247745916247,0.88706119870766997,0.30219173757359385,0.79026939114555717,
0.62407150492072105,0.70999773032963276,0.65407369285821915,0.71278580836951733,
 0.70181696489453316,0.32942054606974125,0.01221632957458496,0.76715826056897640,
 0.27342410013079643,0.69797694869339466,0.37854864448308945,0.95779503695666790,
0.63760355720296502,0.47457459988072515,0.58781063789501786,0.11923700617626309,
 0.40879997471347451,0.23067280324175954,0.48844617092981935,0.08805298106744885,
 0.20717754075303674,0.67989911558106542,0.71531985932961106,0.66892711864784360,
0.42704886104911566,0.9438692079856992,0.60208318661898375,0.50091631803661585,
 0.06362213846296072,0.21362966019660234,0.95498770754784346,0.70085612777620554,
 0.19379387702792883,0.36159398127347231,0.95241537224501371,0.29296159837394953,
0.10716815060004592,0.14596485672518611,0.04535020282492042,0.32900535268709064,
 0.06573933875188231,0.40549980429932475,0.05874312063679099,0.18791387928649783,
 0.67978375917300582,0.26739976881071925,0.47039186349138618,0.82238993747159839,
0.23822965659201145,0.07141010463237762,0.20294443331658840,0.48089468106627464,
 0.53310041315853596,0.30953712016344070,0.82584649138152599,0.20178856328129768,
 0.58836574293673038,0.07736870646476746,0.18709417246282101,0.01798455044627190,
0.94629473658278584,0.67337385797873139,0.78442738251760602,0.33036959776654840,
 0.03315818728879094,0.67629716033115983,0.29807415651157498,0.40628212550655007,
 0.93317538173869252,0.14941003406420350,0.25571879046037793,0.87107013771310449,
0.45766852516680956,0.65369247179478407,0.26375361625105143,0.63044753577560186,
 0.31578356493264437,0.97069163154810667,0.07757596764713526,0.40966569539159536,
 0.55091228801757097,0.32018390577286482,0.44350660685449839,0.31810243334621191,
0.89644787041470408,0.19968961318954825,0.43832763982936740,0.21171907847747207,
 0.37858232436701655,0.54417965700849891,0.58460923237726092,0.17695645010098815,
 0.80405469564720988,0.20260545751079917,0.72340781940147281,0.57244732743129134,
0.44384705275297165,0.60141251794993877,0.86648589745163918,0.44860231317579746,
 0.46195234358310699,0.02047479711472988,0.75287136062979698,0.33129312284290791,
 0.10744897276163101,0.44988587312400341,0.87619100883603096,0.57386581040918827,
0.80895681912079453,0.18993748771026731,0.37921421090140939,0.59145097108557820,
 0.62873698258772492,0.89413649635389447,0.05172297963872552,0.05184767069295049,
 0.74039250845089555,0.77075743721798062,0.03733208635821939,0.34920182498171926,
0.68317985069006681,0.25839814636856318,0.76687160786241293,0.68067426700145006,
 0.28785153012722731,0.34903638903051615,0.59586250688880682,0.41492417920380831,
 0.56103316973894835,0.24352242145687342,0.42934664245694876,0.7067297669127584,
0.03401931514963508,0.09878737432882190,0.60066213225945830,0.07392961112782359,
 0.3292048736475408,0.11053651524707675,0.38337053125724196,0.72212355909869075,
 0.76611549546942115,0.21261148853227496,0.31572330510243773,0.35992007283493876,
0.23805456422269344,0.06199027225375175,0.78567356057465076,0.94336947053670883,
 0.47192330472171307,0.20233777537941933,0.49002202786505222,0.07746253907680511,
 0.78306589089334011,0.10992341861128807,0.36824773438274860,0.40523112565279007,
0.94920115964487195,0.04034968325868249,0.73871155502274632,0.12863306934013963,
 0.33537696348503232,0.13046909729018807,0.52727950783446431,0.58558783913031220,
 0.14388314681127667,0.69814807781949639,0.14587742509320378,0.61408105725422502,
0.21827886346727610,0.74001471605151892,0.55442603398114443,0.20190807711333036,
 0.55530697200447321,0.85739529784768820,0.06889454741030931,0.37079446297138929,
 0.16471924725919962,0.41509064938873053,0.67683792579919100,0.65240467619150877,
0.61546878470107913,0.61626600986346602,0.99291495559737086,0.19693034281954169,
 0.11960808141157031,0.63780163740739226,0.88430777518078685,0.21161167463287711,
 0.31774142337962985,0.50298188393935561,0.52619793592020869,0.02951709320768714,
0.83135433867573738,0.6583583448082209,0.97574284672737122,0.89286901615560055,
 0.76139996573328972,0.40711227245628834,0.71912937611341476,0.19032685272395611,
 0.50265956297516823,0.75116067565977573,0.400362566113472,0.56688958965241909}
;

	double result[] = 
{-1.35304848520861487,0.45754085729476712,-0.6736280871889024,0.33207797896852592,
 0.43686665386108053,1.19699150804728482,-0.53382978138054371,0.29027772826683890,
 -0.00827371705993142,-0.14056593966637726,0.97528495242825564,-0.50640321961329704,
-1.02292396789679763,0.14683824772822532,0.07187827219700703,0.26493234152584039,
 0.19039952557132572,0.55480813680166574,0.39823783903528059,0.10487653718583664,
 -0.01169765032881238,-0.12935543309398898,0.91373948525086457,-0.42095065668914605,
-0.19349758378824730,-0.02882981029864774,-0.22391869192699457,-0.15720068678475169,
 -0.07066729236062046,-0.22778476192919797,-0.07232798550562215,0.25736303036550690,
 0.46282933263406362,-0.30812642599955187,-0.13899968979779151,-0.29110054036689564,
-1.03603776312515605,0.41831226411022665,-0.26815455630947649,0.32749202801394556,
 0.71958381253175108,0.50743495139986494,-0.77843454048260496,-0.65128619093814355,
 0.45389989732032809,0.25340453725266349,-0.22487431273588654,-0.69327413947497007,
1.23257217178938916,-0.20500752874670841,1.17935058240805546,-0.07005924340124725,
 0.02202972751083646,-0.74349480264981749,0.78826180830363013,0.00378475165255014,
 0.20312102001296634,0.76317680003707100,-1.2444586343524908,0.61835799875331021,
0.82435969088956451,0.14161838805165022,0.54413699368884894,-0.35024810526933553,
 0.10736628125177422,-0.30342706713796774,0.16551618468279145,-0.33044241080800685,
 0.26090949768379634,0.36311977822561886,-0.02216943459020578,0.28290526888357609,
0.60758986375566237,-0.17769508155988095,-0.37428738263361294,0.06973138803028064,
 -0.26917609149376737,0.57488494776039478,-0.16182837448139925,-0.54589681560051329,
 0.35855708857331126,-0.06225155630035748,-0.01420478239284544,-0.51044946988565809,
0.30247332250465692,-0.58709398545244817,0.52755056373610110,-0.87395680874726944,
 -0.25878588799924235,-0.14016351767195534,0.26932123245105705,0.18741971186875042,
 -0.10443218008098379,-0.04666556894424437,-0.28998246181099013,0.39888953797173432,
0.29894996645459254,0.44648385188893014,-0.2747623990687768,0.12767005544410789,
 0.31187612680253268,0.93787911555703019,-0.69506239058785912,0.05675543905552551,
 -0.38364317006532606,0.3015716880761152,0.60874303825197718,-0.02132168933396992,
0.28919354677500908,0.08791044194229901,-0.66719204004654808,-0.38892391716572344,
 -0.35074795512020418,0.52079480741130679,-0.12341534994946383,0.10603293453188402,
 0.13292792440340936,-0.03924161719101939,0.50135087079896590,0.13741552942080246,
0.38584460158392103,-1.05581700070645756,1.33305654920496308,-0.4661197871120432,
 -0.29411616444505956,-2.27258047015748854,0.15783833704105082,-0.52713266629484568,
 1.16440529465468257,-0.45001368365485012,-2.15999736051125257,1.01319717905315843,
0.29660053528020919,-0.30427398541498984,-0.12504282968902436,0.25589579382097077,
 -0.08693274594974670,-0.03498727188829748,0.07574429063044799,0.24558509581470137,
 -0.11120224069858284,-0.21580250756805028,-0.02724340730221109,-0.16362172134690667,
0.39424507332817937,0.26915663350224511,-0.48616892178714571,0.06722217755862435,
 -0.30789732141190385,0.93830157987553686,0.36043785223845126,0.42644383761017990,
 -0.13641385018671429,-0.30094945006660034,1.13850388440322159,-0.12250602188987858,
-0.66991170773376507,-0.33568935537136302,0.34616388717968199,0.16394571168478128,
 0.11497788571365419,-1.12355992799920523,0.90321218371657097,0.51843407168999134,
 -0.5333460102169536,0.19508185891564755,-0.24491167665302710,0.43625522780082732,
0.52362419925864290,0.35626701996484733,0.07409894473807596,0.6687300563276672,
 0.02130172947699538,0.07525160898747016,0.33548314852403621,0.36350170853544833,
 -0.43456386741360986,0.30564069254711729,0.60413672598431878,0.62344267157598554,
-0.55671778762503188,0.51384740986051547,-0.66364280764764905,0.20946393028509858,
 0.21734134196942456,1.01080770232414596,-0.81218225821401002,-0.14076620249135630,
 0.32963958497594853,-0.23647842638263297,0.58596014599473090,-0.68150457913031526,
0.52872556238983059,0.57098625620273025,1.06212082783082407,0.59423966432136910,
 0.34731906030365728,-1.35636228486699051,0.60027136476023302,-0.01921912593105047,
 -0.26023872041264290,0.60546432820947238,-0.64774098495099597,1.07329929083653908}
;	
	
*/

	
	double in1[] =    { 4 , 3 , 8 , 9 } ;
	double in2[] =    { 1 , 3 , 2 , 4 } ;
	double result[] = { -1.25 , 0.75 , -1.166666666666666 ,0.83333333333333333 };
	
	
	double out [(COLUMNS2)*(LINES)] ;

	dldiva(  in1 , LINES , COLUMNS1 , in2 , LINES , COLUMNS2 , out ) ;	
	for ( i = 0 ; i < LINES *COLUMNS2  ; i++ )
	{
		printf ( "\t\t %d out : %e\tresult : %e\tassert : %e \n" , i , out[i] , result[i] , fabs ( out[i] - result[i] ) / fabs( out[i]) ) ;
		
			assert ( fabs ( out[i] - result[i] ) / fabs( out[i]) < 1e-15 ) ;
	}
	
}


static void zldivaTest (void )
{
    int i = 0 ;
    
    double tin1[] = { 10 , 9 , 2 ,4};
    double tin2[] = { 1 , 2};
    
    
	doubleComplex* in1 ;
	doubleComplex* in2 ;
	doubleComplex* out  ;
	doubleComplex Result[ZLINES*ZLINES] ;

	in1 = DoubleComplexMatrix (  tin1 , tin1 , ZLINES*ZCOLUMNS1 );
	in2 = DoubleComplexMatrix (  tin2 , tin2 , ZLINES*ZCOLUMNS2 );
    out = DoubleComplexMatrix (  tin2 , tin2 , ZLINES*ZLINES );
	
    Result[0] = DoubleComplex ( 0 ,  0 );
    Result[1] = DoubleComplex ( 0.5   , 0 );
    
	zldiva ( in1 , ZLINES , ZCOLUMNS1 , in2 ,ZLINES , ZCOLUMNS2 , out) ;
	
		for ( i = 0 ; i < (ZCOLUMNS1*ZCOLUMNS2 )  ; i++ )
	{
	  printf ( "\t\t %d out : %e + %e * i  result : %e + %e * i   assert : %e + %e \n" ,
              i ,zreals(out[i]) , zimags(out[i]) , zreals (Result[i])  , zimags (Result[i]),
              fabs(  zreals(out[i]) -  zreals (Result[i]) ) / fabs (zreals (out[i])) ,
              fabs(  zimags(out[i]) -  zimags (Result[i]) ) / fabs (zimags (out[i])));
        
    /*assert ( fabs(  zreals(out[i]) -  zreals (Result[i]) ) / fabs (zreals (out[i]))  < 1e-17 );
	  assert ( fabs(  zimags(out[i]) -  zimags (Result[i]) ) / fabs (zimags (out[i]))  < 1e-17 ) ;
    */
	}
    
}



static int testLDiva   (void) {
  printf("\n\n\n\n*********************\n");
  printf("***** Left Tests ****\n");
  printf("*********************\n");
    
  printf("\n\t>>>>Float real  Tests\n"); 
  sldivaTest();
    
  printf("\n\n\n\t>>>> Double real  Tests\n");
  dldivaTest();

  printf("\n\t>>>> Double complex  Tests\n");
  zldivaTest();	
	
  return 0;
}

int main(void) {
  assert(testLDiva () == 0);
  return 0;
}

