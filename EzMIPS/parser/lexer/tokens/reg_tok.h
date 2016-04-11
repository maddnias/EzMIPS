#pragma once
#include "..\token.h"

class reg_tok :
	public mips_token
{
public:
	reg_tok(unsigned int tok_row, unsigned int tok_col);
	~reg_tok(void);
};

