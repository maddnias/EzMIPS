#include "i_instr_tok.h"


i_instr_tok::i_instr_tok(INSTRUCTION_CODE code, unsigned int tok_row, unsigned int tok_col):
    instr_base_tok(code, INSTRUCTION_I, tok_row, tok_col)
{
}


i_instr_tok::~i_instr_tok(void)
{
}
