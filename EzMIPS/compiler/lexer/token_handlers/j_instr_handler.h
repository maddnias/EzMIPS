#pragma once
#include "token_handler.h"

class j_instr_handler
	: public mips_token_handler
{
public:
	j_instr_handler(void);
	~j_instr_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx) override;
	
};

