#include "j_instr_tok.h"


j_instr_tok::j_instr_tok(INSTRUCTION_CODE code, unsigned int tok_row, unsigned int tok_col):
    instr_base_tok(code, INSTRUCTION_J, tok_row, tok_col)
{
}


j_instr_tok::~j_instr_tok(void)
{
}
