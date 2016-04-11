#pragma once
#include "..\token.h"

class label_decl_tok :
	public mips_token
{
public:
	label_decl_tok(unsigned int tok_row, unsigned int tok_col);
	~label_decl_tok(void);
};

