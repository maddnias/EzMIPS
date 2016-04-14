#pragma once
#include "../token.h"

#define identifier "LABEL_REF: "

class label_ref_tok :
	public mips_token
{
public:
	label_ref_tok(unsigned int tok_row, unsigned int tok_col);
	~label_ref_tok(void);
};

