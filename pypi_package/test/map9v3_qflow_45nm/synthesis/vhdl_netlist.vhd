LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY map9v3 IS
    PORT (
        clock : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        start : IN STD_LOGIC;
        N : IN STD_LOGIC_VECTOR (8 DOWNTO 0);
        dp : OUT STD_LOGIC_VECTOR (8 DOWNTO 0);
        done : OUT STD_LOGIC;
        counter : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);
        sr : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
END ENTITY map9v3;

ARCHITECTURE arch OF map9v3 IS
    SIGNAL new__0_ : STD_LOGIC;
    SIGNAL new__100_ : STD_LOGIC;
    SIGNAL new__101_ : STD_LOGIC;
    SIGNAL new__102_ : STD_LOGIC;
    SIGNAL new__103_ : STD_LOGIC;
    SIGNAL new__104_ : STD_LOGIC;
    SIGNAL new__105_ : STD_LOGIC;
    SIGNAL new__106_ : STD_LOGIC;
    SIGNAL new__107_ : STD_LOGIC;
    SIGNAL new__108_ : STD_LOGIC;
    SIGNAL new__109_ : STD_LOGIC;
    SIGNAL new__10_ : STD_LOGIC;
    SIGNAL new__110_ : STD_LOGIC;
    SIGNAL new__111_ : STD_LOGIC;
    SIGNAL new__112_ : STD_LOGIC;
    SIGNAL new__113_ : STD_LOGIC;
    SIGNAL new__114_ : STD_LOGIC;
    SIGNAL new__115_ : STD_LOGIC;
    SIGNAL new__116_ : STD_LOGIC;
    SIGNAL new__117_ : STD_LOGIC;
    SIGNAL new__118_ : STD_LOGIC;
    SIGNAL new__119_ : STD_LOGIC;
    SIGNAL new__11_ : STD_LOGIC;
    SIGNAL new__120_ : STD_LOGIC;
    SIGNAL new__121_ : STD_LOGIC;
    SIGNAL new__122_ : STD_LOGIC;
    SIGNAL new__123_ : STD_LOGIC;
    SIGNAL new__124_ : STD_LOGIC;
    SIGNAL new__125_ : STD_LOGIC;
    SIGNAL new__126_ : STD_LOGIC;
    SIGNAL new__127_ : STD_LOGIC;
    SIGNAL new__128_ : STD_LOGIC;
    SIGNAL new__129_ : STD_LOGIC;
    SIGNAL new__12_ : STD_LOGIC;
    SIGNAL new__130_ : STD_LOGIC;
    SIGNAL new__131_ : STD_LOGIC;
    SIGNAL new__132_ : STD_LOGIC;
    SIGNAL new__133_ : STD_LOGIC;
    SIGNAL new__134_ : STD_LOGIC;
    SIGNAL new__135_ : STD_LOGIC;
    SIGNAL new__136_ : STD_LOGIC;
    SIGNAL new__137_ : STD_LOGIC;
    SIGNAL new__138_ : STD_LOGIC;
    SIGNAL new__139_ : STD_LOGIC;
    SIGNAL new__13_ : STD_LOGIC;
    SIGNAL new__140_ : STD_LOGIC;
    SIGNAL new__141_ : STD_LOGIC;
    SIGNAL new__142_ : STD_LOGIC;
    SIGNAL new__143_ : STD_LOGIC;
    SIGNAL new__144_ : STD_LOGIC;
    SIGNAL new__145_ : STD_LOGIC;
    SIGNAL new__146_ : STD_LOGIC;
    SIGNAL new__147_ : STD_LOGIC;
    SIGNAL new__148_ : STD_LOGIC;
    SIGNAL new__149_ : STD_LOGIC;
    SIGNAL new__14_ : STD_LOGIC;
    SIGNAL new__150_ : STD_LOGIC;
    SIGNAL new__151_ : STD_LOGIC;
    SIGNAL new__152_ : STD_LOGIC;
    SIGNAL new__153_ : STD_LOGIC;
    SIGNAL new__154_ : STD_LOGIC;
    SIGNAL new__155_ : STD_LOGIC;
    SIGNAL new__156_ : STD_LOGIC;
    SIGNAL new__157_ : STD_LOGIC;
    SIGNAL new__158_ : STD_LOGIC;
    SIGNAL new__159_ : STD_LOGIC;
    SIGNAL new__15_ : STD_LOGIC;
    SIGNAL new__160_ : STD_LOGIC;
    SIGNAL new__161_ : STD_LOGIC;
    SIGNAL new__162_ : STD_LOGIC;
    SIGNAL new__163_ : STD_LOGIC;
    SIGNAL new__164_ : STD_LOGIC;
    SIGNAL new__165_ : STD_LOGIC;
    SIGNAL new__166_ : STD_LOGIC;
    SIGNAL new__167_ : STD_LOGIC;
    SIGNAL new__168_ : STD_LOGIC;
    SIGNAL new__169_ : STD_LOGIC;
    SIGNAL new__16_ : STD_LOGIC;
    SIGNAL new__170_ : STD_LOGIC;
    SIGNAL new__171_ : STD_LOGIC;
    SIGNAL new__172_ : STD_LOGIC;
    SIGNAL new__173_ : STD_LOGIC;
    SIGNAL new__174_ : STD_LOGIC;
    SIGNAL new__175_ : STD_LOGIC;
    SIGNAL new__176_ : STD_LOGIC;
    SIGNAL new__177_ : STD_LOGIC;
    SIGNAL new__178_ : STD_LOGIC;
    SIGNAL new__179_ : STD_LOGIC;
    SIGNAL new__17_ : STD_LOGIC;
    SIGNAL new__180_ : STD_LOGIC;
    SIGNAL new__181_ : STD_LOGIC;
    SIGNAL new__182_ : STD_LOGIC;
    SIGNAL new__183_ : STD_LOGIC;
    SIGNAL new__184_ : STD_LOGIC;
    SIGNAL new__185_ : STD_LOGIC;
    SIGNAL new__186_ : STD_LOGIC;
    SIGNAL new__187_ : STD_LOGIC;
    SIGNAL new__188_ : STD_LOGIC;
    SIGNAL new__18_ : STD_LOGIC;
    SIGNAL new__19_ : STD_LOGIC;
    SIGNAL new__1_ : STD_LOGIC;
    SIGNAL new__20_ : STD_LOGIC;
    SIGNAL new__21_ : STD_LOGIC;
    SIGNAL new__22_ : STD_LOGIC;
    SIGNAL new__23_ : STD_LOGIC;
    SIGNAL new__24_ : STD_LOGIC;
    SIGNAL new__25_ : STD_LOGIC;
    SIGNAL new__26_ : STD_LOGIC;
    SIGNAL new__27_ : STD_LOGIC;
    SIGNAL new__28_ : STD_LOGIC;
    SIGNAL new__29_ : STD_LOGIC;
    SIGNAL new__2_ : STD_LOGIC;
    SIGNAL new__30_ : STD_LOGIC;
    SIGNAL new__31_ : STD_LOGIC;
    SIGNAL new__32_ : STD_LOGIC;
    SIGNAL new__33_ : STD_LOGIC;
    SIGNAL new__34_ : STD_LOGIC;
    SIGNAL new__35_ : STD_LOGIC;
    SIGNAL new__36_ : STD_LOGIC;
    SIGNAL new__37_ : STD_LOGIC;
    SIGNAL new__38_ : STD_LOGIC;
    SIGNAL new__39_ : STD_LOGIC;
    SIGNAL new__3_ : STD_LOGIC;
    SIGNAL new__40_ : STD_LOGIC;
    SIGNAL new__41_ : STD_LOGIC;
    SIGNAL new__42_ : STD_LOGIC;
    SIGNAL new__43_ : STD_LOGIC;
    SIGNAL new__44_ : STD_LOGIC;
    SIGNAL new__45_ : STD_LOGIC;
    SIGNAL new__46_ : STD_LOGIC;
    SIGNAL new__47_ : STD_LOGIC;
    SIGNAL new__48_ : STD_LOGIC;
    SIGNAL new__49_ : STD_LOGIC;
    SIGNAL new__4_ : STD_LOGIC;
    SIGNAL new__50_ : STD_LOGIC;
    SIGNAL new__51_ : STD_LOGIC;
    SIGNAL new__52_ : STD_LOGIC;
    SIGNAL new__53_ : STD_LOGIC;
    SIGNAL new__54_ : STD_LOGIC;
    SIGNAL new__55_ : STD_LOGIC;
    SIGNAL new__56_ : STD_LOGIC;
    SIGNAL new__57_ : STD_LOGIC;
    SIGNAL new__58_ : STD_LOGIC;
    SIGNAL new__59_ : STD_LOGIC;
    SIGNAL new__5_ : STD_LOGIC;
    SIGNAL new__60_ : STD_LOGIC;
    SIGNAL new__61_ : STD_LOGIC;
    SIGNAL new__62_ : STD_LOGIC;
    SIGNAL new__63_ : STD_LOGIC;
    SIGNAL new__64_ : STD_LOGIC;
    SIGNAL new__65_ : STD_LOGIC;
    SIGNAL new__66_ : STD_LOGIC;
    SIGNAL new__67_ : STD_LOGIC;
    SIGNAL new__68_ : STD_LOGIC;
    SIGNAL new__69_ : STD_LOGIC;
    SIGNAL new__6_ : STD_LOGIC;
    SIGNAL new__70_ : STD_LOGIC;
    SIGNAL new__71_ : STD_LOGIC;
    SIGNAL new__72_ : STD_LOGIC;
    SIGNAL new__73_ : STD_LOGIC;
    SIGNAL new__74_ : STD_LOGIC;
    SIGNAL new__75_ : STD_LOGIC;
    SIGNAL new__76_ : STD_LOGIC;
    SIGNAL new__77_ : STD_LOGIC;
    SIGNAL new__78_ : STD_LOGIC;
    SIGNAL new__79_ : STD_LOGIC;
    SIGNAL new__7_ : STD_LOGIC;
    SIGNAL new__80_ : STD_LOGIC;
    SIGNAL new__81_ : STD_LOGIC;
    SIGNAL new__82_ : STD_LOGIC;
    SIGNAL new__83_ : STD_LOGIC;
    SIGNAL new__84_ : STD_LOGIC;
    SIGNAL new__85_ : STD_LOGIC;
    SIGNAL new__86_ : STD_LOGIC;
    SIGNAL new__87_ : STD_LOGIC;
    SIGNAL new__88_ : STD_LOGIC;
    SIGNAL new__89_ : STD_LOGIC;
    SIGNAL new__8_ : STD_LOGIC;
    SIGNAL new__90_ : STD_LOGIC;
    SIGNAL new__91_ : STD_LOGIC;
    SIGNAL new__92_ : STD_LOGIC;
    SIGNAL new__93_ : STD_LOGIC;
    SIGNAL new__94_ : STD_LOGIC;
    SIGNAL new__95_ : STD_LOGIC;
    SIGNAL new__96_ : STD_LOGIC;
    SIGNAL new__97_ : STD_LOGIC;
    SIGNAL new__98_ : STD_LOGIC;
    SIGNAL new__99_ : STD_LOGIC;
    SIGNAL new__9_ : STD_LOGIC;
    SIGNAL new_startbuf_0 : STD_LOGIC;
    SIGNAL new_startbuf_1 : STD_LOGIC;
    SIGNAL new_state_0 : STD_LOGIC;
    SIGNAL new_state_1 : STD_LOGIC;
    SIGNAL new_state_2 : STD_LOGIC;
    SIGNAL new_state_3 : STD_LOGIC;
    SIGNAL new_state_4 : STD_LOGIC;

BEGIN
INV_X1_0: ENTITY WORK.INV_X1
    PORT MAP (
        A => new_state_0,
        ZN => new__115_
    );
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__168_,
        ZN => new__116_
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__169_,
        ZN => new__117_
    );
INV_X1_3: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__170_,
        ZN => new__118_
    );
INV_X1_4: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__167_,
        ZN => new__119_
    );
NOR2_X1_5: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__164_,
        A2 => new__163_,
        ZN => new__120_
    );
NOR2_X1_6: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__166_,
        A2 => new__165_,
        ZN => new__121_
    );
AND3_X1_7: ENTITY WORK.AND3_X1
    PORT MAP (
        A1 => new__121_,
        A2 => new__120_,
        A3 => new__119_,
        ZN => new__122_
    );
NAND4_X1_8: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => new__122_,
        A2 => new__118_,
        A3 => new__117_,
        A4 => new__116_,
        ZN => new__123_
    );
NAND2_X1_9: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__123_,
        A2 => new_state_3,
        ZN => new__124_
    );
NAND2_X1_10: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__124_,
        A2 => new__115_,
        ZN => new__4_
    );
INV_X1_11: ENTITY WORK.INV_X1
    PORT MAP (
        A => new_state_4,
        ZN => new__125_
    );
INV_X1_12: ENTITY WORK.INV_X1
    PORT MAP (
        A => new_startbuf_0,
        ZN => new__126_
    );
OAI21_X1_13: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => new_state_1,
        B1 => new__126_,
        B2 => new_startbuf_1,
        ZN => new__127_
    );
NAND2_X1_14: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__127_,
        A2 => new__125_,
        ZN => new__3_
    );
INV_X1_15: ENTITY WORK.INV_X1
    PORT MAP (
        A => new_state_1,
        ZN => new__128_
    );
NOR3_X1_16: ENTITY WORK.NOR3_X1
    PORT MAP (
        A1 => new__128_,
        A2 => new__126_,
        A3 => new_startbuf_1,
        ZN => new__1_
    );
INV_X1_17: ENTITY WORK.INV_X1
    PORT MAP (
        A => new_state_3,
        ZN => new__129_
    );
NOR2_X1_18: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__123_,
        A2 => new__129_,
        ZN => new__2_
    );
INV_X1_19: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__163_,
        ZN => new__130_
    );
NOR2_X1_20: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new_state_3,
        A2 => new_state_0,
        ZN => new__131_
    );
INV_X1_21: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__131_,
        ZN => new__132_
    );
NOR2_X1_22: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__129_,
        A2 => new_state_0,
        ZN => new__34_
    );
AOI22_X1_23: ENTITY WORK.AOI22_X1
    PORT MAP (
        A1 => new__34_,
        A2 => new__6_,
        B1 => new_state_0,
        B2 => N(1),
        ZN => new__35_
    );
OAI21_X1_24: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => new__35_,
        B1 => new__130_,
        B2 => new__132_,
        ZN => new__8_
    );
INV_X1_25: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__34_,
        ZN => new__36_
    );
NAND2_X1_26: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => N(1),
        A2 => N(2),
        ZN => new__37_
    );
INV_X1_27: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__37_,
        ZN => new__38_
    );
NOR2_X1_28: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => N(1),
        A2 => N(2),
        ZN => new__39_
    );
OAI21_X1_29: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => new_state_0,
        B1 => new__38_,
        B2 => new__39_,
        ZN => new__40_
    );
NAND2_X1_30: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__131_,
        A2 => new__164_,
        ZN => new__41_
    );
XOR2_X1_31: ENTITY WORK.XOR2_X1
    PORT MAP (
        A => new__164_,
        B => new__163_,
        Z => new__42_
    );
OAI211_X1_32: ENTITY WORK.OAI211_X1
    PORT MAP (
        A => new__40_,
        B => new__41_,
        C1 => new__42_,
        C2 => new__36_,
        ZN => new__9_
    );
NAND2_X1_33: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__38_,
        A2 => N(3),
        ZN => new__43_
    );
INV_X1_34: ENTITY WORK.INV_X1
    PORT MAP (
        A => N(3),
        ZN => new__44_
    );
NAND2_X1_35: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__37_,
        A2 => new__44_,
        ZN => new__45_
    );
NAND3_X1_36: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__43_,
        A2 => new_state_0,
        A3 => new__45_,
        ZN => new__46_
    );
INV_X1_37: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__120_,
        ZN => new__47_
    );
OAI211_X1_38: ENTITY WORK.OAI211_X1
    PORT MAP (
        A => new__165_,
        B => new__115_,
        C1 => new__47_,
        C2 => new__129_,
        ZN => new__48_
    );
NOR2_X1_39: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__47_,
        A2 => new__165_,
        ZN => new__49_
    );
NAND3_X1_40: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__49_,
        A2 => new_state_3,
        A3 => new__115_,
        ZN => new__50_
    );
NAND3_X1_41: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__50_,
        A2 => new__46_,
        A3 => new__48_,
        ZN => new__10_
    );
INV_X1_42: ENTITY WORK.INV_X1
    PORT MAP (
        A => N(4),
        ZN => new__51_
    );
AOI21_X1_43: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__51_,
        B1 => new__37_,
        B2 => new__44_,
        ZN => new__52_
    );
AND3_X1_44: ENTITY WORK.AND3_X1
    PORT MAP (
        A1 => new__37_,
        A2 => new__51_,
        A3 => new__44_,
        ZN => new__53_
    );
OR3_X1_45: ENTITY WORK.OR3_X1
    PORT MAP (
        A1 => new__53_,
        A2 => new__52_,
        A3 => new__115_,
        ZN => new__54_
    );
NAND2_X1_46: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__131_,
        A2 => new__166_,
        ZN => new__55_
    );
XNOR2_X1_47: ENTITY WORK.XNOR2_X1
    PORT MAP (
        A => new__49_,
        B => new__166_,
        ZN => new__56_
    );
OAI211_X1_48: ENTITY WORK.OAI211_X1
    PORT MAP (
        A => new__54_,
        B => new__55_,
        C1 => new__56_,
        C2 => new__36_,
        ZN => new__11_
    );
INV_X1_49: ENTITY WORK.INV_X1
    PORT MAP (
        A => N(5),
        ZN => new__57_
    );
NOR2_X1_50: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__53_,
        A2 => new__57_,
        ZN => new__58_
    );
NOR2_X1_51: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => N(3),
        A2 => N(4),
        ZN => new__59_
    );
NAND3_X1_52: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__59_,
        A2 => new__57_,
        A3 => new__37_,
        ZN => new__60_
    );
NAND2_X1_53: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__60_,
        A2 => new_state_0,
        ZN => new__61_
    );
AOI21_X1_54: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__119_,
        B1 => new__120_,
        B2 => new__121_,
        ZN => new__62_
    );
OAI21_X1_55: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => new__34_,
        B1 => new__122_,
        B2 => new__62_,
        ZN => new__63_
    );
OAI221_X1_56: ENTITY WORK.OAI221_X1
    PORT MAP (
        A => new__63_,
        B1 => new__58_,
        B2 => new__61_,
        C1 => new__132_,
        C2 => new__119_,
        ZN => new__12_
    );
NAND3_X1_57: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__120_,
        A2 => new__121_,
        A3 => new__119_,
        ZN => new__64_
    );
NAND4_X1_58: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => new__120_,
        A2 => new__121_,
        A3 => new__116_,
        A4 => new__119_,
        ZN => new__65_
    );
NAND2_X1_59: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__65_,
        A2 => new__34_,
        ZN => new__66_
    );
AOI21_X1_60: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__66_,
        B1 => new__64_,
        B2 => new__168_,
        ZN => new__67_
    );
NOR2_X1_61: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__132_,
        A2 => new__168_,
        ZN => new__68_
    );
NAND2_X1_62: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__60_,
        A2 => N(6),
        ZN => new__69_
    );
NOR2_X1_63: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => N(5),
        A2 => N(6),
        ZN => new__70_
    );
NAND3_X1_64: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__59_,
        A2 => new__70_,
        A3 => new__37_,
        ZN => new__71_
    );
AOI21_X1_65: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__115_,
        B1 => new__69_,
        B2 => new__71_,
        ZN => new__72_
    );
NOR3_X1_66: ENTITY WORK.NOR3_X1
    PORT MAP (
        A1 => new__67_,
        A2 => new__72_,
        A3 => new__68_,
        ZN => new__13_
    );
INV_X1_67: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__5_,
        ZN => new__73_
    );
OAI21_X1_68: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => new__34_,
        B1 => new__65_,
        B2 => new__73_,
        ZN => new__74_
    );
AOI21_X1_69: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__74_,
        B1 => new__65_,
        B2 => new__73_,
        ZN => new__75_
    );
NAND2_X1_70: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__131_,
        A2 => new__117_,
        ZN => new__76_
    );
NAND3_X1_71: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__53_,
        A2 => N(7),
        A3 => new__70_,
        ZN => new__77_
    );
INV_X1_72: ENTITY WORK.INV_X1
    PORT MAP (
        A => N(7),
        ZN => new__78_
    );
NAND2_X1_73: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__71_,
        A2 => new__78_,
        ZN => new__79_
    );
NAND3_X1_74: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__77_,
        A2 => new_state_0,
        A3 => new__79_,
        ZN => new__80_
    );
NAND2_X1_75: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__80_,
        A2 => new__76_,
        ZN => new__81_
    );
NOR2_X1_76: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__81_,
        A2 => new__75_,
        ZN => new__14_
    );
OAI21_X1_77: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => new__118_,
        B1 => new__65_,
        B2 => new__73_,
        ZN => new__82_
    );
NAND4_X1_78: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => new__122_,
        A2 => new__5_,
        A3 => new__170_,
        A4 => new__116_,
        ZN => new__83_
    );
AOI21_X1_79: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__36_,
        B1 => new__83_,
        B2 => new__82_,
        ZN => new__84_
    );
NAND2_X1_80: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__131_,
        A2 => new__118_,
        ZN => new__85_
    );
NAND4_X1_81: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => new__53_,
        A2 => new__70_,
        A3 => new__78_,
        A4 => N(8),
        ZN => new__86_
    );
INV_X1_82: ENTITY WORK.INV_X1
    PORT MAP (
        A => N(8),
        ZN => new__87_
    );
NAND4_X1_83: ENTITY WORK.NAND4_X1
    PORT MAP (
        A1 => new__59_,
        A2 => new__70_,
        A3 => new__78_,
        A4 => new__37_,
        ZN => new__88_
    );
NAND2_X1_84: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__88_,
        A2 => new__87_,
        ZN => new__89_
    );
NAND3_X1_85: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__86_,
        A2 => new_state_0,
        A3 => new__89_,
        ZN => new__90_
    );
NAND2_X1_86: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__90_,
        A2 => new__85_,
        ZN => new__91_
    );
NOR2_X1_87: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__91_,
        A2 => new__84_,
        ZN => new__15_
    );
INV_X1_88: ENTITY WORK.INV_X1
    PORT MAP (
        A => new_state_2,
        ZN => new__92_
    );
NOR2_X1_89: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__132_,
        A2 => new__92_,
        ZN => new__93_
    );
MUX2_X1_90: ENTITY WORK.MUX2_X1
    PORT MAP (
        A => new__172_,
        B => N(0),
        S => new__93_,
        Z => new__16_
    );
INV_X1_91: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__181_,
        ZN => new__94_
    );
NOR2_X1_92: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__93_,
        A2 => new__173_,
        ZN => new__95_
    );
AOI21_X1_93: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__95_,
        B1 => new__93_,
        B2 => new__94_,
        ZN => new__17_
    );
MUX2_X1_94: ENTITY WORK.MUX2_X1
    PORT MAP (
        A => new__174_,
        B => new__182_,
        S => new__93_,
        Z => new__18_
    );
MUX2_X1_95: ENTITY WORK.MUX2_X1
    PORT MAP (
        A => new__175_,
        B => new__183_,
        S => new__93_,
        Z => new__19_
    );
MUX2_X1_96: ENTITY WORK.MUX2_X1
    PORT MAP (
        A => new__176_,
        B => new__184_,
        S => new__93_,
        Z => new__20_
    );
MUX2_X1_97: ENTITY WORK.MUX2_X1
    PORT MAP (
        A => new__177_,
        B => new__185_,
        S => new__93_,
        Z => new__21_
    );
MUX2_X1_98: ENTITY WORK.MUX2_X1
    PORT MAP (
        A => new__178_,
        B => new__186_,
        S => new__93_,
        Z => new__22_
    );
MUX2_X1_99: ENTITY WORK.MUX2_X1
    PORT MAP (
        A => new__179_,
        B => new__187_,
        S => new__93_,
        Z => new__23_
    );
INV_X1_100: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__188_,
        ZN => new__96_
    );
NOR2_X1_101: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => new__93_,
        A2 => new__180_,
        ZN => new__97_
    );
AOI21_X1_102: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__97_,
        B1 => new__93_,
        B2 => new__96_,
        ZN => new__24_
    );
NAND3_X1_103: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__129_,
        A2 => new__92_,
        A3 => new_state_4,
        ZN => new__98_
    );
NAND2_X1_104: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__98_,
        A2 => new__115_,
        ZN => new__99_
    );
MUX2_X1_105: ENTITY WORK.MUX2_X1
    PORT MAP (
        A => new__171_,
        B => new__0_,
        S => new__99_,
        Z => new__25_
    );
NAND2_X1_106: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__131_,
        A2 => new__181_,
        ZN => new__100_
    );
INV_X1_107: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__184_,
        ZN => new__101_
    );
INV_X1_108: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__185_,
        ZN => new__102_
    );
NAND2_X1_109: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__96_,
        A2 => new__102_,
        ZN => new__103_
    );
NAND2_X1_110: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__188_,
        A2 => new__185_,
        ZN => new__104_
    );
NAND3_X1_111: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__103_,
        A2 => new__186_,
        A3 => new__104_,
        ZN => new__105_
    );
INV_X1_112: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__186_,
        ZN => new__106_
    );
NAND2_X1_113: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__103_,
        A2 => new__104_,
        ZN => new__107_
    );
NAND2_X1_114: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => new__107_,
        A2 => new__106_,
        ZN => new__108_
    );
AOI21_X1_115: ENTITY WORK.AOI21_X1
    PORT MAP (
        A => new__101_,
        B1 => new__108_,
        B2 => new__105_,
        ZN => new__109_
    );
NAND3_X1_116: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__108_,
        A2 => new__101_,
        A3 => new__105_,
        ZN => new__110_
    );
NAND3_X1_117: ENTITY WORK.NAND3_X1
    PORT MAP (
        A1 => new__110_,
        A2 => new__0_,
        A3 => new__132_,
        ZN => new__111_
    );
OAI21_X1_118: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => new__100_,
        B1 => new__111_,
        B2 => new__109_,
        ZN => new__26_
    );
INV_X1_119: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__182_,
        ZN => new__112_
    );
OAI22_X1_120: ENTITY WORK.OAI22_X1
    PORT MAP (
        A1 => new__36_,
        A2 => new__94_,
        B1 => new__132_,
        B2 => new__112_,
        ZN => new__27_
    );
INV_X1_121: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__183_,
        ZN => new__113_
    );
OAI22_X1_122: ENTITY WORK.OAI22_X1
    PORT MAP (
        A1 => new__36_,
        A2 => new__112_,
        B1 => new__113_,
        B2 => new__132_,
        ZN => new__28_
    );
OAI22_X1_123: ENTITY WORK.OAI22_X1
    PORT MAP (
        A1 => new__36_,
        A2 => new__113_,
        B1 => new__132_,
        B2 => new__101_,
        ZN => new__29_
    );
OAI22_X1_124: ENTITY WORK.OAI22_X1
    PORT MAP (
        A1 => new__36_,
        A2 => new__101_,
        B1 => new__132_,
        B2 => new__102_,
        ZN => new__30_
    );
OAI22_X1_125: ENTITY WORK.OAI22_X1
    PORT MAP (
        A1 => new__36_,
        A2 => new__102_,
        B1 => new__132_,
        B2 => new__106_,
        ZN => new__31_
    );
INV_X1_126: ENTITY WORK.INV_X1
    PORT MAP (
        A => new__187_,
        ZN => new__114_
    );
OAI22_X1_127: ENTITY WORK.OAI22_X1
    PORT MAP (
        A1 => new__36_,
        A2 => new__106_,
        B1 => new__114_,
        B2 => new__132_,
        ZN => new__32_
    );
OAI22_X1_128: ENTITY WORK.OAI22_X1
    PORT MAP (
        A1 => new__36_,
        A2 => new__114_,
        B1 => new__132_,
        B2 => new__96_,
        ZN => new__33_
    );
INV_X1_129: ENTITY WORK.INV_X1
    PORT MAP (
        A => reset,
        ZN => new__7_
    );
DFFR_X1_130: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__8_,
        Q => new__163_,
        QN => new__6_,
        RN => new__7_
    );
DFFR_X1_131: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__9_,
        Q => new__164_,
        QN => new__133_,
        RN => new__7_
    );
DFFR_X1_132: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__10_,
        Q => new__165_,
        QN => new__134_,
        RN => new__7_
    );
DFFR_X1_133: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__11_,
        Q => new__166_,
        QN => new__135_,
        RN => new__7_
    );
DFFR_X1_134: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__12_,
        Q => new__167_,
        QN => new__136_,
        RN => new__7_
    );
DFFR_X1_135: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__13_,
        Q => new__168_,
        QN => new__137_,
        RN => new__7_
    );
DFFR_X1_136: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__14_,
        Q => new__169_,
        QN => new__5_,
        RN => new__7_
    );
DFFR_X1_137: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__15_,
        Q => new__170_,
        QN => new__138_,
        RN => new__7_
    );
DFFR_X1_138: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__16_,
        Q => new__172_,
        QN => new__139_,
        RN => new__7_
    );
DFFR_X1_139: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__17_,
        Q => new__173_,
        QN => new__140_,
        RN => new__7_
    );
DFFR_X1_140: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__18_,
        Q => new__174_,
        QN => new__141_,
        RN => new__7_
    );
DFFR_X1_141: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__19_,
        Q => new__175_,
        QN => new__142_,
        RN => new__7_
    );
DFFR_X1_142: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__20_,
        Q => new__176_,
        QN => new__143_,
        RN => new__7_
    );
DFFR_X1_143: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__21_,
        Q => new__177_,
        QN => new__144_,
        RN => new__7_
    );
DFFR_X1_144: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__22_,
        Q => new__178_,
        QN => new__145_,
        RN => new__7_
    );
DFFR_X1_145: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__23_,
        Q => new__179_,
        QN => new__146_,
        RN => new__7_
    );
DFFR_X1_146: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__24_,
        Q => new__180_,
        QN => new__147_,
        RN => new__7_
    );
DFFR_X1_147: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__25_,
        Q => new__171_,
        QN => new__148_,
        RN => new__7_
    );
DFFS_X1_148: ENTITY WORK.DFFS_X1
    PORT MAP (
        CK => clock,
        D => new__1_,
        Q => new_state_0,
        QN => new__0_,
        SN => new__7_
    );
DFFR_X1_149: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__3_,
        Q => new_state_1,
        QN => new__149_,
        RN => new__7_
    );
DFFR_X1_150: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__2_,
        Q => new_state_2,
        QN => new__150_,
        RN => new__7_
    );
DFFR_X1_151: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__4_,
        Q => new_state_3,
        QN => new__151_,
        RN => new__7_
    );
DFFR_X1_152: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new_state_2,
        Q => new_state_4,
        QN => new__152_,
        RN => new__7_
    );
DFFR_X1_153: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__26_,
        Q => new__181_,
        QN => new__153_,
        RN => new__7_
    );
DFFR_X1_154: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__27_,
        Q => new__182_,
        QN => new__154_,
        RN => new__7_
    );
DFFR_X1_155: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__28_,
        Q => new__183_,
        QN => new__155_,
        RN => new__7_
    );
DFFR_X1_156: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__29_,
        Q => new__184_,
        QN => new__156_,
        RN => new__7_
    );
DFFR_X1_157: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__30_,
        Q => new__185_,
        QN => new__157_,
        RN => new__7_
    );
DFFR_X1_158: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__31_,
        Q => new__186_,
        QN => new__158_,
        RN => new__7_
    );
DFFR_X1_159: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__32_,
        Q => new__187_,
        QN => new__159_,
        RN => new__7_
    );
DFFR_X1_160: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new__33_,
        Q => new__188_,
        QN => new__160_,
        RN => new__7_
    );
DFFR_X1_161: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => start,
        Q => new_startbuf_0,
        QN => new__161_,
        RN => new__7_
    );
DFFR_X1_162: ENTITY WORK.DFFR_X1
    PORT MAP (
        CK => clock,
        D => new_startbuf_0,
        Q => new_startbuf_1,
        QN => new__162_,
        RN => new__7_
    );
BUF_X1_163: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__163_,
        Z => counter(0)
    );
BUF_X1_164: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__164_,
        Z => counter(1)
    );
BUF_X1_165: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__165_,
        Z => counter(2)
    );
BUF_X1_166: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__166_,
        Z => counter(3)
    );
BUF_X1_167: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__167_,
        Z => counter(4)
    );
BUF_X1_168: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__168_,
        Z => counter(5)
    );
BUF_X1_169: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__169_,
        Z => counter(6)
    );
BUF_X1_170: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__170_,
        Z => counter(7)
    );
BUF_X1_171: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__171_,
        Z => done
    );
BUF_X1_172: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__172_,
        Z => dp(0)
    );
BUF_X1_173: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__173_,
        Z => dp(1)
    );
BUF_X1_174: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__174_,
        Z => dp(2)
    );
BUF_X1_175: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__175_,
        Z => dp(3)
    );
BUF_X1_176: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__176_,
        Z => dp(4)
    );
BUF_X1_177: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__177_,
        Z => dp(5)
    );
BUF_X1_178: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__178_,
        Z => dp(6)
    );
BUF_X1_179: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__179_,
        Z => dp(7)
    );
BUF_X1_180: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__180_,
        Z => dp(8)
    );
BUF_X1_181: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__181_,
        Z => sr(0)
    );
BUF_X1_182: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__182_,
        Z => sr(1)
    );
BUF_X1_183: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__183_,
        Z => sr(2)
    );
BUF_X1_184: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__184_,
        Z => sr(3)
    );
BUF_X1_185: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__185_,
        Z => sr(4)
    );
BUF_X1_186: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__186_,
        Z => sr(5)
    );
BUF_X1_187: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__187_,
        Z => sr(6)
    );
BUF_X1_188: ENTITY WORK.BUF_X1
    PORT MAP (
        A => new__188_,
        Z => sr(7)
    );

END ARCHITECTURE arch;
