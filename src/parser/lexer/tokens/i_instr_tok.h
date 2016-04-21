#ifndef I_INSTR_TOK_H
#define I_INSTR_TOK_H

#include "instr_base_tok.h"
class i_instr_tok :
	public instr_base_tok
{
public:
    i_instr_tok(INSTRUCTION_CODE code, unsigned int tok_row, unsigned int tok_col);
	~i_instr_tok(void);
};

#endif
