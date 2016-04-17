#ifndef J_INSTR_HANDLER_H
#define J_INSTR_HANDLER_H

#include "token_handler.h"

#define instr_j "j"
#define instr_jal "ja"

class j_instr_handler
	: public mips_token_handler
{
public:
	j_instr_handler(void);
	~j_instr_handler(void);
	
    virtual mips_token* parse_token(parser_context &ctx, std::string buff) override;
	
};

#endif
