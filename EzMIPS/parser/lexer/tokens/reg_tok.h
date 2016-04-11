#pragma once
#include "../token.h"

#ifdef _WIN32
    #define identifier  L"OPERAND_REG: "
#elif __linux__
    #define identifier  "OPERAND_REG: "
#endif

class reg_tok :
	public mips_token
{
public:
	reg_tok(unsigned int tok_row, unsigned int tok_col);
	~reg_tok(void);
};

