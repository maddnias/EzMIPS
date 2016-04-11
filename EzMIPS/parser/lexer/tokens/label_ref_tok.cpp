#include "label_ref_tok.h"


label_ref_tok::label_ref_tok(unsigned int tok_row, unsigned int tok_col):
    mips_token(LABEL_REF_TOK, tok_row, tok_col, identifier)
{
}


label_ref_tok::~label_ref_tok(void)
{
}
