module map9v3(clock, reset, start, N, dp, done, counter, sr);

wire new__0_;
wire new__100_;
wire new__101_;
wire new__102_;
wire new__103_;
wire new__104_;
wire new__105_;
wire new__106_;
wire new__107_;
wire new__108_;
wire new__109_;
wire new__10_;
wire new__110_;
wire new__111_;
wire new__112_;
wire new__113_;
wire new__114_;
wire new__115_;
wire new__116_;
wire new__117_;
wire new__118_;
wire new__119_;
wire new__11_;
wire new__120_;
wire new__121_;
wire new__122_;
wire new__123_;
wire new__124_;
wire new__125_;
wire new__126_;
wire new__127_;
wire new__128_;
wire new__129_;
wire new__12_;
wire new__130_;
wire new__131_;
wire new__132_;
wire new__133_;
wire new__134_;
wire new__135_;
wire new__136_;
wire new__137_;
wire new__138_;
wire new__139_;
wire new__13_;
wire new__140_;
wire new__141_;
wire new__142_;
wire new__143_;
wire new__144_;
wire new__145_;
wire new__146_;
wire new__147_;
wire new__148_;
wire new__149_;
wire new__14_;
wire new__150_;
wire new__151_;
wire new__152_;
wire new__153_;
wire new__154_;
wire new__155_;
wire new__156_;
wire new__157_;
wire new__158_;
wire new__159_;
wire new__15_;
wire new__160_;
wire new__161_;
wire new__162_;
wire new__163_;
wire new__164_;
wire new__165_;
wire new__166_;
wire new__167_;
wire new__168_;
wire new__169_;
wire new__16_;
wire new__170_;
wire new__171_;
wire new__172_;
wire new__173_;
wire new__174_;
wire new__175_;
wire new__176_;
wire new__177_;
wire new__178_;
wire new__179_;
wire new__17_;
wire new__180_;
wire new__181_;
wire new__182_;
wire new__183_;
wire new__184_;
wire new__185_;
wire new__186_;
wire new__187_;
wire new__188_;
wire new__18_;
wire new__19_;
wire new__1_;
wire new__20_;
wire new__21_;
wire new__22_;
wire new__23_;
wire new__24_;
wire new__25_;
wire new__26_;
wire new__27_;
wire new__28_;
wire new__29_;
wire new__2_;
wire new__30_;
wire new__31_;
wire new__32_;
wire new__33_;
wire new__34_;
wire new__35_;
wire new__36_;
wire new__37_;
wire new__38_;
wire new__39_;
wire new__3_;
wire new__40_;
wire new__41_;
wire new__42_;
wire new__43_;
wire new__44_;
wire new__45_;
wire new__46_;
wire new__47_;
wire new__48_;
wire new__49_;
wire new__4_;
wire new__50_;
wire new__51_;
wire new__52_;
wire new__53_;
wire new__54_;
wire new__55_;
wire new__56_;
wire new__57_;
wire new__58_;
wire new__59_;
wire new__5_;
wire new__60_;
wire new__61_;
wire new__62_;
wire new__63_;
wire new__64_;
wire new__65_;
wire new__66_;
wire new__67_;
wire new__68_;
wire new__69_;
wire new__6_;
wire new__70_;
wire new__71_;
wire new__72_;
wire new__73_;
wire new__74_;
wire new__75_;
wire new__76_;
wire new__77_;
wire new__78_;
wire new__79_;
wire new__7_;
wire new__80_;
wire new__81_;
wire new__82_;
wire new__83_;
wire new__84_;
wire new__85_;
wire new__86_;
wire new__87_;
wire new__88_;
wire new__89_;
wire new__8_;
wire new__90_;
wire new__91_;
wire new__92_;
wire new__93_;
wire new__94_;
wire new__95_;
wire new__96_;
wire new__97_;
wire new__98_;
wire new__99_;
wire new__9_;
wire new_startbuf_0;
wire new_startbuf_1;
wire new_state_0;
wire new_state_1;
wire new_state_2;
wire new_state_3;
wire new_state_4;
input clock;
input reset;
input start;
input [8:0] N;output [8:0] dp;output done;
output [7:0] counter;output [7:0] sr;
INV_X1 #
) INV_X1_0_ (
  .A({ new_state_0 }),
  .ZN({ new__115_ })
);
INV_X1 #
) INV_X1_1_ (
  .A({ new__168_ }),
  .ZN({ new__116_ })
);
INV_X1 #
) INV_X1_2_ (
  .A({ new__169_ }),
  .ZN({ new__117_ })
);
INV_X1 #
) INV_X1_3_ (
  .A({ new__170_ }),
  .ZN({ new__118_ })
);
INV_X1 #
) INV_X1_4_ (
  .A({ new__167_ }),
  .ZN({ new__119_ })
);
NOR2_X1 #
) NOR2_X1_5_ (
  .A1({ new__164_ }),
  .A2({ new__163_ }),
  .ZN({ new__120_ })
);
NOR2_X1 #
) NOR2_X1_6_ (
  .A1({ new__166_ }),
  .A2({ new__165_ }),
  .ZN({ new__121_ })
);
AND3_X1 #
) AND3_X1_7_ (
  .A1({ new__121_ }),
  .A2({ new__120_ }),
  .A3({ new__119_ }),
  .ZN({ new__122_ })
);
NAND4_X1 #
) NAND4_X1_8_ (
  .A1({ new__122_ }),
  .A2({ new__118_ }),
  .A3({ new__117_ }),
  .A4({ new__116_ }),
  .ZN({ new__123_ })
);
NAND2_X1 #
) NAND2_X1_9_ (
  .A1({ new__123_ }),
  .A2({ new_state_3 }),
  .ZN({ new__124_ })
);
NAND2_X1 #
) NAND2_X1_10_ (
  .A1({ new__124_ }),
  .A2({ new__115_ }),
  .ZN({ new__4_ })
);
INV_X1 #
) INV_X1_11_ (
  .A({ new_state_4 }),
  .ZN({ new__125_ })
);
INV_X1 #
) INV_X1_12_ (
  .A({ new_startbuf_0 }),
  .ZN({ new__126_ })
);
OAI21_X1 #
) OAI21_X1_13_ (
  .A({ new_state_1 }),
  .B1({ new__126_ }),
  .B2({ new_startbuf_1 }),
  .ZN({ new__127_ })
);
NAND2_X1 #
) NAND2_X1_14_ (
  .A1({ new__127_ }),
  .A2({ new__125_ }),
  .ZN({ new__3_ })
);
INV_X1 #
) INV_X1_15_ (
  .A({ new_state_1 }),
  .ZN({ new__128_ })
);
NOR3_X1 #
) NOR3_X1_16_ (
  .A1({ new__128_ }),
  .A2({ new__126_ }),
  .A3({ new_startbuf_1 }),
  .ZN({ new__1_ })
);
INV_X1 #
) INV_X1_17_ (
  .A({ new_state_3 }),
  .ZN({ new__129_ })
);
NOR2_X1 #
) NOR2_X1_18_ (
  .A1({ new__123_ }),
  .A2({ new__129_ }),
  .ZN({ new__2_ })
);
INV_X1 #
) INV_X1_19_ (
  .A({ new__163_ }),
  .ZN({ new__130_ })
);
NOR2_X1 #
) NOR2_X1_20_ (
  .A1({ new_state_3 }),
  .A2({ new_state_0 }),
  .ZN({ new__131_ })
);
INV_X1 #
) INV_X1_21_ (
  .A({ new__131_ }),
  .ZN({ new__132_ })
);
NOR2_X1 #
) NOR2_X1_22_ (
  .A1({ new__129_ }),
  .A2({ new_state_0 }),
  .ZN({ new__34_ })
);
AOI22_X1 #
) AOI22_X1_23_ (
  .A1({ new__34_ }),
  .A2({ new__6_ }),
  .B1({ new_state_0 }),
  .B2({ N[1] }),
  .ZN({ new__35_ })
);
OAI21_X1 #
) OAI21_X1_24_ (
  .A({ new__35_ }),
  .B1({ new__130_ }),
  .B2({ new__132_ }),
  .ZN({ new__8_ })
);
INV_X1 #
) INV_X1_25_ (
  .A({ new__34_ }),
  .ZN({ new__36_ })
);
NAND2_X1 #
) NAND2_X1_26_ (
  .A1({ N[1] }),
  .A2({ N[2] }),
  .ZN({ new__37_ })
);
INV_X1 #
) INV_X1_27_ (
  .A({ new__37_ }),
  .ZN({ new__38_ })
);
NOR2_X1 #
) NOR2_X1_28_ (
  .A1({ N[1] }),
  .A2({ N[2] }),
  .ZN({ new__39_ })
);
OAI21_X1 #
) OAI21_X1_29_ (
  .A({ new_state_0 }),
  .B1({ new__38_ }),
  .B2({ new__39_ }),
  .ZN({ new__40_ })
);
NAND2_X1 #
) NAND2_X1_30_ (
  .A1({ new__131_ }),
  .A2({ new__164_ }),
  .ZN({ new__41_ })
);
XOR2_X1 #
) XOR2_X1_31_ (
  .A({ new__164_ }),
  .B({ new__163_ }),
  .Z({ new__42_ })
);
OAI211_X1 #
) OAI211_X1_32_ (
  .A({ new__40_ }),
  .B({ new__41_ }),
  .C1({ new__42_ }),
  .C2({ new__36_ }),
  .ZN({ new__9_ })
);
NAND2_X1 #
) NAND2_X1_33_ (
  .A1({ new__38_ }),
  .A2({ N[3] }),
  .ZN({ new__43_ })
);
INV_X1 #
) INV_X1_34_ (
  .A({ N[3] }),
  .ZN({ new__44_ })
);
NAND2_X1 #
) NAND2_X1_35_ (
  .A1({ new__37_ }),
  .A2({ new__44_ }),
  .ZN({ new__45_ })
);
NAND3_X1 #
) NAND3_X1_36_ (
  .A1({ new__43_ }),
  .A2({ new_state_0 }),
  .A3({ new__45_ }),
  .ZN({ new__46_ })
);
INV_X1 #
) INV_X1_37_ (
  .A({ new__120_ }),
  .ZN({ new__47_ })
);
OAI211_X1 #
) OAI211_X1_38_ (
  .A({ new__165_ }),
  .B({ new__115_ }),
  .C1({ new__47_ }),
  .C2({ new__129_ }),
  .ZN({ new__48_ })
);
NOR2_X1 #
) NOR2_X1_39_ (
  .A1({ new__47_ }),
  .A2({ new__165_ }),
  .ZN({ new__49_ })
);
NAND3_X1 #
) NAND3_X1_40_ (
  .A1({ new__49_ }),
  .A2({ new_state_3 }),
  .A3({ new__115_ }),
  .ZN({ new__50_ })
);
NAND3_X1 #
) NAND3_X1_41_ (
  .A1({ new__50_ }),
  .A2({ new__46_ }),
  .A3({ new__48_ }),
  .ZN({ new__10_ })
);
INV_X1 #
) INV_X1_42_ (
  .A({ N[4] }),
  .ZN({ new__51_ })
);
AOI21_X1 #
) AOI21_X1_43_ (
  .A({ new__51_ }),
  .B1({ new__37_ }),
  .B2({ new__44_ }),
  .ZN({ new__52_ })
);
AND3_X1 #
) AND3_X1_44_ (
  .A1({ new__37_ }),
  .A2({ new__51_ }),
  .A3({ new__44_ }),
  .ZN({ new__53_ })
);
OR3_X1 #
) OR3_X1_45_ (
  .A1({ new__53_ }),
  .A2({ new__52_ }),
  .A3({ new__115_ }),
  .ZN({ new__54_ })
);
NAND2_X1 #
) NAND2_X1_46_ (
  .A1({ new__131_ }),
  .A2({ new__166_ }),
  .ZN({ new__55_ })
);
XNOR2_X1 #
) XNOR2_X1_47_ (
  .A({ new__49_ }),
  .B({ new__166_ }),
  .ZN({ new__56_ })
);
OAI211_X1 #
) OAI211_X1_48_ (
  .A({ new__54_ }),
  .B({ new__55_ }),
  .C1({ new__56_ }),
  .C2({ new__36_ }),
  .ZN({ new__11_ })
);
INV_X1 #
) INV_X1_49_ (
  .A({ N[5] }),
  .ZN({ new__57_ })
);
NOR2_X1 #
) NOR2_X1_50_ (
  .A1({ new__53_ }),
  .A2({ new__57_ }),
  .ZN({ new__58_ })
);
NOR2_X1 #
) NOR2_X1_51_ (
  .A1({ N[3] }),
  .A2({ N[4] }),
  .ZN({ new__59_ })
);
NAND3_X1 #
) NAND3_X1_52_ (
  .A1({ new__59_ }),
  .A2({ new__57_ }),
  .A3({ new__37_ }),
  .ZN({ new__60_ })
);
NAND2_X1 #
) NAND2_X1_53_ (
  .A1({ new__60_ }),
  .A2({ new_state_0 }),
  .ZN({ new__61_ })
);
AOI21_X1 #
) AOI21_X1_54_ (
  .A({ new__119_ }),
  .B1({ new__120_ }),
  .B2({ new__121_ }),
  .ZN({ new__62_ })
);
OAI21_X1 #
) OAI21_X1_55_ (
  .A({ new__34_ }),
  .B1({ new__122_ }),
  .B2({ new__62_ }),
  .ZN({ new__63_ })
);
OAI221_X1 #
) OAI221_X1_56_ (
  .A({ new__63_ }),
  .B1({ new__58_ }),
  .B2({ new__61_ }),
  .C1({ new__132_ }),
  .C2({ new__119_ }),
  .ZN({ new__12_ })
);
NAND3_X1 #
) NAND3_X1_57_ (
  .A1({ new__120_ }),
  .A2({ new__121_ }),
  .A3({ new__119_ }),
  .ZN({ new__64_ })
);
NAND4_X1 #
) NAND4_X1_58_ (
  .A1({ new__120_ }),
  .A2({ new__121_ }),
  .A3({ new__116_ }),
  .A4({ new__119_ }),
  .ZN({ new__65_ })
);
NAND2_X1 #
) NAND2_X1_59_ (
  .A1({ new__65_ }),
  .A2({ new__34_ }),
  .ZN({ new__66_ })
);
AOI21_X1 #
) AOI21_X1_60_ (
  .A({ new__66_ }),
  .B1({ new__64_ }),
  .B2({ new__168_ }),
  .ZN({ new__67_ })
);
NOR2_X1 #
) NOR2_X1_61_ (
  .A1({ new__132_ }),
  .A2({ new__168_ }),
  .ZN({ new__68_ })
);
NAND2_X1 #
) NAND2_X1_62_ (
  .A1({ new__60_ }),
  .A2({ N[6] }),
  .ZN({ new__69_ })
);
NOR2_X1 #
) NOR2_X1_63_ (
  .A1({ N[5] }),
  .A2({ N[6] }),
  .ZN({ new__70_ })
);
NAND3_X1 #
) NAND3_X1_64_ (
  .A1({ new__59_ }),
  .A2({ new__70_ }),
  .A3({ new__37_ }),
  .ZN({ new__71_ })
);
AOI21_X1 #
) AOI21_X1_65_ (
  .A({ new__115_ }),
  .B1({ new__69_ }),
  .B2({ new__71_ }),
  .ZN({ new__72_ })
);
NOR3_X1 #
) NOR3_X1_66_ (
  .A1({ new__67_ }),
  .A2({ new__72_ }),
  .A3({ new__68_ }),
  .ZN({ new__13_ })
);
INV_X1 #
) INV_X1_67_ (
  .A({ new__5_ }),
  .ZN({ new__73_ })
);
OAI21_X1 #
) OAI21_X1_68_ (
  .A({ new__34_ }),
  .B1({ new__65_ }),
  .B2({ new__73_ }),
  .ZN({ new__74_ })
);
AOI21_X1 #
) AOI21_X1_69_ (
  .A({ new__74_ }),
  .B1({ new__65_ }),
  .B2({ new__73_ }),
  .ZN({ new__75_ })
);
NAND2_X1 #
) NAND2_X1_70_ (
  .A1({ new__131_ }),
  .A2({ new__117_ }),
  .ZN({ new__76_ })
);
NAND3_X1 #
) NAND3_X1_71_ (
  .A1({ new__53_ }),
  .A2({ N[7] }),
  .A3({ new__70_ }),
  .ZN({ new__77_ })
);
INV_X1 #
) INV_X1_72_ (
  .A({ N[7] }),
  .ZN({ new__78_ })
);
NAND2_X1 #
) NAND2_X1_73_ (
  .A1({ new__71_ }),
  .A2({ new__78_ }),
  .ZN({ new__79_ })
);
NAND3_X1 #
) NAND3_X1_74_ (
  .A1({ new__77_ }),
  .A2({ new_state_0 }),
  .A3({ new__79_ }),
  .ZN({ new__80_ })
);
NAND2_X1 #
) NAND2_X1_75_ (
  .A1({ new__80_ }),
  .A2({ new__76_ }),
  .ZN({ new__81_ })
);
NOR2_X1 #
) NOR2_X1_76_ (
  .A1({ new__81_ }),
  .A2({ new__75_ }),
  .ZN({ new__14_ })
);
OAI21_X1 #
) OAI21_X1_77_ (
  .A({ new__118_ }),
  .B1({ new__65_ }),
  .B2({ new__73_ }),
  .ZN({ new__82_ })
);
NAND4_X1 #
) NAND4_X1_78_ (
  .A1({ new__122_ }),
  .A2({ new__5_ }),
  .A3({ new__170_ }),
  .A4({ new__116_ }),
  .ZN({ new__83_ })
);
AOI21_X1 #
) AOI21_X1_79_ (
  .A({ new__36_ }),
  .B1({ new__83_ }),
  .B2({ new__82_ }),
  .ZN({ new__84_ })
);
NAND2_X1 #
) NAND2_X1_80_ (
  .A1({ new__131_ }),
  .A2({ new__118_ }),
  .ZN({ new__85_ })
);
NAND4_X1 #
) NAND4_X1_81_ (
  .A1({ new__53_ }),
  .A2({ new__70_ }),
  .A3({ new__78_ }),
  .A4({ N[8] }),
  .ZN({ new__86_ })
);
INV_X1 #
) INV_X1_82_ (
  .A({ N[8] }),
  .ZN({ new__87_ })
);
NAND4_X1 #
) NAND4_X1_83_ (
  .A1({ new__59_ }),
  .A2({ new__70_ }),
  .A3({ new__78_ }),
  .A4({ new__37_ }),
  .ZN({ new__88_ })
);
NAND2_X1 #
) NAND2_X1_84_ (
  .A1({ new__88_ }),
  .A2({ new__87_ }),
  .ZN({ new__89_ })
);
NAND3_X1 #
) NAND3_X1_85_ (
  .A1({ new__86_ }),
  .A2({ new_state_0 }),
  .A3({ new__89_ }),
  .ZN({ new__90_ })
);
NAND2_X1 #
) NAND2_X1_86_ (
  .A1({ new__90_ }),
  .A2({ new__85_ }),
  .ZN({ new__91_ })
);
NOR2_X1 #
) NOR2_X1_87_ (
  .A1({ new__91_ }),
  .A2({ new__84_ }),
  .ZN({ new__15_ })
);
INV_X1 #
) INV_X1_88_ (
  .A({ new_state_2 }),
  .ZN({ new__92_ })
);
NOR2_X1 #
) NOR2_X1_89_ (
  .A1({ new__132_ }),
  .A2({ new__92_ }),
  .ZN({ new__93_ })
);
MUX2_X1 #
) MUX2_X1_90_ (
  .A({ new__172_ }),
  .B({ N[0] }),
  .S({ new__93_ }),
  .Z({ new__16_ })
);
INV_X1 #
) INV_X1_91_ (
  .A({ new__181_ }),
  .ZN({ new__94_ })
);
NOR2_X1 #
) NOR2_X1_92_ (
  .A1({ new__93_ }),
  .A2({ new__173_ }),
  .ZN({ new__95_ })
);
AOI21_X1 #
) AOI21_X1_93_ (
  .A({ new__95_ }),
  .B1({ new__93_ }),
  .B2({ new__94_ }),
  .ZN({ new__17_ })
);
MUX2_X1 #
) MUX2_X1_94_ (
  .A({ new__174_ }),
  .B({ new__182_ }),
  .S({ new__93_ }),
  .Z({ new__18_ })
);
MUX2_X1 #
) MUX2_X1_95_ (
  .A({ new__175_ }),
  .B({ new__183_ }),
  .S({ new__93_ }),
  .Z({ new__19_ })
);
MUX2_X1 #
) MUX2_X1_96_ (
  .A({ new__176_ }),
  .B({ new__184_ }),
  .S({ new__93_ }),
  .Z({ new__20_ })
);
MUX2_X1 #
) MUX2_X1_97_ (
  .A({ new__177_ }),
  .B({ new__185_ }),
  .S({ new__93_ }),
  .Z({ new__21_ })
);
MUX2_X1 #
) MUX2_X1_98_ (
  .A({ new__178_ }),
  .B({ new__186_ }),
  .S({ new__93_ }),
  .Z({ new__22_ })
);
MUX2_X1 #
) MUX2_X1_99_ (
  .A({ new__179_ }),
  .B({ new__187_ }),
  .S({ new__93_ }),
  .Z({ new__23_ })
);
INV_X1 #
) INV_X1_100_ (
  .A({ new__188_ }),
  .ZN({ new__96_ })
);
NOR2_X1 #
) NOR2_X1_101_ (
  .A1({ new__93_ }),
  .A2({ new__180_ }),
  .ZN({ new__97_ })
);
AOI21_X1 #
) AOI21_X1_102_ (
  .A({ new__97_ }),
  .B1({ new__93_ }),
  .B2({ new__96_ }),
  .ZN({ new__24_ })
);
NAND3_X1 #
) NAND3_X1_103_ (
  .A1({ new__129_ }),
  .A2({ new__92_ }),
  .A3({ new_state_4 }),
  .ZN({ new__98_ })
);
NAND2_X1 #
) NAND2_X1_104_ (
  .A1({ new__98_ }),
  .A2({ new__115_ }),
  .ZN({ new__99_ })
);
MUX2_X1 #
) MUX2_X1_105_ (
  .A({ new__171_ }),
  .B({ new__0_ }),
  .S({ new__99_ }),
  .Z({ new__25_ })
);
NAND2_X1 #
) NAND2_X1_106_ (
  .A1({ new__131_ }),
  .A2({ new__181_ }),
  .ZN({ new__100_ })
);
INV_X1 #
) INV_X1_107_ (
  .A({ new__184_ }),
  .ZN({ new__101_ })
);
INV_X1 #
) INV_X1_108_ (
  .A({ new__185_ }),
  .ZN({ new__102_ })
);
NAND2_X1 #
) NAND2_X1_109_ (
  .A1({ new__96_ }),
  .A2({ new__102_ }),
  .ZN({ new__103_ })
);
NAND2_X1 #
) NAND2_X1_110_ (
  .A1({ new__188_ }),
  .A2({ new__185_ }),
  .ZN({ new__104_ })
);
NAND3_X1 #
) NAND3_X1_111_ (
  .A1({ new__103_ }),
  .A2({ new__186_ }),
  .A3({ new__104_ }),
  .ZN({ new__105_ })
);
INV_X1 #
) INV_X1_112_ (
  .A({ new__186_ }),
  .ZN({ new__106_ })
);
NAND2_X1 #
) NAND2_X1_113_ (
  .A1({ new__103_ }),
  .A2({ new__104_ }),
  .ZN({ new__107_ })
);
NAND2_X1 #
) NAND2_X1_114_ (
  .A1({ new__107_ }),
  .A2({ new__106_ }),
  .ZN({ new__108_ })
);
AOI21_X1 #
) AOI21_X1_115_ (
  .A({ new__101_ }),
  .B1({ new__108_ }),
  .B2({ new__105_ }),
  .ZN({ new__109_ })
);
NAND3_X1 #
) NAND3_X1_116_ (
  .A1({ new__108_ }),
  .A2({ new__101_ }),
  .A3({ new__105_ }),
  .ZN({ new__110_ })
);
NAND3_X1 #
) NAND3_X1_117_ (
  .A1({ new__110_ }),
  .A2({ new__0_ }),
  .A3({ new__132_ }),
  .ZN({ new__111_ })
);
OAI21_X1 #
) OAI21_X1_118_ (
  .A({ new__100_ }),
  .B1({ new__111_ }),
  .B2({ new__109_ }),
  .ZN({ new__26_ })
);
INV_X1 #
) INV_X1_119_ (
  .A({ new__182_ }),
  .ZN({ new__112_ })
);
OAI22_X1 #
) OAI22_X1_120_ (
  .A1({ new__36_ }),
  .A2({ new__94_ }),
  .B1({ new__132_ }),
  .B2({ new__112_ }),
  .ZN({ new__27_ })
);
INV_X1 #
) INV_X1_121_ (
  .A({ new__183_ }),
  .ZN({ new__113_ })
);
OAI22_X1 #
) OAI22_X1_122_ (
  .A1({ new__36_ }),
  .A2({ new__112_ }),
  .B1({ new__113_ }),
  .B2({ new__132_ }),
  .ZN({ new__28_ })
);
OAI22_X1 #
) OAI22_X1_123_ (
  .A1({ new__36_ }),
  .A2({ new__113_ }),
  .B1({ new__132_ }),
  .B2({ new__101_ }),
  .ZN({ new__29_ })
);
OAI22_X1 #
) OAI22_X1_124_ (
  .A1({ new__36_ }),
  .A2({ new__101_ }),
  .B1({ new__132_ }),
  .B2({ new__102_ }),
  .ZN({ new__30_ })
);
OAI22_X1 #
) OAI22_X1_125_ (
  .A1({ new__36_ }),
  .A2({ new__102_ }),
  .B1({ new__132_ }),
  .B2({ new__106_ }),
  .ZN({ new__31_ })
);
INV_X1 #
) INV_X1_126_ (
  .A({ new__187_ }),
  .ZN({ new__114_ })
);
OAI22_X1 #
) OAI22_X1_127_ (
  .A1({ new__36_ }),
  .A2({ new__106_ }),
  .B1({ new__114_ }),
  .B2({ new__132_ }),
  .ZN({ new__32_ })
);
OAI22_X1 #
) OAI22_X1_128_ (
  .A1({ new__36_ }),
  .A2({ new__114_ }),
  .B1({ new__132_ }),
  .B2({ new__96_ }),
  .ZN({ new__33_ })
);
INV_X1 #
) INV_X1_129_ (
  .A({ reset }),
  .ZN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_130_ (
  .CK({ clock }),
  .D({ new__8_ }),
  .Q({ new__163_ }),
  .QN({ new__6_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_131_ (
  .CK({ clock }),
  .D({ new__9_ }),
  .Q({ new__164_ }),
  .QN({ new__133_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_132_ (
  .CK({ clock }),
  .D({ new__10_ }),
  .Q({ new__165_ }),
  .QN({ new__134_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_133_ (
  .CK({ clock }),
  .D({ new__11_ }),
  .Q({ new__166_ }),
  .QN({ new__135_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_134_ (
  .CK({ clock }),
  .D({ new__12_ }),
  .Q({ new__167_ }),
  .QN({ new__136_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_135_ (
  .CK({ clock }),
  .D({ new__13_ }),
  .Q({ new__168_ }),
  .QN({ new__137_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_136_ (
  .CK({ clock }),
  .D({ new__14_ }),
  .Q({ new__169_ }),
  .QN({ new__5_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_137_ (
  .CK({ clock }),
  .D({ new__15_ }),
  .Q({ new__170_ }),
  .QN({ new__138_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_138_ (
  .CK({ clock }),
  .D({ new__16_ }),
  .Q({ new__172_ }),
  .QN({ new__139_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_139_ (
  .CK({ clock }),
  .D({ new__17_ }),
  .Q({ new__173_ }),
  .QN({ new__140_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_140_ (
  .CK({ clock }),
  .D({ new__18_ }),
  .Q({ new__174_ }),
  .QN({ new__141_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_141_ (
  .CK({ clock }),
  .D({ new__19_ }),
  .Q({ new__175_ }),
  .QN({ new__142_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_142_ (
  .CK({ clock }),
  .D({ new__20_ }),
  .Q({ new__176_ }),
  .QN({ new__143_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_143_ (
  .CK({ clock }),
  .D({ new__21_ }),
  .Q({ new__177_ }),
  .QN({ new__144_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_144_ (
  .CK({ clock }),
  .D({ new__22_ }),
  .Q({ new__178_ }),
  .QN({ new__145_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_145_ (
  .CK({ clock }),
  .D({ new__23_ }),
  .Q({ new__179_ }),
  .QN({ new__146_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_146_ (
  .CK({ clock }),
  .D({ new__24_ }),
  .Q({ new__180_ }),
  .QN({ new__147_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_147_ (
  .CK({ clock }),
  .D({ new__25_ }),
  .Q({ new__171_ }),
  .QN({ new__148_ }),
  .RN({ new__7_ })
);
DFFS_X1 #
) DFFS_X1_148_ (
  .CK({ clock }),
  .D({ new__1_ }),
  .Q({ new_state_0 }),
  .QN({ new__0_ }),
  .SN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_149_ (
  .CK({ clock }),
  .D({ new__3_ }),
  .Q({ new_state_1 }),
  .QN({ new__149_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_150_ (
  .CK({ clock }),
  .D({ new__2_ }),
  .Q({ new_state_2 }),
  .QN({ new__150_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_151_ (
  .CK({ clock }),
  .D({ new__4_ }),
  .Q({ new_state_3 }),
  .QN({ new__151_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_152_ (
  .CK({ clock }),
  .D({ new_state_2 }),
  .Q({ new_state_4 }),
  .QN({ new__152_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_153_ (
  .CK({ clock }),
  .D({ new__26_ }),
  .Q({ new__181_ }),
  .QN({ new__153_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_154_ (
  .CK({ clock }),
  .D({ new__27_ }),
  .Q({ new__182_ }),
  .QN({ new__154_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_155_ (
  .CK({ clock }),
  .D({ new__28_ }),
  .Q({ new__183_ }),
  .QN({ new__155_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_156_ (
  .CK({ clock }),
  .D({ new__29_ }),
  .Q({ new__184_ }),
  .QN({ new__156_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_157_ (
  .CK({ clock }),
  .D({ new__30_ }),
  .Q({ new__185_ }),
  .QN({ new__157_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_158_ (
  .CK({ clock }),
  .D({ new__31_ }),
  .Q({ new__186_ }),
  .QN({ new__158_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_159_ (
  .CK({ clock }),
  .D({ new__32_ }),
  .Q({ new__187_ }),
  .QN({ new__159_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_160_ (
  .CK({ clock }),
  .D({ new__33_ }),
  .Q({ new__188_ }),
  .QN({ new__160_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_161_ (
  .CK({ clock }),
  .D({ start }),
  .Q({ new_startbuf_0 }),
  .QN({ new__161_ }),
  .RN({ new__7_ })
);
DFFR_X1 #
) DFFR_X1_162_ (
  .CK({ clock }),
  .D({ new_startbuf_0 }),
  .Q({ new_startbuf_1 }),
  .QN({ new__162_ }),
  .RN({ new__7_ })
);
BUF_X1 #
) BUF_X1_163_ (
  .A({ new__163_ }),
  .Z({ counter[0] })
);
BUF_X1 #
) BUF_X1_164_ (
  .A({ new__164_ }),
  .Z({ counter[1] })
);
BUF_X1 #
) BUF_X1_165_ (
  .A({ new__165_ }),
  .Z({ counter[2] })
);
BUF_X1 #
) BUF_X1_166_ (
  .A({ new__166_ }),
  .Z({ counter[3] })
);
BUF_X1 #
) BUF_X1_167_ (
  .A({ new__167_ }),
  .Z({ counter[4] })
);
BUF_X1 #
) BUF_X1_168_ (
  .A({ new__168_ }),
  .Z({ counter[5] })
);
BUF_X1 #
) BUF_X1_169_ (
  .A({ new__169_ }),
  .Z({ counter[6] })
);
BUF_X1 #
) BUF_X1_170_ (
  .A({ new__170_ }),
  .Z({ counter[7] })
);
BUF_X1 #
) BUF_X1_171_ (
  .A({ new__171_ }),
  .Z({ done })
);
BUF_X1 #
) BUF_X1_172_ (
  .A({ new__172_ }),
  .Z({ dp[0] })
);
BUF_X1 #
) BUF_X1_173_ (
  .A({ new__173_ }),
  .Z({ dp[1] })
);
BUF_X1 #
) BUF_X1_174_ (
  .A({ new__174_ }),
  .Z({ dp[2] })
);
BUF_X1 #
) BUF_X1_175_ (
  .A({ new__175_ }),
  .Z({ dp[3] })
);
BUF_X1 #
) BUF_X1_176_ (
  .A({ new__176_ }),
  .Z({ dp[4] })
);
BUF_X1 #
) BUF_X1_177_ (
  .A({ new__177_ }),
  .Z({ dp[5] })
);
BUF_X1 #
) BUF_X1_178_ (
  .A({ new__178_ }),
  .Z({ dp[6] })
);
BUF_X1 #
) BUF_X1_179_ (
  .A({ new__179_ }),
  .Z({ dp[7] })
);
BUF_X1 #
) BUF_X1_180_ (
  .A({ new__180_ }),
  .Z({ dp[8] })
);
BUF_X1 #
) BUF_X1_181_ (
  .A({ new__181_ }),
  .Z({ sr[0] })
);
BUF_X1 #
) BUF_X1_182_ (
  .A({ new__182_ }),
  .Z({ sr[1] })
);
BUF_X1 #
) BUF_X1_183_ (
  .A({ new__183_ }),
  .Z({ sr[2] })
);
BUF_X1 #
) BUF_X1_184_ (
  .A({ new__184_ }),
  .Z({ sr[3] })
);
BUF_X1 #
) BUF_X1_185_ (
  .A({ new__185_ }),
  .Z({ sr[4] })
);
BUF_X1 #
) BUF_X1_186_ (
  .A({ new__186_ }),
  .Z({ sr[5] })
);
BUF_X1 #
) BUF_X1_187_ (
  .A({ new__187_ }),
  .Z({ sr[6] })
);
BUF_X1 #
) BUF_X1_188_ (
  .A({ new__188_ }),
  .Z({ sr[7] })
);

endmodule