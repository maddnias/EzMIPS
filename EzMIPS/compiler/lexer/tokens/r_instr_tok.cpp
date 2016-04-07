#include "r_instr_tok.h"


r_instr_tok::r_instr_tok(INSTRUCTION_TYPE type, unsigned int tok_row,
						 unsigned int tok_col, unsigned int op, unsigned int funct):
	instr_base_tok(INSTRUCTION_R, tok_row, tok_col, op, funct)
{
}


r_instr_tok::~r_instr_tok(void)
{
}
