#include "label_decl_tok.h"


label_decl_tok::label_decl_tok(unsigned int tok_row, unsigned int tok_col):
    mips_token(LABEL_DECL_TOK, tok_row, tok_col, identifier)
{
}


label_decl_tok::~label_decl_tok(void)
{
}
