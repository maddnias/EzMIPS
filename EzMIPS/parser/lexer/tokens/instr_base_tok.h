#pragma once
#include "..\token.h"

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

