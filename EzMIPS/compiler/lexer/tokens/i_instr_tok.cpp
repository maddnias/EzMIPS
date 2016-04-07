#include "i_instr_tok.h"


i_instr_tok::i_instr_tok(INSTRUCTION_TYPE type, unsigned int tok_row,
						 unsigned int tok_col, unsigned int op, unsigned int funct):
	instr_base_tok(INSTRUCTION_I, tok_row, tok_col, op, funct)
{
}


i_instr_tok::~i_instr_tok(void)
{
}
