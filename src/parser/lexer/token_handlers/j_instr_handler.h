#pragma once
#include "token_handler.h"

#define instr_j "j"
#define instr_jal "ja"

class j_instr_handler
	: public mips_token_handler
{
public:
	j_instr_handler(void);
	~j_instr_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, std::string buff) override;
	
};

