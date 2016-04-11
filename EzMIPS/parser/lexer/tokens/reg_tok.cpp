#include "reg_tok.h"


reg_tok::reg_tok(unsigned int tok_row, unsigned int tok_col):
	mips_token(REG_TOK, tok_row, tok_col, L"OPERAND_REG: ")
{
}


reg_tok::~reg_tok(void)
{
}
