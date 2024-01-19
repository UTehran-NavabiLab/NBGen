LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY aftab_adder_subtractor IS
    PORT (
        a : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
        b : IN STD_LOGIC_VECTOR (31 DOWNTO 0);
        subsel : IN STD_LOGIC;
        pass : IN STD_LOGIC;
        cout : OUT STD_LOGIC;
        result : OUT STD_LOGIC_VECTOR (31 DOWNTO 0));
END ENTITY aftab_adder_subtractor;

ARCHITECTURE arch OF aftab_adder_subtractor IS
    SIGNAL S0 : STD_LOGIC;
    SIGNAL S1 : STD_LOGIC;
    SIGNAL S2 : STD_LOGIC;
    SIGNAL S3 : STD_LOGIC;
    SIGNAL S4 : STD_LOGIC;
    SIGNAL S5 : STD_LOGIC;
    SIGNAL S6 : STD_LOGIC;
    SIGNAL S7 : STD_LOGIC;
    SIGNAL S8 : STD_LOGIC;
    SIGNAL S9 : STD_LOGIC;
    SIGNAL S10 : STD_LOGIC;
    SIGNAL S11 : STD_LOGIC;
    SIGNAL S12 : STD_LOGIC;
    SIGNAL S13 : STD_LOGIC;
    SIGNAL S14 : STD_LOGIC;
    SIGNAL S15 : STD_LOGIC;
    SIGNAL S16 : STD_LOGIC;
    SIGNAL S17 : STD_LOGIC;
    SIGNAL S18 : STD_LOGIC;
    SIGNAL S19 : STD_LOGIC;
    SIGNAL S20 : STD_LOGIC;
    SIGNAL S21 : STD_LOGIC;
    SIGNAL S22 : STD_LOGIC;
    SIGNAL S23 : STD_LOGIC;
    SIGNAL S24 : STD_LOGIC;
    SIGNAL S25 : STD_LOGIC;
    SIGNAL S26 : STD_LOGIC;
    SIGNAL S27 : STD_LOGIC;
    SIGNAL S28 : STD_LOGIC;
    SIGNAL S29 : STD_LOGIC;
    SIGNAL S30 : STD_LOGIC;
    SIGNAL S31 : STD_LOGIC;
    SIGNAL S32 : STD_LOGIC;
    SIGNAL S33 : STD_LOGIC;
    SIGNAL S34 : STD_LOGIC;
    SIGNAL S35 : STD_LOGIC;
    SIGNAL S36 : STD_LOGIC;
    SIGNAL S37 : STD_LOGIC;
    SIGNAL S38 : STD_LOGIC;
    SIGNAL S39 : STD_LOGIC;
    SIGNAL S40 : STD_LOGIC;
    SIGNAL S41 : STD_LOGIC;
    SIGNAL S42 : STD_LOGIC;
    SIGNAL S43 : STD_LOGIC;
    SIGNAL S44 : STD_LOGIC;
    SIGNAL S45 : STD_LOGIC;
    SIGNAL S46 : STD_LOGIC;
    SIGNAL S47 : STD_LOGIC;
    SIGNAL S48 : STD_LOGIC;
    SIGNAL S49 : STD_LOGIC;
    SIGNAL S50 : STD_LOGIC;
    SIGNAL S51 : STD_LOGIC;
    SIGNAL S52 : STD_LOGIC;
    SIGNAL S53 : STD_LOGIC;
    SIGNAL S54 : STD_LOGIC;
    SIGNAL S55 : STD_LOGIC;
    SIGNAL S56 : STD_LOGIC;
    SIGNAL S57 : STD_LOGIC;
    SIGNAL S58 : STD_LOGIC;
    SIGNAL S59 : STD_LOGIC;
    SIGNAL S60 : STD_LOGIC;
    SIGNAL S61 : STD_LOGIC;
    SIGNAL S62 : STD_LOGIC;
    SIGNAL S63 : STD_LOGIC;
    SIGNAL S64 : STD_LOGIC;
    SIGNAL S65 : STD_LOGIC;
    SIGNAL S66 : STD_LOGIC;
    SIGNAL S67 : STD_LOGIC;
    SIGNAL S68 : STD_LOGIC;
    SIGNAL S69 : STD_LOGIC;
    SIGNAL S70 : STD_LOGIC;
    SIGNAL S71 : STD_LOGIC;
    SIGNAL S72 : STD_LOGIC;
    SIGNAL S73 : STD_LOGIC;
    SIGNAL S74 : STD_LOGIC;
    SIGNAL S75 : STD_LOGIC;
    SIGNAL S76 : STD_LOGIC;
    SIGNAL S77 : STD_LOGIC;
    SIGNAL S78 : STD_LOGIC;
    SIGNAL S79 : STD_LOGIC;
    SIGNAL S80 : STD_LOGIC;
    SIGNAL S81 : STD_LOGIC;
    SIGNAL S82 : STD_LOGIC;
    SIGNAL S83 : STD_LOGIC;
    SIGNAL S84 : STD_LOGIC;
    SIGNAL S85 : STD_LOGIC;
    SIGNAL S86 : STD_LOGIC;
    SIGNAL S87 : STD_LOGIC;
    SIGNAL S88 : STD_LOGIC;
    SIGNAL S89 : STD_LOGIC;
    SIGNAL S90 : STD_LOGIC;
    SIGNAL S91 : STD_LOGIC;
    SIGNAL S92 : STD_LOGIC;
    SIGNAL S93 : STD_LOGIC;
    SIGNAL S94 : STD_LOGIC;
    SIGNAL S95 : STD_LOGIC;
    SIGNAL S96 : STD_LOGIC;
    SIGNAL S97 : STD_LOGIC;
    SIGNAL S98 : STD_LOGIC;
    SIGNAL S99 : STD_LOGIC;
    SIGNAL S100 : STD_LOGIC;
    SIGNAL S101 : STD_LOGIC;
    SIGNAL S102 : STD_LOGIC;
    SIGNAL S103 : STD_LOGIC;
    SIGNAL S104 : STD_LOGIC;
    SIGNAL S105 : STD_LOGIC;
    SIGNAL S106 : STD_LOGIC;
    SIGNAL S107 : STD_LOGIC;
    SIGNAL S108 : STD_LOGIC;
    SIGNAL S109 : STD_LOGIC;
    SIGNAL S110 : STD_LOGIC;
    SIGNAL S111 : STD_LOGIC;
    SIGNAL S112 : STD_LOGIC;
    SIGNAL S113 : STD_LOGIC;
    SIGNAL S114 : STD_LOGIC;
    SIGNAL S115 : STD_LOGIC;
    SIGNAL S116 : STD_LOGIC;
    SIGNAL S117 : STD_LOGIC;
    SIGNAL S118 : STD_LOGIC;
    SIGNAL S119 : STD_LOGIC;
    SIGNAL S120 : STD_LOGIC;
    SIGNAL S121 : STD_LOGIC;
    SIGNAL S122 : STD_LOGIC;
    SIGNAL S123 : STD_LOGIC;
    SIGNAL S124 : STD_LOGIC;
    SIGNAL S125 : STD_LOGIC;
    SIGNAL S126 : STD_LOGIC;
    SIGNAL S127 : STD_LOGIC;
    SIGNAL S128 : STD_LOGIC;
    SIGNAL S129 : STD_LOGIC;
    SIGNAL S130 : STD_LOGIC;
    SIGNAL S131 : STD_LOGIC;
    SIGNAL S132 : STD_LOGIC;
    SIGNAL S133 : STD_LOGIC;
    SIGNAL addSubRes_0 : STD_LOGIC;
    SIGNAL addSubRes_10 : STD_LOGIC;
    SIGNAL addSubRes_11 : STD_LOGIC;
    SIGNAL addSubRes_12 : STD_LOGIC;
    SIGNAL addSubRes_13 : STD_LOGIC;
    SIGNAL addSubRes_14 : STD_LOGIC;
    SIGNAL addSubRes_15 : STD_LOGIC;
    SIGNAL addSubRes_16 : STD_LOGIC;
    SIGNAL addSubRes_17 : STD_LOGIC;
    SIGNAL addSubRes_18 : STD_LOGIC;
    SIGNAL addSubRes_19 : STD_LOGIC;
    SIGNAL addSubRes_1 : STD_LOGIC;
    SIGNAL addSubRes_20 : STD_LOGIC;
    SIGNAL addSubRes_21 : STD_LOGIC;
    SIGNAL addSubRes_22 : STD_LOGIC;
    SIGNAL addSubRes_23 : STD_LOGIC;
    SIGNAL addSubRes_24 : STD_LOGIC;
    SIGNAL addSubRes_25 : STD_LOGIC;
    SIGNAL addSubRes_26 : STD_LOGIC;
    SIGNAL addSubRes_27 : STD_LOGIC;
    SIGNAL addSubRes_28 : STD_LOGIC;
    SIGNAL addSubRes_29 : STD_LOGIC;
    SIGNAL addSubRes_2 : STD_LOGIC;
    SIGNAL addSubRes_30 : STD_LOGIC;
    SIGNAL addSubRes_31 : STD_LOGIC;
    SIGNAL addSubRes_3 : STD_LOGIC;
    SIGNAL addSubRes_4 : STD_LOGIC;
    SIGNAL addSubRes_5 : STD_LOGIC;
    SIGNAL addSubRes_6 : STD_LOGIC;
    SIGNAL addSubRes_7 : STD_LOGIC;
    SIGNAL addSubRes_8 : STD_LOGIC;
    SIGNAL addSubRes_9 : STD_LOGIC;
    SIGNAL bsel_0 : STD_LOGIC;
    SIGNAL bsel_10 : STD_LOGIC;
    SIGNAL bsel_11 : STD_LOGIC;
    SIGNAL bsel_12 : STD_LOGIC;
    SIGNAL bsel_13 : STD_LOGIC;
    SIGNAL bsel_14 : STD_LOGIC;
    SIGNAL bsel_15 : STD_LOGIC;
    SIGNAL bsel_16 : STD_LOGIC;
    SIGNAL bsel_17 : STD_LOGIC;
    SIGNAL bsel_18 : STD_LOGIC;
    SIGNAL bsel_19 : STD_LOGIC;
    SIGNAL bsel_1 : STD_LOGIC;
    SIGNAL bsel_20 : STD_LOGIC;
    SIGNAL bsel_21 : STD_LOGIC;
    SIGNAL bsel_22 : STD_LOGIC;
    SIGNAL bsel_23 : STD_LOGIC;
    SIGNAL bsel_24 : STD_LOGIC;
    SIGNAL bsel_25 : STD_LOGIC;
    SIGNAL bsel_26 : STD_LOGIC;
    SIGNAL bsel_27 : STD_LOGIC;
    SIGNAL bsel_28 : STD_LOGIC;
    SIGNAL bsel_29 : STD_LOGIC;
    SIGNAL bsel_2 : STD_LOGIC;
    SIGNAL bsel_30 : STD_LOGIC;
    SIGNAL bsel_31 : STD_LOGIC;
    SIGNAL bsel_3 : STD_LOGIC;
    SIGNAL bsel_4 : STD_LOGIC;
    SIGNAL bsel_5 : STD_LOGIC;
    SIGNAL bsel_6 : STD_LOGIC;
    SIGNAL bsel_7 : STD_LOGIC;
    SIGNAL bsel_8 : STD_LOGIC;
    SIGNAL bsel_9 : STD_LOGIC;

BEGIN
NOR2_X1_1: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(0),
        ZN => S0
    );
AND2_X1_1: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(0),
        A2 => S133,
        ZN => S1
    );
NOR2_X1_2: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S1,
        A2 => S0,
        ZN => bsel_0
    );
NOR2_X1_3: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(1),
        ZN => S2
    );
AND2_X1_2: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(1),
        A2 => S133,
        ZN => S3
    );
NOR2_X1_4: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S3,
        A2 => S2,
        ZN => bsel_1
    );
NOR2_X1_5: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(2),
        ZN => S4
    );
AND2_X1_3: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(2),
        A2 => S133,
        ZN => S5
    );
NOR2_X1_6: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S5,
        A2 => S4,
        ZN => bsel_2
    );
NOR2_X1_7: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(3),
        ZN => S6
    );
AND2_X1_4: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(3),
        A2 => S133,
        ZN => S7
    );
NOR2_X1_8: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S7,
        A2 => S6,
        ZN => bsel_3
    );
NOR2_X1_9: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(4),
        ZN => S8
    );
AND2_X1_5: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(4),
        A2 => S133,
        ZN => S9
    );
NOR2_X1_10: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S9,
        A2 => S8,
        ZN => bsel_4
    );
NOR2_X1_11: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(5),
        ZN => S10
    );
AND2_X1_6: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(5),
        A2 => S133,
        ZN => S11
    );
NOR2_X1_12: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S11,
        A2 => S10,
        ZN => bsel_5
    );
NOR2_X1_13: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(6),
        ZN => S12
    );
AND2_X1_7: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(6),
        A2 => S133,
        ZN => S13
    );
NOR2_X1_14: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S13,
        A2 => S12,
        ZN => bsel_6
    );
NOR2_X1_15: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(7),
        ZN => S14
    );
AND2_X1_8: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(7),
        A2 => S133,
        ZN => S15
    );
NOR2_X1_16: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S15,
        A2 => S14,
        ZN => bsel_7
    );
NOR2_X1_17: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(8),
        ZN => S16
    );
AND2_X1_9: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(8),
        A2 => S133,
        ZN => S17
    );
NOR2_X1_18: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S17,
        A2 => S16,
        ZN => bsel_8
    );
NOR2_X1_19: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(9),
        ZN => S18
    );
AND2_X1_10: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(9),
        A2 => S133,
        ZN => S19
    );
NOR2_X1_20: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S19,
        A2 => S18,
        ZN => bsel_9
    );
NOR2_X1_21: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(10),
        ZN => S20
    );
AND2_X1_11: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(10),
        A2 => S133,
        ZN => S21
    );
NOR2_X1_22: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S21,
        A2 => S20,
        ZN => bsel_10
    );
NOR2_X1_23: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(11),
        ZN => S22
    );
AND2_X1_12: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(11),
        A2 => S133,
        ZN => S23
    );
NOR2_X1_24: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S23,
        A2 => S22,
        ZN => bsel_11
    );
NOR2_X1_25: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(12),
        ZN => S24
    );
AND2_X1_13: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(12),
        A2 => S133,
        ZN => S25
    );
NOR2_X1_26: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S25,
        A2 => S24,
        ZN => bsel_12
    );
NOR2_X1_27: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(13),
        ZN => S26
    );
AND2_X1_14: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(13),
        A2 => S133,
        ZN => S27
    );
NOR2_X1_28: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S27,
        A2 => S26,
        ZN => bsel_13
    );
NOR2_X1_29: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(14),
        ZN => S28
    );
AND2_X1_15: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(14),
        A2 => S133,
        ZN => S29
    );
NOR2_X1_30: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S29,
        A2 => S28,
        ZN => bsel_14
    );
NOR2_X1_31: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(15),
        ZN => S30
    );
AND2_X1_16: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(15),
        A2 => S133,
        ZN => S31
    );
NOR2_X1_32: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S31,
        A2 => S30,
        ZN => bsel_15
    );
NOR2_X1_33: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(16),
        ZN => S32
    );
AND2_X1_17: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(16),
        A2 => S133,
        ZN => S33
    );
NOR2_X1_34: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S33,
        A2 => S32,
        ZN => bsel_16
    );
NOR2_X1_35: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(17),
        ZN => S34
    );
AND2_X1_18: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(17),
        A2 => S133,
        ZN => S35
    );
NOR2_X1_36: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S35,
        A2 => S34,
        ZN => bsel_17
    );
NOR2_X1_37: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(18),
        ZN => S36
    );
AND2_X1_19: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(18),
        A2 => S133,
        ZN => S37
    );
NOR2_X1_38: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S37,
        A2 => S36,
        ZN => bsel_18
    );
NOR2_X1_39: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(19),
        ZN => S38
    );
AND2_X1_20: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(19),
        A2 => S133,
        ZN => S39
    );
NOR2_X1_40: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S39,
        A2 => S38,
        ZN => bsel_19
    );
NOR2_X1_41: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(20),
        ZN => S40
    );
AND2_X1_21: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(20),
        A2 => S133,
        ZN => S41
    );
NOR2_X1_42: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S41,
        A2 => S40,
        ZN => bsel_20
    );
NOR2_X1_43: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(21),
        ZN => S42
    );
AND2_X1_22: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(21),
        A2 => S133,
        ZN => S43
    );
NOR2_X1_44: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S43,
        A2 => S42,
        ZN => bsel_21
    );
NOR2_X1_45: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(22),
        ZN => S44
    );
AND2_X1_23: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(22),
        A2 => S133,
        ZN => S45
    );
NOR2_X1_46: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S45,
        A2 => S44,
        ZN => bsel_22
    );
NOR2_X1_47: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(23),
        ZN => S46
    );
AND2_X1_24: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(23),
        A2 => S133,
        ZN => S47
    );
NOR2_X1_48: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S47,
        A2 => S46,
        ZN => bsel_23
    );
NOR2_X1_49: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(24),
        ZN => S48
    );
AND2_X1_25: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(24),
        A2 => S133,
        ZN => S49
    );
NOR2_X1_50: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S49,
        A2 => S48,
        ZN => bsel_24
    );
NOR2_X1_51: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(25),
        ZN => S50
    );
AND2_X1_26: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(25),
        A2 => S133,
        ZN => S51
    );
NOR2_X1_52: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S51,
        A2 => S50,
        ZN => bsel_25
    );
NOR2_X1_53: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(26),
        ZN => S52
    );
AND2_X1_27: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(26),
        A2 => S133,
        ZN => S53
    );
NOR2_X1_54: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S53,
        A2 => S52,
        ZN => bsel_26
    );
NOR2_X1_55: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(27),
        ZN => S54
    );
AND2_X1_28: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(27),
        A2 => S133,
        ZN => S55
    );
NOR2_X1_56: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S55,
        A2 => S54,
        ZN => bsel_27
    );
NOR2_X1_57: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(28),
        ZN => S56
    );
AND2_X1_29: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(28),
        A2 => S133,
        ZN => S57
    );
NOR2_X1_58: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S57,
        A2 => S56,
        ZN => bsel_28
    );
NOR2_X1_59: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(29),
        ZN => S58
    );
AND2_X1_30: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(29),
        A2 => S133,
        ZN => S59
    );
NOR2_X1_60: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S59,
        A2 => S58,
        ZN => bsel_29
    );
NOR2_X1_61: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(30),
        ZN => S60
    );
AND2_X1_31: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(30),
        A2 => S133,
        ZN => S61
    );
NOR2_X1_62: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S61,
        A2 => S60,
        ZN => bsel_30
    );
NOR2_X1_63: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S133,
        A2 => S129(31),
        ZN => S62
    );
AND2_X1_32: ENTITY WORK.AND2_X1
    PORT MAP (
        A1 => S129(31),
        A2 => S133,
        ZN => S63
    );
NOR2_X1_64: ENTITY WORK.NOR2_X1
    PORT MAP (
        A1 => S63,
        A2 => S62,
        ZN => bsel_31
    );
INV_X1_1: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_0,
        ZN => S64
    );
NAND2_X1_1: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(0),
        A2 => S131,
        ZN => S65
    );
OAI21_X1_1: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S65,
        B1 => S64,
        B2 => S131,
        ZN => S132(0)
    );
INV_X1_2: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_1,
        ZN => S66
    );
NAND2_X1_2: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(1),
        A2 => S131,
        ZN => S67
    );
OAI21_X1_2: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S67,
        B1 => S66,
        B2 => S131,
        ZN => S132(1)
    );
INV_X1_3: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_2,
        ZN => S68
    );
NAND2_X1_3: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(2),
        A2 => S131,
        ZN => S69
    );
OAI21_X1_3: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S69,
        B1 => S68,
        B2 => S131,
        ZN => S132(2)
    );
INV_X1_4: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_3,
        ZN => S70
    );
NAND2_X1_4: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(3),
        A2 => S131,
        ZN => S71
    );
OAI21_X1_4: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S71,
        B1 => S70,
        B2 => S131,
        ZN => S132(3)
    );
INV_X1_5: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_4,
        ZN => S72
    );
NAND2_X1_5: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(4),
        A2 => S131,
        ZN => S73
    );
OAI21_X1_5: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S73,
        B1 => S72,
        B2 => S131,
        ZN => S132(4)
    );
INV_X1_6: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_5,
        ZN => S74
    );
NAND2_X1_6: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(5),
        A2 => S131,
        ZN => S75
    );
OAI21_X1_6: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S75,
        B1 => S74,
        B2 => S131,
        ZN => S132(5)
    );
INV_X1_7: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_6,
        ZN => S76
    );
NAND2_X1_7: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(6),
        A2 => S131,
        ZN => S77
    );
OAI21_X1_7: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S77,
        B1 => S76,
        B2 => S131,
        ZN => S132(6)
    );
INV_X1_8: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_7,
        ZN => S78
    );
NAND2_X1_8: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(7),
        A2 => S131,
        ZN => S79
    );
OAI21_X1_8: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S79,
        B1 => S78,
        B2 => S131,
        ZN => S132(7)
    );
INV_X1_9: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_8,
        ZN => S80
    );
NAND2_X1_9: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(8),
        A2 => S131,
        ZN => S81
    );
OAI21_X1_9: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S81,
        B1 => S80,
        B2 => S131,
        ZN => S132(8)
    );
INV_X1_10: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_9,
        ZN => S82
    );
NAND2_X1_10: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(9),
        A2 => S131,
        ZN => S83
    );
OAI21_X1_10: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S83,
        B1 => S82,
        B2 => S131,
        ZN => S132(9)
    );
INV_X1_11: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_10,
        ZN => S84
    );
NAND2_X1_11: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(10),
        A2 => S131,
        ZN => S85
    );
OAI21_X1_11: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S85,
        B1 => S84,
        B2 => S131,
        ZN => S132(10)
    );
INV_X1_12: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_11,
        ZN => S86
    );
NAND2_X1_12: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(11),
        A2 => S131,
        ZN => S87
    );
OAI21_X1_12: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S87,
        B1 => S86,
        B2 => S131,
        ZN => S132(11)
    );
INV_X1_13: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_12,
        ZN => S88
    );
NAND2_X1_13: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(12),
        A2 => S131,
        ZN => S89
    );
OAI21_X1_13: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S89,
        B1 => S88,
        B2 => S131,
        ZN => S132(12)
    );
INV_X1_14: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_13,
        ZN => S90
    );
NAND2_X1_14: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(13),
        A2 => S131,
        ZN => S91
    );
OAI21_X1_14: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S91,
        B1 => S90,
        B2 => S131,
        ZN => S132(13)
    );
INV_X1_15: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_14,
        ZN => S92
    );
NAND2_X1_15: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(14),
        A2 => S131,
        ZN => S93
    );
OAI21_X1_15: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S93,
        B1 => S92,
        B2 => S131,
        ZN => S132(14)
    );
INV_X1_16: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_15,
        ZN => S94
    );
NAND2_X1_16: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(15),
        A2 => S131,
        ZN => S95
    );
OAI21_X1_16: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S95,
        B1 => S94,
        B2 => S131,
        ZN => S132(15)
    );
INV_X1_17: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_16,
        ZN => S96
    );
NAND2_X1_17: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(16),
        A2 => S131,
        ZN => S97
    );
OAI21_X1_17: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S97,
        B1 => S96,
        B2 => S131,
        ZN => S132(16)
    );
INV_X1_18: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_17,
        ZN => S98
    );
NAND2_X1_18: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(17),
        A2 => S131,
        ZN => S99
    );
OAI21_X1_18: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S99,
        B1 => S98,
        B2 => S131,
        ZN => S132(17)
    );
INV_X1_19: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_18,
        ZN => S100
    );
NAND2_X1_19: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(18),
        A2 => S131,
        ZN => S101
    );
OAI21_X1_19: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S101,
        B1 => S100,
        B2 => S131,
        ZN => S132(18)
    );
INV_X1_20: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_19,
        ZN => S102
    );
NAND2_X1_20: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(19),
        A2 => S131,
        ZN => S103
    );
OAI21_X1_20: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S103,
        B1 => S102,
        B2 => S131,
        ZN => S132(19)
    );
INV_X1_21: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_20,
        ZN => S104
    );
NAND2_X1_21: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(20),
        A2 => S131,
        ZN => S105
    );
OAI21_X1_21: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S105,
        B1 => S104,
        B2 => S131,
        ZN => S132(20)
    );
INV_X1_22: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_21,
        ZN => S106
    );
NAND2_X1_22: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(21),
        A2 => S131,
        ZN => S107
    );
OAI21_X1_22: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S107,
        B1 => S106,
        B2 => S131,
        ZN => S132(21)
    );
INV_X1_23: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_22,
        ZN => S108
    );
NAND2_X1_23: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(22),
        A2 => S131,
        ZN => S109
    );
OAI21_X1_23: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S109,
        B1 => S108,
        B2 => S131,
        ZN => S132(22)
    );
INV_X1_24: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_23,
        ZN => S110
    );
NAND2_X1_24: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(23),
        A2 => S131,
        ZN => S111
    );
OAI21_X1_24: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S111,
        B1 => S110,
        B2 => S131,
        ZN => S132(23)
    );
INV_X1_25: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_24,
        ZN => S112
    );
NAND2_X1_25: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(24),
        A2 => S131,
        ZN => S113
    );
OAI21_X1_25: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S113,
        B1 => S112,
        B2 => S131,
        ZN => S132(24)
    );
INV_X1_26: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_25,
        ZN => S114
    );
NAND2_X1_26: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(25),
        A2 => S131,
        ZN => S115
    );
OAI21_X1_26: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S115,
        B1 => S114,
        B2 => S131,
        ZN => S132(25)
    );
INV_X1_27: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_26,
        ZN => S116
    );
NAND2_X1_27: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(26),
        A2 => S131,
        ZN => S117
    );
OAI21_X1_27: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S117,
        B1 => S116,
        B2 => S131,
        ZN => S132(26)
    );
INV_X1_28: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_27,
        ZN => S118
    );
NAND2_X1_28: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(27),
        A2 => S131,
        ZN => S119
    );
OAI21_X1_28: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S119,
        B1 => S118,
        B2 => S131,
        ZN => S132(27)
    );
INV_X1_29: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_28,
        ZN => S120
    );
NAND2_X1_29: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(28),
        A2 => S131,
        ZN => S121
    );
OAI21_X1_29: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S121,
        B1 => S120,
        B2 => S131,
        ZN => S132(28)
    );
INV_X1_30: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_29,
        ZN => S122
    );
NAND2_X1_30: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(29),
        A2 => S131,
        ZN => S123
    );
OAI21_X1_30: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S123,
        B1 => S122,
        B2 => S131,
        ZN => S132(29)
    );
INV_X1_31: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_30,
        ZN => S124
    );
NAND2_X1_31: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(30),
        A2 => S131,
        ZN => S125
    );
OAI21_X1_31: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S125,
        B1 => S124,
        B2 => S131,
        ZN => S132(30)
    );
INV_X1_32: ENTITY WORK.INV_X1
    PORT MAP (
        A => addSubRes_31,
        ZN => S126
    );
NAND2_X1_32: ENTITY WORK.NAND2_X1
    PORT MAP (
        A1 => S129(31),
        A2 => S131,
        ZN => S127
    );
OAI21_X1_32: ENTITY WORK.OAI21_X1
    PORT MAP (
        A => S127,
        B1 => S126,
        B2 => S131,
        ZN => S132(31)
    );
BUF_X1_1: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(0),
        Z => S128(0)
    );
BUF_X1_2: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(1),
        Z => S128(1)
    );
BUF_X1_3: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(10),
        Z => S128(10)
    );
BUF_X1_4: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(11),
        Z => S128(11)
    );
BUF_X1_5: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(12),
        Z => S128(12)
    );
BUF_X1_6: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(13),
        Z => S128(13)
    );
BUF_X1_7: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(14),
        Z => S128(14)
    );
BUF_X1_8: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(15),
        Z => S128(15)
    );
BUF_X1_9: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(16),
        Z => S128(16)
    );
BUF_X1_10: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(17),
        Z => S128(17)
    );
BUF_X1_11: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(18),
        Z => S128(18)
    );
BUF_X1_12: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(19),
        Z => S128(19)
    );
BUF_X1_13: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(2),
        Z => S128(2)
    );
BUF_X1_14: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(20),
        Z => S128(20)
    );
BUF_X1_15: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(21),
        Z => S128(21)
    );
BUF_X1_16: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(22),
        Z => S128(22)
    );
BUF_X1_17: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(23),
        Z => S128(23)
    );
BUF_X1_18: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(24),
        Z => S128(24)
    );
BUF_X1_19: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(25),
        Z => S128(25)
    );
BUF_X1_20: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(26),
        Z => S128(26)
    );
BUF_X1_21: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(27),
        Z => S128(27)
    );
BUF_X1_22: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(28),
        Z => S128(28)
    );
BUF_X1_23: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(29),
        Z => S128(29)
    );
BUF_X1_24: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(3),
        Z => S128(3)
    );
BUF_X1_25: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(30),
        Z => S128(30)
    );
BUF_X1_26: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(31),
        Z => S128(31)
    );
BUF_X1_27: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(4),
        Z => S128(4)
    );
BUF_X1_28: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(5),
        Z => S128(5)
    );
BUF_X1_29: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(6),
        Z => S128(6)
    );
BUF_X1_30: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(7),
        Z => S128(7)
    );
BUF_X1_31: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(8),
        Z => S128(8)
    );
BUF_X1_32: ENTITY WORK.BUF_X1
    PORT MAP (
        A => a(9),
        Z => S128(9)
    );
BUF_X1_33: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(0),
        Z => S129(0)
    );
BUF_X1_34: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(1),
        Z => S129(1)
    );
BUF_X1_35: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(10),
        Z => S129(10)
    );
BUF_X1_36: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(11),
        Z => S129(11)
    );
BUF_X1_37: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(12),
        Z => S129(12)
    );
BUF_X1_38: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(13),
        Z => S129(13)
    );
BUF_X1_39: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(14),
        Z => S129(14)
    );
BUF_X1_40: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(15),
        Z => S129(15)
    );
BUF_X1_41: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(16),
        Z => S129(16)
    );
BUF_X1_42: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(17),
        Z => S129(17)
    );
BUF_X1_43: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(18),
        Z => S129(18)
    );
BUF_X1_44: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(19),
        Z => S129(19)
    );
BUF_X1_45: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(2),
        Z => S129(2)
    );
BUF_X1_46: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(20),
        Z => S129(20)
    );
BUF_X1_47: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(21),
        Z => S129(21)
    );
BUF_X1_48: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(22),
        Z => S129(22)
    );
BUF_X1_49: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(23),
        Z => S129(23)
    );
BUF_X1_50: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(24),
        Z => S129(24)
    );
BUF_X1_51: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(25),
        Z => S129(25)
    );
BUF_X1_52: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(26),
        Z => S129(26)
    );
BUF_X1_53: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(27),
        Z => S129(27)
    );
BUF_X1_54: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(28),
        Z => S129(28)
    );
BUF_X1_55: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(29),
        Z => S129(29)
    );
BUF_X1_56: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(3),
        Z => S129(3)
    );
BUF_X1_57: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(30),
        Z => S129(30)
    );
BUF_X1_58: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(31),
        Z => S129(31)
    );
BUF_X1_59: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(4),
        Z => S129(4)
    );
BUF_X1_60: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(5),
        Z => S129(5)
    );
BUF_X1_61: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(6),
        Z => S129(6)
    );
BUF_X1_62: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(7),
        Z => S129(7)
    );
BUF_X1_63: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(8),
        Z => S129(8)
    );
BUF_X1_64: ENTITY WORK.BUF_X1
    PORT MAP (
        A => b(9),
        Z => S129(9)
    );
BUF_X1_65: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S130,
        Z => cout
    );
BUF_X1_66: ENTITY WORK.BUF_X1
    PORT MAP (
        A => pass,
        Z => S131
    );
BUF_X1_67: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(0),
        Z => result(0)
    );
BUF_X1_68: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(1),
        Z => result(1)
    );
BUF_X1_69: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(10),
        Z => result(10)
    );
BUF_X1_70: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(11),
        Z => result(11)
    );
BUF_X1_71: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(12),
        Z => result(12)
    );
BUF_X1_72: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(13),
        Z => result(13)
    );
BUF_X1_73: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(14),
        Z => result(14)
    );
BUF_X1_74: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(15),
        Z => result(15)
    );
BUF_X1_75: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(16),
        Z => result(16)
    );
BUF_X1_76: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(17),
        Z => result(17)
    );
BUF_X1_77: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(18),
        Z => result(18)
    );
BUF_X1_78: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(19),
        Z => result(19)
    );
BUF_X1_79: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(2),
        Z => result(2)
    );
BUF_X1_80: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(20),
        Z => result(20)
    );
BUF_X1_81: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(21),
        Z => result(21)
    );
BUF_X1_82: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(22),
        Z => result(22)
    );
BUF_X1_83: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(23),
        Z => result(23)
    );
BUF_X1_84: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(24),
        Z => result(24)
    );
BUF_X1_85: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(25),
        Z => result(25)
    );
BUF_X1_86: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(26),
        Z => result(26)
    );
BUF_X1_87: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(27),
        Z => result(27)
    );
BUF_X1_88: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(28),
        Z => result(28)
    );
BUF_X1_89: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(29),
        Z => result(29)
    );
BUF_X1_90: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(3),
        Z => result(3)
    );
BUF_X1_91: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(30),
        Z => result(30)
    );
BUF_X1_92: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(31),
        Z => result(31)
    );
BUF_X1_93: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(4),
        Z => result(4)
    );
BUF_X1_94: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(5),
        Z => result(5)
    );
BUF_X1_95: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(6),
        Z => result(6)
    );
BUF_X1_96: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(7),
        Z => result(7)
    );
BUF_X1_97: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(8),
        Z => result(8)
    );
BUF_X1_98: ENTITY WORK.BUF_X1
    PORT MAP (
        A => S132(9),
        Z => result(9)
    );
BUF_X1_99: ENTITY WORK.BUF_X1
    PORT MAP (
        A => subsel,
        Z => S133
    );
$paramod\aftab_adder\size=s32'00000000000000000000000000100000_1: ENTITY WORK.$paramod\aftab_adder\size=s32'00000000000000000000000000100000
    PORT MAP (
        a(0) => S128(0),
        a(1) => S128(1),
        a(2) => S128(2),
        a(3) => S128(3),
        a(4) => S128(4),
        a(5) => S128(5),
        a(6) => S128(6),
        a(7) => S128(7),
        a(8) => S128(8),
        a(9) => S128(9),
        a(10) => S128(10),
        a(11) => S128(11),
        a(12) => S128(12),
        a(13) => S128(13),
        a(14) => S128(14),
        a(15) => S128(15),
        a(16) => S128(16),
        a(17) => S128(17),
        a(18) => S128(18),
        a(19) => S128(19),
        a(20) => S128(20),
        a(21) => S128(21),
        a(22) => S128(22),
        a(23) => S128(23),
        a(24) => S128(24),
        a(25) => S128(25),
        a(26) => S128(26),
        a(27) => S128(27),
        a(28) => S128(28),
        a(29) => S128(29),
        a(30) => S128(30),
        a(31) => S128(31),
        b(0) => bsel_0,
        b(1) => bsel_1,
        b(2) => bsel_2,
        b(3) => bsel_3,
        b(4) => bsel_4,
        b(5) => bsel_5,
        b(6) => bsel_6,
        b(7) => bsel_7,
        b(8) => bsel_8,
        b(9) => bsel_9,
        b(10) => bsel_10,
        b(11) => bsel_11,
        b(12) => bsel_12,
        b(13) => bsel_13,
        b(14) => bsel_14,
        b(15) => bsel_15,
        b(16) => bsel_16,
        b(17) => bsel_17,
        b(18) => bsel_18,
        b(19) => bsel_19,
        b(20) => bsel_20,
        b(21) => bsel_21,
        b(22) => bsel_22,
        b(23) => bsel_23,
        b(24) => bsel_24,
        b(25) => bsel_25,
        b(26) => bsel_26,
        b(27) => bsel_27,
        b(28) => bsel_28,
        b(29) => bsel_29,
        b(30) => bsel_30,
        b(31) => bsel_31,
        cin => S133,
        cout => S130,
        sum(0) => addSubRes_0,
        sum(1) => addSubRes_1,
        sum(2) => addSubRes_2,
        sum(3) => addSubRes_3,
        sum(4) => addSubRes_4,
        sum(5) => addSubRes_5,
        sum(6) => addSubRes_6,
        sum(7) => addSubRes_7,
        sum(8) => addSubRes_8,
        sum(9) => addSubRes_9,
        sum(10) => addSubRes_10,
        sum(11) => addSubRes_11,
        sum(12) => addSubRes_12,
        sum(13) => addSubRes_13,
        sum(14) => addSubRes_14,
        sum(15) => addSubRes_15,
        sum(16) => addSubRes_16,
        sum(17) => addSubRes_17,
        sum(18) => addSubRes_18,
        sum(19) => addSubRes_19,
        sum(20) => addSubRes_20,
        sum(21) => addSubRes_21,
        sum(22) => addSubRes_22,
        sum(23) => addSubRes_23,
        sum(24) => addSubRes_24,
        sum(25) => addSubRes_25,
        sum(26) => addSubRes_26,
        sum(27) => addSubRes_27,
        sum(28) => addSubRes_28,
        sum(29) => addSubRes_29,
        sum(30) => addSubRes_30,
        sum(31) => addSubRes_31
    );

END ARCHITECTURE arch;
