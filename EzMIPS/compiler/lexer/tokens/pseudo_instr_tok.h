#pragma once
#include "instr_base_tok.h"

class pseudo_instr_tok :
	public instr_base_tok
{
public:
	pseudo_instr_tok(INSTRUCTION_TYPE type, unsigned int tok_row,
		unsigned int tok_col);
	~pseudo_instr_tok(void);
};

