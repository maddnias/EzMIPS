#include "instr_base_tok.h"


instr_base_tok::instr_base_tok(INSTRUCTION_TYPE type, 
							   unsigned int tok_row, unsigned int tok_col):
	mips_token(INSTR_TOK, tok_row, tok_col, L"PLACEHOLDER: ")
{
	switch(type){
	case INSTRUCTION_I:
		this->set_formatted_prefix(L"INSTRUCTION_I: ");
		break;
	case INSTRUCTION_J:
		this->set_formatted_prefix(L"INSTRUCTION_J: ");
		break;
	case INSTRUCTION_PSEUDO:
		this->set_formatted_prefix(L"INSTRUCTION_PSEUDO: ");
		break;
	case INSTRUCTION_R:
		this->set_formatted_prefix(L"INSTRUCTION_R: ");
		break;
	}
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
