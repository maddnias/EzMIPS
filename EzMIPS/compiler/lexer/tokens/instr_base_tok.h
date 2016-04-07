#pragma once
#include "..\token.h"

enum INSTRUCTION_TYPE{
	INSTRUCTION_R = 0,
	INSTRUCTION_I = 1,
	INSTRUCTION_J = 2,
	INSTRUCTION_PSEUDO = 4
};

class instr_base_tok :
	public mips_token
{
public:
	instr_base_tok(INSTRUCTION_TYPE type, unsigned int tok_row,
		unsigned int tok_col, unsigned int op, unsigned int funct);
	~instr_base_tok(void);

	void set_instr_type(INSTRUCTION_TYPE type);
	INSTRUCTION_TYPE get_instr_type();

	void set_opcode(unsigned int op);
	unsigned int get_opcode();

	void set_funct(unsigned int funct);
	unsigned int get_funct();

private:
	INSTRUCTION_TYPE m_instr_type;
	unsigned int m_opcode;
	unsigned int m_funct;
};

