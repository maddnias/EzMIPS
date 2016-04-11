#pragma once
#include "instr_base_tok.h"

class j_instr_tok :
	public instr_base_tok
{
public:
	j_instr_tok(unsigned int tok_row, unsigned int tok_col);
	~j_instr_tok(void);
};

