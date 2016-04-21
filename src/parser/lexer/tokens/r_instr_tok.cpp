#include "r_instr_tok.h"


r_instr_tok::r_instr_tok(INSTRUCTION_CODE code, INSTRUCTION_TYPE type, unsigned int tok_row,
						 unsigned int tok_col):
    instr_base_tok(code, INSTRUCTION_R, tok_row, tok_col)
{
}


r_instr_tok::~r_instr_tok(void)
{
}
