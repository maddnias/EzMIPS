#pragma once
#include "../token.h"

#ifdef _WIN32
    #define identifier L"LABEL_REF: "
#elif __linux__
    #define identifier "LABEL_REF: "
#endif

class label_ref_tok :
	public mips_token
{
public:
	label_ref_tok(unsigned int tok_row, unsigned int tok_col);
	~label_ref_tok(void);
};

