#pragma once

#include "..\token.h"
#include <string>

class undefined_tok :
	public mips_token
{
public:
	undefined_tok(unsigned int tok_row, unsigned int tok_col);
	~undefined_tok(void);
};

