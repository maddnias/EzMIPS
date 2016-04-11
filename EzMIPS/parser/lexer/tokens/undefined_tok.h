#pragma once
#include "../token.h"
#include <string>

#ifdef _WIN32
    #define identifier  L"UNDEFINED: "
#elif __linux__
    #define identifier  "UNDEFINED: "
#endif

class undefined_tok :
	public mips_token
{
public:
	undefined_tok(unsigned int tok_row, unsigned int tok_col);
	~undefined_tok(void);
};

