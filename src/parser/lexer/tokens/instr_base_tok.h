#ifndef INSTR_BASE_TOK_H
#define INSTR_BASE_TOK_H

#include "../token.h"

enum INSTRUCTION_CODE{
    ADD = 0,
    ADDI = 1,
    ADDU = 2,
    ADDIU = 3,
    SRA = 4,
    AND = 5,
    ANDI = 6,
    NOR = 7,
    OR = 8,
    ORI = 9,
    XOR = 10,
    BEQ = 11,
    BNE = 12,
    DIV = 13,
    JAL = 14,
    J = 15,
    JR = 16,
    LBU = 17,
    LHU = 18,
    LUI = 19,
    LW = 20,
    SLL = 21,
    SRL = 22,
    MFC0 = 23,
    MFHI = 24,
    MFLO = 25,
    MULT = 26,
    SLT = 27,
    SLTI = 28,
    SLTU = 29,
    SLTIU = 30,
    SB = 31,
    SH = 32,
    SW = 33,
    SUB = 34,
    DIVU = 35,
    MULTU = 36,
    SUBU = 37,
    BLT = 38,
    BGT = 39,
    BLE = 40,
    NEG = 41,
    NOT = 42,
    BGE = 43,
    LI = 44,
    LA = 45,
    MOVE = 46,
    SGE = 47,
    SGT = 48
};

#define identifier_i "INSTRUCTION_I: "
#define identifier_j "INSTRUCTION_J: "
#define identifier_pseudo "INSTRUCTION_PSEUDO: "
#define identifier_r "INSTRUCTION_R: "

enum INSTRUCTION_TYPE{
	INSTRUCTION_I = 0x1,
	INSTRUCTION_J = 0x2,
	INSTRUCTION_PSEUDO = 0x4,
	INSTRUCTION_R = 0x8,
};

class instr_base_tok :
	public mips_token
{
public:
    instr_base_tok(INSTRUCTION_CODE code, INSTRUCTION_TYPE type, unsigned int tok_row,
		unsigned int tok_col);
	~instr_base_tok(void);

	void set_instr_type(INSTRUCTION_TYPE type);
	INSTRUCTION_TYPE get_instr_type();

    INSTRUCTION_CODE get_instr_code();
private:
	INSTRUCTION_TYPE m_instr_type;
    INSTRUCTION_CODE m_instr_code;
};

#endif
