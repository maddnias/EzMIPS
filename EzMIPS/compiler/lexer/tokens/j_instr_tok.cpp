#include "j_instr_tok.h"


j_instr_tok::j_instr_tok(INSTRUCTION_TYPE type, unsigned int tok_row,
						 unsigned int tok_col, unsigned int op, unsigned int funct):
	instr_base_tok(INSTRUCTION_I, tok_row, tok_col, op, funct)
{
}


j_instr_tok::~j_instr_tok(void)
{
}