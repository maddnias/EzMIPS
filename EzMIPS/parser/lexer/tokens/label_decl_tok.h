#pragma once
#include "../token.h"

#ifdef _WIN32
    #define identifier L"LABEL_DECL: "
#elif __linux__
    #define identifier "LABEL_DECL: "
#endif

class label_decl_tok :
	public mips_token
{
public:
	label_decl_tok(unsigned int tok_row, unsigned int tok_col);
	~label_decl_tok(void);
};

