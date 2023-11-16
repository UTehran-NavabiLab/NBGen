module aftab_adder_subtractor(a, b, subsel, pass, cout, result);

wire S0;
wire S1;
wire S2;
wire S3;
wire S4;
wire S5;
wire S6;
wire S7;
wire S8;
wire S9;
wire S10;
wire S11;
wire S12;
wire S13;
wire S14;
wire S15;
wire S16;
wire S17;
wire S18;
wire S19;
wire S20;
wire S21;
wire S22;
wire S23;
wire S24;
wire S25;
wire S26;
wire S27;
wire S28;
wire S29;
wire S30;
wire S31;
wire S32;
wire S33;
wire S34;
wire S35;
wire S36;
wire S37;
wire S38;
wire S39;
wire S40;
wire S41;
wire S42;
wire S43;
wire S44;
wire S45;
wire S46;
wire S47;
wire S48;
wire S49;
wire S50;
wire S51;
wire S52;
wire S53;
wire S54;
wire S55;
wire S56;
wire S57;
wire S58;
wire S59;
wire S60;
wire S61;
wire S62;
wire S63;
wire S64;
wire S65;
wire S66;
wire S67;
wire S68;
wire S69;
wire S70;
wire S71;
wire S72;
wire S73;
wire S74;
wire S75;
wire S76;
wire S77;
wire S78;
wire S79;
wire S80;
wire S81;
wire S82;
wire S83;
wire S84;
wire S85;
wire S86;
wire S87;
wire S88;
wire S89;
wire S90;
wire S91;
wire S92;
wire S93;
wire S94;
wire S95;
wire S96;
wire S97;
wire S98;
wire S99;
wire S100;
wire S101;
wire S102;
wire S103;
wire S104;
wire S105;
wire S106;
wire S107;
wire S108;
wire S109;
wire S110;
wire S111;
wire S112;
wire S113;
wire S114;
wire S115;
wire S116;
wire S117;
wire S118;
wire S119;
wire S120;
wire S121;
wire S122;
wire S123;
wire S124;
wire S125;
wire S126;
wire S127;
wire S128;
wire S129;
wire S130;
wire S131;
wire S132;
wire S133;
wire addSubRes_0;
wire addSubRes_10;
wire addSubRes_11;
wire addSubRes_12;
wire addSubRes_13;
wire addSubRes_14;
wire addSubRes_15;
wire addSubRes_16;
wire addSubRes_17;
wire addSubRes_18;
wire addSubRes_19;
wire addSubRes_1;
wire addSubRes_20;
wire addSubRes_21;
wire addSubRes_22;
wire addSubRes_23;
wire addSubRes_24;
wire addSubRes_25;
wire addSubRes_26;
wire addSubRes_27;
wire addSubRes_28;
wire addSubRes_29;
wire addSubRes_2;
wire addSubRes_30;
wire addSubRes_31;
wire addSubRes_3;
wire addSubRes_4;
wire addSubRes_5;
wire addSubRes_6;
wire addSubRes_7;
wire addSubRes_8;
wire addSubRes_9;
wire bsel_0;
wire bsel_10;
wire bsel_11;
wire bsel_12;
wire bsel_13;
wire bsel_14;
wire bsel_15;
wire bsel_16;
wire bsel_17;
wire bsel_18;
wire bsel_19;
wire bsel_1;
wire bsel_20;
wire bsel_21;
wire bsel_22;
wire bsel_23;
wire bsel_24;
wire bsel_25;
wire bsel_26;
wire bsel_27;
wire bsel_28;
wire bsel_29;
wire bsel_2;
wire bsel_30;
wire bsel_31;
wire bsel_3;
wire bsel_4;
wire bsel_5;
wire bsel_6;
wire bsel_7;
wire bsel_8;
wire bsel_9;
input [31:0] a;input [31:0] b;input subsel;
input pass;
output cout;
output [31:0] result;
NOR2_X1 #() 
NOR2_X1_1_ (
  .A1({ S133 }),
  .A2({ S129[0] }),
  .ZN({ S0 })
);
AND2_X1 #() 
AND2_X1_1_ (
  .A1({ S129[0] }),
  .A2({ S133 }),
  .ZN({ S1 })
);
NOR2_X1 #() 
NOR2_X1_2_ (
  .A1({ S1 }),
  .A2({ S0 }),
  .ZN({ bsel_0 })
);
NOR2_X1 #() 
NOR2_X1_3_ (
  .A1({ S133 }),
  .A2({ S129[1] }),
  .ZN({ S2 })
);
AND2_X1 #() 
AND2_X1_2_ (
  .A1({ S129[1] }),
  .A2({ S133 }),
  .ZN({ S3 })
);
NOR2_X1 #() 
NOR2_X1_4_ (
  .A1({ S3 }),
  .A2({ S2 }),
  .ZN({ bsel_1 })
);
NOR2_X1 #() 
NOR2_X1_5_ (
  .A1({ S133 }),
  .A2({ S129[2] }),
  .ZN({ S4 })
);
AND2_X1 #() 
AND2_X1_3_ (
  .A1({ S129[2] }),
  .A2({ S133 }),
  .ZN({ S5 })
);
NOR2_X1 #() 
NOR2_X1_6_ (
  .A1({ S5 }),
  .A2({ S4 }),
  .ZN({ bsel_2 })
);
NOR2_X1 #() 
NOR2_X1_7_ (
  .A1({ S133 }),
  .A2({ S129[3] }),
  .ZN({ S6 })
);
AND2_X1 #() 
AND2_X1_4_ (
  .A1({ S129[3] }),
  .A2({ S133 }),
  .ZN({ S7 })
);
NOR2_X1 #() 
NOR2_X1_8_ (
  .A1({ S7 }),
  .A2({ S6 }),
  .ZN({ bsel_3 })
);
NOR2_X1 #() 
NOR2_X1_9_ (
  .A1({ S133 }),
  .A2({ S129[4] }),
  .ZN({ S8 })
);
AND2_X1 #() 
AND2_X1_5_ (
  .A1({ S129[4] }),
  .A2({ S133 }),
  .ZN({ S9 })
);
NOR2_X1 #() 
NOR2_X1_10_ (
  .A1({ S9 }),
  .A2({ S8 }),
  .ZN({ bsel_4 })
);
NOR2_X1 #() 
NOR2_X1_11_ (
  .A1({ S133 }),
  .A2({ S129[5] }),
  .ZN({ S10 })
);
AND2_X1 #() 
AND2_X1_6_ (
  .A1({ S129[5] }),
  .A2({ S133 }),
  .ZN({ S11 })
);
NOR2_X1 #() 
NOR2_X1_12_ (
  .A1({ S11 }),
  .A2({ S10 }),
  .ZN({ bsel_5 })
);
NOR2_X1 #() 
NOR2_X1_13_ (
  .A1({ S133 }),
  .A2({ S129[6] }),
  .ZN({ S12 })
);
AND2_X1 #() 
AND2_X1_7_ (
  .A1({ S129[6] }),
  .A2({ S133 }),
  .ZN({ S13 })
);
NOR2_X1 #() 
NOR2_X1_14_ (
  .A1({ S13 }),
  .A2({ S12 }),
  .ZN({ bsel_6 })
);
NOR2_X1 #() 
NOR2_X1_15_ (
  .A1({ S133 }),
  .A2({ S129[7] }),
  .ZN({ S14 })
);
AND2_X1 #() 
AND2_X1_8_ (
  .A1({ S129[7] }),
  .A2({ S133 }),
  .ZN({ S15 })
);
NOR2_X1 #() 
NOR2_X1_16_ (
  .A1({ S15 }),
  .A2({ S14 }),
  .ZN({ bsel_7 })
);
NOR2_X1 #() 
NOR2_X1_17_ (
  .A1({ S133 }),
  .A2({ S129[8] }),
  .ZN({ S16 })
);
AND2_X1 #() 
AND2_X1_9_ (
  .A1({ S129[8] }),
  .A2({ S133 }),
  .ZN({ S17 })
);
NOR2_X1 #() 
NOR2_X1_18_ (
  .A1({ S17 }),
  .A2({ S16 }),
  .ZN({ bsel_8 })
);
NOR2_X1 #() 
NOR2_X1_19_ (
  .A1({ S133 }),
  .A2({ S129[9] }),
  .ZN({ S18 })
);
AND2_X1 #() 
AND2_X1_10_ (
  .A1({ S129[9] }),
  .A2({ S133 }),
  .ZN({ S19 })
);
NOR2_X1 #() 
NOR2_X1_20_ (
  .A1({ S19 }),
  .A2({ S18 }),
  .ZN({ bsel_9 })
);
NOR2_X1 #() 
NOR2_X1_21_ (
  .A1({ S133 }),
  .A2({ S129[10] }),
  .ZN({ S20 })
);
AND2_X1 #() 
AND2_X1_11_ (
  .A1({ S129[10] }),
  .A2({ S133 }),
  .ZN({ S21 })
);
NOR2_X1 #() 
NOR2_X1_22_ (
  .A1({ S21 }),
  .A2({ S20 }),
  .ZN({ bsel_10 })
);
NOR2_X1 #() 
NOR2_X1_23_ (
  .A1({ S133 }),
  .A2({ S129[11] }),
  .ZN({ S22 })
);
AND2_X1 #() 
AND2_X1_12_ (
  .A1({ S129[11] }),
  .A2({ S133 }),
  .ZN({ S23 })
);
NOR2_X1 #() 
NOR2_X1_24_ (
  .A1({ S23 }),
  .A2({ S22 }),
  .ZN({ bsel_11 })
);
NOR2_X1 #() 
NOR2_X1_25_ (
  .A1({ S133 }),
  .A2({ S129[12] }),
  .ZN({ S24 })
);
AND2_X1 #() 
AND2_X1_13_ (
  .A1({ S129[12] }),
  .A2({ S133 }),
  .ZN({ S25 })
);
NOR2_X1 #() 
NOR2_X1_26_ (
  .A1({ S25 }),
  .A2({ S24 }),
  .ZN({ bsel_12 })
);
NOR2_X1 #() 
NOR2_X1_27_ (
  .A1({ S133 }),
  .A2({ S129[13] }),
  .ZN({ S26 })
);
AND2_X1 #() 
AND2_X1_14_ (
  .A1({ S129[13] }),
  .A2({ S133 }),
  .ZN({ S27 })
);
NOR2_X1 #() 
NOR2_X1_28_ (
  .A1({ S27 }),
  .A2({ S26 }),
  .ZN({ bsel_13 })
);
NOR2_X1 #() 
NOR2_X1_29_ (
  .A1({ S133 }),
  .A2({ S129[14] }),
  .ZN({ S28 })
);
AND2_X1 #() 
AND2_X1_15_ (
  .A1({ S129[14] }),
  .A2({ S133 }),
  .ZN({ S29 })
);
NOR2_X1 #() 
NOR2_X1_30_ (
  .A1({ S29 }),
  .A2({ S28 }),
  .ZN({ bsel_14 })
);
NOR2_X1 #() 
NOR2_X1_31_ (
  .A1({ S133 }),
  .A2({ S129[15] }),
  .ZN({ S30 })
);
AND2_X1 #() 
AND2_X1_16_ (
  .A1({ S129[15] }),
  .A2({ S133 }),
  .ZN({ S31 })
);
NOR2_X1 #() 
NOR2_X1_32_ (
  .A1({ S31 }),
  .A2({ S30 }),
  .ZN({ bsel_15 })
);
NOR2_X1 #() 
NOR2_X1_33_ (
  .A1({ S133 }),
  .A2({ S129[16] }),
  .ZN({ S32 })
);
AND2_X1 #() 
AND2_X1_17_ (
  .A1({ S129[16] }),
  .A2({ S133 }),
  .ZN({ S33 })
);
NOR2_X1 #() 
NOR2_X1_34_ (
  .A1({ S33 }),
  .A2({ S32 }),
  .ZN({ bsel_16 })
);
NOR2_X1 #() 
NOR2_X1_35_ (
  .A1({ S133 }),
  .A2({ S129[17] }),
  .ZN({ S34 })
);
AND2_X1 #() 
AND2_X1_18_ (
  .A1({ S129[17] }),
  .A2({ S133 }),
  .ZN({ S35 })
);
NOR2_X1 #() 
NOR2_X1_36_ (
  .A1({ S35 }),
  .A2({ S34 }),
  .ZN({ bsel_17 })
);
NOR2_X1 #() 
NOR2_X1_37_ (
  .A1({ S133 }),
  .A2({ S129[18] }),
  .ZN({ S36 })
);
AND2_X1 #() 
AND2_X1_19_ (
  .A1({ S129[18] }),
  .A2({ S133 }),
  .ZN({ S37 })
);
NOR2_X1 #() 
NOR2_X1_38_ (
  .A1({ S37 }),
  .A2({ S36 }),
  .ZN({ bsel_18 })
);
NOR2_X1 #() 
NOR2_X1_39_ (
  .A1({ S133 }),
  .A2({ S129[19] }),
  .ZN({ S38 })
);
AND2_X1 #() 
AND2_X1_20_ (
  .A1({ S129[19] }),
  .A2({ S133 }),
  .ZN({ S39 })
);
NOR2_X1 #() 
NOR2_X1_40_ (
  .A1({ S39 }),
  .A2({ S38 }),
  .ZN({ bsel_19 })
);
NOR2_X1 #() 
NOR2_X1_41_ (
  .A1({ S133 }),
  .A2({ S129[20] }),
  .ZN({ S40 })
);
AND2_X1 #() 
AND2_X1_21_ (
  .A1({ S129[20] }),
  .A2({ S133 }),
  .ZN({ S41 })
);
NOR2_X1 #() 
NOR2_X1_42_ (
  .A1({ S41 }),
  .A2({ S40 }),
  .ZN({ bsel_20 })
);
NOR2_X1 #() 
NOR2_X1_43_ (
  .A1({ S133 }),
  .A2({ S129[21] }),
  .ZN({ S42 })
);
AND2_X1 #() 
AND2_X1_22_ (
  .A1({ S129[21] }),
  .A2({ S133 }),
  .ZN({ S43 })
);
NOR2_X1 #() 
NOR2_X1_44_ (
  .A1({ S43 }),
  .A2({ S42 }),
  .ZN({ bsel_21 })
);
NOR2_X1 #() 
NOR2_X1_45_ (
  .A1({ S133 }),
  .A2({ S129[22] }),
  .ZN({ S44 })
);
AND2_X1 #() 
AND2_X1_23_ (
  .A1({ S129[22] }),
  .A2({ S133 }),
  .ZN({ S45 })
);
NOR2_X1 #() 
NOR2_X1_46_ (
  .A1({ S45 }),
  .A2({ S44 }),
  .ZN({ bsel_22 })
);
NOR2_X1 #() 
NOR2_X1_47_ (
  .A1({ S133 }),
  .A2({ S129[23] }),
  .ZN({ S46 })
);
AND2_X1 #() 
AND2_X1_24_ (
  .A1({ S129[23] }),
  .A2({ S133 }),
  .ZN({ S47 })
);
NOR2_X1 #() 
NOR2_X1_48_ (
  .A1({ S47 }),
  .A2({ S46 }),
  .ZN({ bsel_23 })
);
NOR2_X1 #() 
NOR2_X1_49_ (
  .A1({ S133 }),
  .A2({ S129[24] }),
  .ZN({ S48 })
);
AND2_X1 #() 
AND2_X1_25_ (
  .A1({ S129[24] }),
  .A2({ S133 }),
  .ZN({ S49 })
);
NOR2_X1 #() 
NOR2_X1_50_ (
  .A1({ S49 }),
  .A2({ S48 }),
  .ZN({ bsel_24 })
);
NOR2_X1 #() 
NOR2_X1_51_ (
  .A1({ S133 }),
  .A2({ S129[25] }),
  .ZN({ S50 })
);
AND2_X1 #() 
AND2_X1_26_ (
  .A1({ S129[25] }),
  .A2({ S133 }),
  .ZN({ S51 })
);
NOR2_X1 #() 
NOR2_X1_52_ (
  .A1({ S51 }),
  .A2({ S50 }),
  .ZN({ bsel_25 })
);
NOR2_X1 #() 
NOR2_X1_53_ (
  .A1({ S133 }),
  .A2({ S129[26] }),
  .ZN({ S52 })
);
AND2_X1 #() 
AND2_X1_27_ (
  .A1({ S129[26] }),
  .A2({ S133 }),
  .ZN({ S53 })
);
NOR2_X1 #() 
NOR2_X1_54_ (
  .A1({ S53 }),
  .A2({ S52 }),
  .ZN({ bsel_26 })
);
NOR2_X1 #() 
NOR2_X1_55_ (
  .A1({ S133 }),
  .A2({ S129[27] }),
  .ZN({ S54 })
);
AND2_X1 #() 
AND2_X1_28_ (
  .A1({ S129[27] }),
  .A2({ S133 }),
  .ZN({ S55 })
);
NOR2_X1 #() 
NOR2_X1_56_ (
  .A1({ S55 }),
  .A2({ S54 }),
  .ZN({ bsel_27 })
);
NOR2_X1 #() 
NOR2_X1_57_ (
  .A1({ S133 }),
  .A2({ S129[28] }),
  .ZN({ S56 })
);
AND2_X1 #() 
AND2_X1_29_ (
  .A1({ S129[28] }),
  .A2({ S133 }),
  .ZN({ S57 })
);
NOR2_X1 #() 
NOR2_X1_58_ (
  .A1({ S57 }),
  .A2({ S56 }),
  .ZN({ bsel_28 })
);
NOR2_X1 #() 
NOR2_X1_59_ (
  .A1({ S133 }),
  .A2({ S129[29] }),
  .ZN({ S58 })
);
AND2_X1 #() 
AND2_X1_30_ (
  .A1({ S129[29] }),
  .A2({ S133 }),
  .ZN({ S59 })
);
NOR2_X1 #() 
NOR2_X1_60_ (
  .A1({ S59 }),
  .A2({ S58 }),
  .ZN({ bsel_29 })
);
NOR2_X1 #() 
NOR2_X1_61_ (
  .A1({ S133 }),
  .A2({ S129[30] }),
  .ZN({ S60 })
);
AND2_X1 #() 
AND2_X1_31_ (
  .A1({ S129[30] }),
  .A2({ S133 }),
  .ZN({ S61 })
);
NOR2_X1 #() 
NOR2_X1_62_ (
  .A1({ S61 }),
  .A2({ S60 }),
  .ZN({ bsel_30 })
);
NOR2_X1 #() 
NOR2_X1_63_ (
  .A1({ S133 }),
  .A2({ S129[31] }),
  .ZN({ S62 })
);
AND2_X1 #() 
AND2_X1_32_ (
  .A1({ S129[31] }),
  .A2({ S133 }),
  .ZN({ S63 })
);
NOR2_X1 #() 
NOR2_X1_64_ (
  .A1({ S63 }),
  .A2({ S62 }),
  .ZN({ bsel_31 })
);
INV_X1 #() 
INV_X1_1_ (
  .A({ addSubRes_0 }),
  .ZN({ S64 })
);
NAND2_X1 #() 
NAND2_X1_1_ (
  .A1({ S129[0] }),
  .A2({ S131 }),
  .ZN({ S65 })
);
OAI21_X1 #() 
OAI21_X1_1_ (
  .A({ S65 }),
  .B1({ S64 }),
  .B2({ S131 }),
  .ZN({ S132[0] })
);
INV_X1 #() 
INV_X1_2_ (
  .A({ addSubRes_1 }),
  .ZN({ S66 })
);
NAND2_X1 #() 
NAND2_X1_2_ (
  .A1({ S129[1] }),
  .A2({ S131 }),
  .ZN({ S67 })
);
OAI21_X1 #() 
OAI21_X1_2_ (
  .A({ S67 }),
  .B1({ S66 }),
  .B2({ S131 }),
  .ZN({ S132[1] })
);
INV_X1 #() 
INV_X1_3_ (
  .A({ addSubRes_2 }),
  .ZN({ S68 })
);
NAND2_X1 #() 
NAND2_X1_3_ (
  .A1({ S129[2] }),
  .A2({ S131 }),
  .ZN({ S69 })
);
OAI21_X1 #() 
OAI21_X1_3_ (
  .A({ S69 }),
  .B1({ S68 }),
  .B2({ S131 }),
  .ZN({ S132[2] })
);
INV_X1 #() 
INV_X1_4_ (
  .A({ addSubRes_3 }),
  .ZN({ S70 })
);
NAND2_X1 #() 
NAND2_X1_4_ (
  .A1({ S129[3] }),
  .A2({ S131 }),
  .ZN({ S71 })
);
OAI21_X1 #() 
OAI21_X1_4_ (
  .A({ S71 }),
  .B1({ S70 }),
  .B2({ S131 }),
  .ZN({ S132[3] })
);
INV_X1 #() 
INV_X1_5_ (
  .A({ addSubRes_4 }),
  .ZN({ S72 })
);
NAND2_X1 #() 
NAND2_X1_5_ (
  .A1({ S129[4] }),
  .A2({ S131 }),
  .ZN({ S73 })
);
OAI21_X1 #() 
OAI21_X1_5_ (
  .A({ S73 }),
  .B1({ S72 }),
  .B2({ S131 }),
  .ZN({ S132[4] })
);
INV_X1 #() 
INV_X1_6_ (
  .A({ addSubRes_5 }),
  .ZN({ S74 })
);
NAND2_X1 #() 
NAND2_X1_6_ (
  .A1({ S129[5] }),
  .A2({ S131 }),
  .ZN({ S75 })
);
OAI21_X1 #() 
OAI21_X1_6_ (
  .A({ S75 }),
  .B1({ S74 }),
  .B2({ S131 }),
  .ZN({ S132[5] })
);
INV_X1 #() 
INV_X1_7_ (
  .A({ addSubRes_6 }),
  .ZN({ S76 })
);
NAND2_X1 #() 
NAND2_X1_7_ (
  .A1({ S129[6] }),
  .A2({ S131 }),
  .ZN({ S77 })
);
OAI21_X1 #() 
OAI21_X1_7_ (
  .A({ S77 }),
  .B1({ S76 }),
  .B2({ S131 }),
  .ZN({ S132[6] })
);
INV_X1 #() 
INV_X1_8_ (
  .A({ addSubRes_7 }),
  .ZN({ S78 })
);
NAND2_X1 #() 
NAND2_X1_8_ (
  .A1({ S129[7] }),
  .A2({ S131 }),
  .ZN({ S79 })
);
OAI21_X1 #() 
OAI21_X1_8_ (
  .A({ S79 }),
  .B1({ S78 }),
  .B2({ S131 }),
  .ZN({ S132[7] })
);
INV_X1 #() 
INV_X1_9_ (
  .A({ addSubRes_8 }),
  .ZN({ S80 })
);
NAND2_X1 #() 
NAND2_X1_9_ (
  .A1({ S129[8] }),
  .A2({ S131 }),
  .ZN({ S81 })
);
OAI21_X1 #() 
OAI21_X1_9_ (
  .A({ S81 }),
  .B1({ S80 }),
  .B2({ S131 }),
  .ZN({ S132[8] })
);
INV_X1 #() 
INV_X1_10_ (
  .A({ addSubRes_9 }),
  .ZN({ S82 })
);
NAND2_X1 #() 
NAND2_X1_10_ (
  .A1({ S129[9] }),
  .A2({ S131 }),
  .ZN({ S83 })
);
OAI21_X1 #() 
OAI21_X1_10_ (
  .A({ S83 }),
  .B1({ S82 }),
  .B2({ S131 }),
  .ZN({ S132[9] })
);
INV_X1 #() 
INV_X1_11_ (
  .A({ addSubRes_10 }),
  .ZN({ S84 })
);
NAND2_X1 #() 
NAND2_X1_11_ (
  .A1({ S129[10] }),
  .A2({ S131 }),
  .ZN({ S85 })
);
OAI21_X1 #() 
OAI21_X1_11_ (
  .A({ S85 }),
  .B1({ S84 }),
  .B2({ S131 }),
  .ZN({ S132[10] })
);
INV_X1 #() 
INV_X1_12_ (
  .A({ addSubRes_11 }),
  .ZN({ S86 })
);
NAND2_X1 #() 
NAND2_X1_12_ (
  .A1({ S129[11] }),
  .A2({ S131 }),
  .ZN({ S87 })
);
OAI21_X1 #() 
OAI21_X1_12_ (
  .A({ S87 }),
  .B1({ S86 }),
  .B2({ S131 }),
  .ZN({ S132[11] })
);
INV_X1 #() 
INV_X1_13_ (
  .A({ addSubRes_12 }),
  .ZN({ S88 })
);
NAND2_X1 #() 
NAND2_X1_13_ (
  .A1({ S129[12] }),
  .A2({ S131 }),
  .ZN({ S89 })
);
OAI21_X1 #() 
OAI21_X1_13_ (
  .A({ S89 }),
  .B1({ S88 }),
  .B2({ S131 }),
  .ZN({ S132[12] })
);
INV_X1 #() 
INV_X1_14_ (
  .A({ addSubRes_13 }),
  .ZN({ S90 })
);
NAND2_X1 #() 
NAND2_X1_14_ (
  .A1({ S129[13] }),
  .A2({ S131 }),
  .ZN({ S91 })
);
OAI21_X1 #() 
OAI21_X1_14_ (
  .A({ S91 }),
  .B1({ S90 }),
  .B2({ S131 }),
  .ZN({ S132[13] })
);
INV_X1 #() 
INV_X1_15_ (
  .A({ addSubRes_14 }),
  .ZN({ S92 })
);
NAND2_X1 #() 
NAND2_X1_15_ (
  .A1({ S129[14] }),
  .A2({ S131 }),
  .ZN({ S93 })
);
OAI21_X1 #() 
OAI21_X1_15_ (
  .A({ S93 }),
  .B1({ S92 }),
  .B2({ S131 }),
  .ZN({ S132[14] })
);
INV_X1 #() 
INV_X1_16_ (
  .A({ addSubRes_15 }),
  .ZN({ S94 })
);
NAND2_X1 #() 
NAND2_X1_16_ (
  .A1({ S129[15] }),
  .A2({ S131 }),
  .ZN({ S95 })
);
OAI21_X1 #() 
OAI21_X1_16_ (
  .A({ S95 }),
  .B1({ S94 }),
  .B2({ S131 }),
  .ZN({ S132[15] })
);
INV_X1 #() 
INV_X1_17_ (
  .A({ addSubRes_16 }),
  .ZN({ S96 })
);
NAND2_X1 #() 
NAND2_X1_17_ (
  .A1({ S129[16] }),
  .A2({ S131 }),
  .ZN({ S97 })
);
OAI21_X1 #() 
OAI21_X1_17_ (
  .A({ S97 }),
  .B1({ S96 }),
  .B2({ S131 }),
  .ZN({ S132[16] })
);
INV_X1 #() 
INV_X1_18_ (
  .A({ addSubRes_17 }),
  .ZN({ S98 })
);
NAND2_X1 #() 
NAND2_X1_18_ (
  .A1({ S129[17] }),
  .A2({ S131 }),
  .ZN({ S99 })
);
OAI21_X1 #() 
OAI21_X1_18_ (
  .A({ S99 }),
  .B1({ S98 }),
  .B2({ S131 }),
  .ZN({ S132[17] })
);
INV_X1 #() 
INV_X1_19_ (
  .A({ addSubRes_18 }),
  .ZN({ S100 })
);
NAND2_X1 #() 
NAND2_X1_19_ (
  .A1({ S129[18] }),
  .A2({ S131 }),
  .ZN({ S101 })
);
OAI21_X1 #() 
OAI21_X1_19_ (
  .A({ S101 }),
  .B1({ S100 }),
  .B2({ S131 }),
  .ZN({ S132[18] })
);
INV_X1 #() 
INV_X1_20_ (
  .A({ addSubRes_19 }),
  .ZN({ S102 })
);
NAND2_X1 #() 
NAND2_X1_20_ (
  .A1({ S129[19] }),
  .A2({ S131 }),
  .ZN({ S103 })
);
OAI21_X1 #() 
OAI21_X1_20_ (
  .A({ S103 }),
  .B1({ S102 }),
  .B2({ S131 }),
  .ZN({ S132[19] })
);
INV_X1 #() 
INV_X1_21_ (
  .A({ addSubRes_20 }),
  .ZN({ S104 })
);
NAND2_X1 #() 
NAND2_X1_21_ (
  .A1({ S129[20] }),
  .A2({ S131 }),
  .ZN({ S105 })
);
OAI21_X1 #() 
OAI21_X1_21_ (
  .A({ S105 }),
  .B1({ S104 }),
  .B2({ S131 }),
  .ZN({ S132[20] })
);
INV_X1 #() 
INV_X1_22_ (
  .A({ addSubRes_21 }),
  .ZN({ S106 })
);
NAND2_X1 #() 
NAND2_X1_22_ (
  .A1({ S129[21] }),
  .A2({ S131 }),
  .ZN({ S107 })
);
OAI21_X1 #() 
OAI21_X1_22_ (
  .A({ S107 }),
  .B1({ S106 }),
  .B2({ S131 }),
  .ZN({ S132[21] })
);
INV_X1 #() 
INV_X1_23_ (
  .A({ addSubRes_22 }),
  .ZN({ S108 })
);
NAND2_X1 #() 
NAND2_X1_23_ (
  .A1({ S129[22] }),
  .A2({ S131 }),
  .ZN({ S109 })
);
OAI21_X1 #() 
OAI21_X1_23_ (
  .A({ S109 }),
  .B1({ S108 }),
  .B2({ S131 }),
  .ZN({ S132[22] })
);
INV_X1 #() 
INV_X1_24_ (
  .A({ addSubRes_23 }),
  .ZN({ S110 })
);
NAND2_X1 #() 
NAND2_X1_24_ (
  .A1({ S129[23] }),
  .A2({ S131 }),
  .ZN({ S111 })
);
OAI21_X1 #() 
OAI21_X1_24_ (
  .A({ S111 }),
  .B1({ S110 }),
  .B2({ S131 }),
  .ZN({ S132[23] })
);
INV_X1 #() 
INV_X1_25_ (
  .A({ addSubRes_24 }),
  .ZN({ S112 })
);
NAND2_X1 #() 
NAND2_X1_25_ (
  .A1({ S129[24] }),
  .A2({ S131 }),
  .ZN({ S113 })
);
OAI21_X1 #() 
OAI21_X1_25_ (
  .A({ S113 }),
  .B1({ S112 }),
  .B2({ S131 }),
  .ZN({ S132[24] })
);
INV_X1 #() 
INV_X1_26_ (
  .A({ addSubRes_25 }),
  .ZN({ S114 })
);
NAND2_X1 #() 
NAND2_X1_26_ (
  .A1({ S129[25] }),
  .A2({ S131 }),
  .ZN({ S115 })
);
OAI21_X1 #() 
OAI21_X1_26_ (
  .A({ S115 }),
  .B1({ S114 }),
  .B2({ S131 }),
  .ZN({ S132[25] })
);
INV_X1 #() 
INV_X1_27_ (
  .A({ addSubRes_26 }),
  .ZN({ S116 })
);
NAND2_X1 #() 
NAND2_X1_27_ (
  .A1({ S129[26] }),
  .A2({ S131 }),
  .ZN({ S117 })
);
OAI21_X1 #() 
OAI21_X1_27_ (
  .A({ S117 }),
  .B1({ S116 }),
  .B2({ S131 }),
  .ZN({ S132[26] })
);
INV_X1 #() 
INV_X1_28_ (
  .A({ addSubRes_27 }),
  .ZN({ S118 })
);
NAND2_X1 #() 
NAND2_X1_28_ (
  .A1({ S129[27] }),
  .A2({ S131 }),
  .ZN({ S119 })
);
OAI21_X1 #() 
OAI21_X1_28_ (
  .A({ S119 }),
  .B1({ S118 }),
  .B2({ S131 }),
  .ZN({ S132[27] })
);
INV_X1 #() 
INV_X1_29_ (
  .A({ addSubRes_28 }),
  .ZN({ S120 })
);
NAND2_X1 #() 
NAND2_X1_29_ (
  .A1({ S129[28] }),
  .A2({ S131 }),
  .ZN({ S121 })
);
OAI21_X1 #() 
OAI21_X1_29_ (
  .A({ S121 }),
  .B1({ S120 }),
  .B2({ S131 }),
  .ZN({ S132[28] })
);
INV_X1 #() 
INV_X1_30_ (
  .A({ addSubRes_29 }),
  .ZN({ S122 })
);
NAND2_X1 #() 
NAND2_X1_30_ (
  .A1({ S129[29] }),
  .A2({ S131 }),
  .ZN({ S123 })
);
OAI21_X1 #() 
OAI21_X1_30_ (
  .A({ S123 }),
  .B1({ S122 }),
  .B2({ S131 }),
  .ZN({ S132[29] })
);
INV_X1 #() 
INV_X1_31_ (
  .A({ addSubRes_30 }),
  .ZN({ S124 })
);
NAND2_X1 #() 
NAND2_X1_31_ (
  .A1({ S129[30] }),
  .A2({ S131 }),
  .ZN({ S125 })
);
OAI21_X1 #() 
OAI21_X1_31_ (
  .A({ S125 }),
  .B1({ S124 }),
  .B2({ S131 }),
  .ZN({ S132[30] })
);
INV_X1 #() 
INV_X1_32_ (
  .A({ addSubRes_31 }),
  .ZN({ S126 })
);
NAND2_X1 #() 
NAND2_X1_32_ (
  .A1({ S129[31] }),
  .A2({ S131 }),
  .ZN({ S127 })
);
OAI21_X1 #() 
OAI21_X1_32_ (
  .A({ S127 }),
  .B1({ S126 }),
  .B2({ S131 }),
  .ZN({ S132[31] })
);
BUF_X1 #() 
BUF_X1_1_ (
  .A({ a[0] }),
  .Z({ S128[0] })
);
BUF_X1 #() 
BUF_X1_2_ (
  .A({ a[1] }),
  .Z({ S128[1] })
);
BUF_X1 #() 
BUF_X1_3_ (
  .A({ a[10] }),
  .Z({ S128[10] })
);
BUF_X1 #() 
BUF_X1_4_ (
  .A({ a[11] }),
  .Z({ S128[11] })
);
BUF_X1 #() 
BUF_X1_5_ (
  .A({ a[12] }),
  .Z({ S128[12] })
);
BUF_X1 #() 
BUF_X1_6_ (
  .A({ a[13] }),
  .Z({ S128[13] })
);
BUF_X1 #() 
BUF_X1_7_ (
  .A({ a[14] }),
  .Z({ S128[14] })
);
BUF_X1 #() 
BUF_X1_8_ (
  .A({ a[15] }),
  .Z({ S128[15] })
);
BUF_X1 #() 
BUF_X1_9_ (
  .A({ a[16] }),
  .Z({ S128[16] })
);
BUF_X1 #() 
BUF_X1_10_ (
  .A({ a[17] }),
  .Z({ S128[17] })
);
BUF_X1 #() 
BUF_X1_11_ (
  .A({ a[18] }),
  .Z({ S128[18] })
);
BUF_X1 #() 
BUF_X1_12_ (
  .A({ a[19] }),
  .Z({ S128[19] })
);
BUF_X1 #() 
BUF_X1_13_ (
  .A({ a[2] }),
  .Z({ S128[2] })
);
BUF_X1 #() 
BUF_X1_14_ (
  .A({ a[20] }),
  .Z({ S128[20] })
);
BUF_X1 #() 
BUF_X1_15_ (
  .A({ a[21] }),
  .Z({ S128[21] })
);
BUF_X1 #() 
BUF_X1_16_ (
  .A({ a[22] }),
  .Z({ S128[22] })
);
BUF_X1 #() 
BUF_X1_17_ (
  .A({ a[23] }),
  .Z({ S128[23] })
);
BUF_X1 #() 
BUF_X1_18_ (
  .A({ a[24] }),
  .Z({ S128[24] })
);
BUF_X1 #() 
BUF_X1_19_ (
  .A({ a[25] }),
  .Z({ S128[25] })
);
BUF_X1 #() 
BUF_X1_20_ (
  .A({ a[26] }),
  .Z({ S128[26] })
);
BUF_X1 #() 
BUF_X1_21_ (
  .A({ a[27] }),
  .Z({ S128[27] })
);
BUF_X1 #() 
BUF_X1_22_ (
  .A({ a[28] }),
  .Z({ S128[28] })
);
BUF_X1 #() 
BUF_X1_23_ (
  .A({ a[29] }),
  .Z({ S128[29] })
);
BUF_X1 #() 
BUF_X1_24_ (
  .A({ a[3] }),
  .Z({ S128[3] })
);
BUF_X1 #() 
BUF_X1_25_ (
  .A({ a[30] }),
  .Z({ S128[30] })
);
BUF_X1 #() 
BUF_X1_26_ (
  .A({ a[31] }),
  .Z({ S128[31] })
);
BUF_X1 #() 
BUF_X1_27_ (
  .A({ a[4] }),
  .Z({ S128[4] })
);
BUF_X1 #() 
BUF_X1_28_ (
  .A({ a[5] }),
  .Z({ S128[5] })
);
BUF_X1 #() 
BUF_X1_29_ (
  .A({ a[6] }),
  .Z({ S128[6] })
);
BUF_X1 #() 
BUF_X1_30_ (
  .A({ a[7] }),
  .Z({ S128[7] })
);
BUF_X1 #() 
BUF_X1_31_ (
  .A({ a[8] }),
  .Z({ S128[8] })
);
BUF_X1 #() 
BUF_X1_32_ (
  .A({ a[9] }),
  .Z({ S128[9] })
);
BUF_X1 #() 
BUF_X1_33_ (
  .A({ b[0] }),
  .Z({ S129[0] })
);
BUF_X1 #() 
BUF_X1_34_ (
  .A({ b[1] }),
  .Z({ S129[1] })
);
BUF_X1 #() 
BUF_X1_35_ (
  .A({ b[10] }),
  .Z({ S129[10] })
);
BUF_X1 #() 
BUF_X1_36_ (
  .A({ b[11] }),
  .Z({ S129[11] })
);
BUF_X1 #() 
BUF_X1_37_ (
  .A({ b[12] }),
  .Z({ S129[12] })
);
BUF_X1 #() 
BUF_X1_38_ (
  .A({ b[13] }),
  .Z({ S129[13] })
);
BUF_X1 #() 
BUF_X1_39_ (
  .A({ b[14] }),
  .Z({ S129[14] })
);
BUF_X1 #() 
BUF_X1_40_ (
  .A({ b[15] }),
  .Z({ S129[15] })
);
BUF_X1 #() 
BUF_X1_41_ (
  .A({ b[16] }),
  .Z({ S129[16] })
);
BUF_X1 #() 
BUF_X1_42_ (
  .A({ b[17] }),
  .Z({ S129[17] })
);
BUF_X1 #() 
BUF_X1_43_ (
  .A({ b[18] }),
  .Z({ S129[18] })
);
BUF_X1 #() 
BUF_X1_44_ (
  .A({ b[19] }),
  .Z({ S129[19] })
);
BUF_X1 #() 
BUF_X1_45_ (
  .A({ b[2] }),
  .Z({ S129[2] })
);
BUF_X1 #() 
BUF_X1_46_ (
  .A({ b[20] }),
  .Z({ S129[20] })
);
BUF_X1 #() 
BUF_X1_47_ (
  .A({ b[21] }),
  .Z({ S129[21] })
);
BUF_X1 #() 
BUF_X1_48_ (
  .A({ b[22] }),
  .Z({ S129[22] })
);
BUF_X1 #() 
BUF_X1_49_ (
  .A({ b[23] }),
  .Z({ S129[23] })
);
BUF_X1 #() 
BUF_X1_50_ (
  .A({ b[24] }),
  .Z({ S129[24] })
);
BUF_X1 #() 
BUF_X1_51_ (
  .A({ b[25] }),
  .Z({ S129[25] })
);
BUF_X1 #() 
BUF_X1_52_ (
  .A({ b[26] }),
  .Z({ S129[26] })
);
BUF_X1 #() 
BUF_X1_53_ (
  .A({ b[27] }),
  .Z({ S129[27] })
);
BUF_X1 #() 
BUF_X1_54_ (
  .A({ b[28] }),
  .Z({ S129[28] })
);
BUF_X1 #() 
BUF_X1_55_ (
  .A({ b[29] }),
  .Z({ S129[29] })
);
BUF_X1 #() 
BUF_X1_56_ (
  .A({ b[3] }),
  .Z({ S129[3] })
);
BUF_X1 #() 
BUF_X1_57_ (
  .A({ b[30] }),
  .Z({ S129[30] })
);
BUF_X1 #() 
BUF_X1_58_ (
  .A({ b[31] }),
  .Z({ S129[31] })
);
BUF_X1 #() 
BUF_X1_59_ (
  .A({ b[4] }),
  .Z({ S129[4] })
);
BUF_X1 #() 
BUF_X1_60_ (
  .A({ b[5] }),
  .Z({ S129[5] })
);
BUF_X1 #() 
BUF_X1_61_ (
  .A({ b[6] }),
  .Z({ S129[6] })
);
BUF_X1 #() 
BUF_X1_62_ (
  .A({ b[7] }),
  .Z({ S129[7] })
);
BUF_X1 #() 
BUF_X1_63_ (
  .A({ b[8] }),
  .Z({ S129[8] })
);
BUF_X1 #() 
BUF_X1_64_ (
  .A({ b[9] }),
  .Z({ S129[9] })
);
BUF_X1 #() 
BUF_X1_65_ (
  .A({ S130 }),
  .Z({ cout })
);
BUF_X1 #() 
BUF_X1_66_ (
  .A({ pass }),
  .Z({ S131 })
);
BUF_X1 #() 
BUF_X1_67_ (
  .A({ S132[0] }),
  .Z({ result[0] })
);
BUF_X1 #() 
BUF_X1_68_ (
  .A({ S132[1] }),
  .Z({ result[1] })
);
BUF_X1 #() 
BUF_X1_69_ (
  .A({ S132[10] }),
  .Z({ result[10] })
);
BUF_X1 #() 
BUF_X1_70_ (
  .A({ S132[11] }),
  .Z({ result[11] })
);
BUF_X1 #() 
BUF_X1_71_ (
  .A({ S132[12] }),
  .Z({ result[12] })
);
BUF_X1 #() 
BUF_X1_72_ (
  .A({ S132[13] }),
  .Z({ result[13] })
);
BUF_X1 #() 
BUF_X1_73_ (
  .A({ S132[14] }),
  .Z({ result[14] })
);
BUF_X1 #() 
BUF_X1_74_ (
  .A({ S132[15] }),
  .Z({ result[15] })
);
BUF_X1 #() 
BUF_X1_75_ (
  .A({ S132[16] }),
  .Z({ result[16] })
);
BUF_X1 #() 
BUF_X1_76_ (
  .A({ S132[17] }),
  .Z({ result[17] })
);
BUF_X1 #() 
BUF_X1_77_ (
  .A({ S132[18] }),
  .Z({ result[18] })
);
BUF_X1 #() 
BUF_X1_78_ (
  .A({ S132[19] }),
  .Z({ result[19] })
);
BUF_X1 #() 
BUF_X1_79_ (
  .A({ S132[2] }),
  .Z({ result[2] })
);
BUF_X1 #() 
BUF_X1_80_ (
  .A({ S132[20] }),
  .Z({ result[20] })
);
BUF_X1 #() 
BUF_X1_81_ (
  .A({ S132[21] }),
  .Z({ result[21] })
);
BUF_X1 #() 
BUF_X1_82_ (
  .A({ S132[22] }),
  .Z({ result[22] })
);
BUF_X1 #() 
BUF_X1_83_ (
  .A({ S132[23] }),
  .Z({ result[23] })
);
BUF_X1 #() 
BUF_X1_84_ (
  .A({ S132[24] }),
  .Z({ result[24] })
);
BUF_X1 #() 
BUF_X1_85_ (
  .A({ S132[25] }),
  .Z({ result[25] })
);
BUF_X1 #() 
BUF_X1_86_ (
  .A({ S132[26] }),
  .Z({ result[26] })
);
BUF_X1 #() 
BUF_X1_87_ (
  .A({ S132[27] }),
  .Z({ result[27] })
);
BUF_X1 #() 
BUF_X1_88_ (
  .A({ S132[28] }),
  .Z({ result[28] })
);
BUF_X1 #() 
BUF_X1_89_ (
  .A({ S132[29] }),
  .Z({ result[29] })
);
BUF_X1 #() 
BUF_X1_90_ (
  .A({ S132[3] }),
  .Z({ result[3] })
);
BUF_X1 #() 
BUF_X1_91_ (
  .A({ S132[30] }),
  .Z({ result[30] })
);
BUF_X1 #() 
BUF_X1_92_ (
  .A({ S132[31] }),
  .Z({ result[31] })
);
BUF_X1 #() 
BUF_X1_93_ (
  .A({ S132[4] }),
  .Z({ result[4] })
);
BUF_X1 #() 
BUF_X1_94_ (
  .A({ S132[5] }),
  .Z({ result[5] })
);
BUF_X1 #() 
BUF_X1_95_ (
  .A({ S132[6] }),
  .Z({ result[6] })
);
BUF_X1 #() 
BUF_X1_96_ (
  .A({ S132[7] }),
  .Z({ result[7] })
);
BUF_X1 #() 
BUF_X1_97_ (
  .A({ S132[8] }),
  .Z({ result[8] })
);
BUF_X1 #() 
BUF_X1_98_ (
  .A({ S132[9] }),
  .Z({ result[9] })
);
BUF_X1 #() 
BUF_X1_99_ (
  .A({ subsel }),
  .Z({ S133 })
);
$paramod\aftab_adder\size=s32'00000000000000000000000000100000 #() 
$paramod\aftab_adder\size=s32'00000000000000000000000000100000_1_ (
  .a({ S128[0], S128[1], S128[2], S128[3], S128[4], S128[5], S128[6], S128[7], S128[8], S128[9], S128[10], S128[11], S128[12], S128[13], S128[14], S128[15], S128[16], S128[17], S128[18], S128[19], S128[20], S128[21], S128[22], S128[23], S128[24], S128[25], S128[26], S128[27], S128[28], S128[29], S128[30], S128[31] }),
  .b({ bsel_0, bsel_1, bsel_2, bsel_3, bsel_4, bsel_5, bsel_6, bsel_7, bsel_8, bsel_9, bsel_10, bsel_11, bsel_12, bsel_13, bsel_14, bsel_15, bsel_16, bsel_17, bsel_18, bsel_19, bsel_20, bsel_21, bsel_22, bsel_23, bsel_24, bsel_25, bsel_26, bsel_27, bsel_28, bsel_29, bsel_30, bsel_31 }),
  .cin({ S133 }),
  .cout({ S130 }),
  .sum({ addSubRes_0, addSubRes_1, addSubRes_2, addSubRes_3, addSubRes_4, addSubRes_5, addSubRes_6, addSubRes_7, addSubRes_8, addSubRes_9, addSubRes_10, addSubRes_11, addSubRes_12, addSubRes_13, addSubRes_14, addSubRes_15, addSubRes_16, addSubRes_17, addSubRes_18, addSubRes_19, addSubRes_20, addSubRes_21, addSubRes_22, addSubRes_23, addSubRes_24, addSubRes_25, addSubRes_26, addSubRes_27, addSubRes_28, addSubRes_29, addSubRes_30, addSubRes_31 })
);

endmodule