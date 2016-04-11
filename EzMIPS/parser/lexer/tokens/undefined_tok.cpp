
#include "undefined_tok.h"


undefined_tok::undefined_tok(unsigned int tok_row, unsigned int tok_col):
	mips_token(UNDEFINED_TOK, tok_row, tok_col, L"UNDEFINED: "){
}


undefined_tok::~undefined_tok(void){
}

