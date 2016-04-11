#pragma once
#include "token_handler.h"

class pseudo_instr_handler
	: public mips_token_handler
{
public:
	pseudo_instr_handler(void);
	~pseudo_instr_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, std::wstring buff) override;
	
};

