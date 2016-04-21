#include "pseudo_instr_tok.h"


pseudo_instr_tok::pseudo_instr_tok(INSTRUCTION_CODE code, unsigned int tok_row, unsigned int tok_col):
instr_base_tok(code, INSTRUCTION_PSEUDO, tok_row, tok_col)
{
}


pseudo_instr_tok::~pseudo_instr_tok(void)
{
}
