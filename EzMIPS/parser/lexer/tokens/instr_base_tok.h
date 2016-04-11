#pragma once
#include "../token.h"

#ifdef _WIN32
    #define identifier_i L"INSTRUCTION_I: "
    #define identifier_j L"INSTRUCTION_J: "
    #define identifier_pseudo L"INSTRUCTION_PSEUDO: "
    #define identifier_r L"INSTRUCTION_R: "
#elif __linux__
    #define identifier_i "INSTRUCTION_I: "
    #define identifier_j "INSTRUCTION_J: "
    #define identifier_pseudo "INSTRUCTION_PSEUDO: "
    #define identifier_r "INSTRUCTION_R: "
#endif

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
	instr_base_tok(INSTRUCTION_TYPE type, unsigned int tok_row,
		unsigned int tok_col);
	~instr_base_tok(void);

	void set_instr_type(INSTRUCTION_TYPE type);
	INSTRUCTION_TYPE get_instr_type();

private:
	INSTRUCTION_TYPE m_instr_type;
};

