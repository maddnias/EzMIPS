#include "instr_base_tok.h"


instr_base_tok::instr_base_tok(INSTRUCTION_TYPE type, unsigned int tok_row,
									 unsigned int tok_col, unsigned int op, unsigned int funct):
	mips_token(INSTR_TOK, tok_row, tok_col, L"INSTRUCTION: "),
		m_opcode(op),
		m_funct(funct)
{
}


instr_base_tok::~instr_base_tok(void)
{
}

void instr_base_tok::set_instr_type(INSTRUCTION_TYPE type){
	m_instr_type = type;
}

INSTRUCTION_TYPE instr_base_tok::get_instr_type(){
	return m_instr_type;
}
