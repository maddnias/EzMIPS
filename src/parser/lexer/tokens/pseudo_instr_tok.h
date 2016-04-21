#ifndef PSEUDO_INSTR_TOK_H
#define PSEUDO_INSTR_TOK_H

#include "instr_base_tok.h"

class pseudo_instr_tok :
	public instr_base_tok
{
public:
    pseudo_instr_tok(INSTRUCTION_CODE code, unsigned int tok_row, unsigned int tok_col);
	~pseudo_instr_tok(void);
};

#endif
