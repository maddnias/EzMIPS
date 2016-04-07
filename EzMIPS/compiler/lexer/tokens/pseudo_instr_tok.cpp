#include "pseudo_instr_tok.h"


pseudo_instr_tok::pseudo_instr_tok(INSTRUCTION_TYPE type, unsigned int tok_row,
						 unsigned int tok_col, unsigned int op, unsigned int funct):
	instr_base_tok(INSTRUCTION_I, tok_row, tok_col, op, funct)
{
}


pseudo_instr_tok::~pseudo_instr_tok(void)
{
}
