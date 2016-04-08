#pragma once
#include "instr_base_tok.h"
class i_instr_tok :
	public instr_base_tok
{
public:
	i_instr_tok(unsigned int tok_row, unsigned int tok_col);
	~i_instr_tok(void);
};

