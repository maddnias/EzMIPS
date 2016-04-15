#ifndef UNDEFINED_TOK_H
#define UNDEFINED_TOK_H

#include "../token.h"
#include <string>

#define identifier  "UNDEFINED: "

class undefined_tok :
	public mips_token
{
public:
	undefined_tok(unsigned int tok_row, unsigned int tok_col);
	~undefined_tok(void);
};

#endif
