#pragma once
#include "token_handler.h"

class i_instr_handler
	: public mips_token_handler
{
public:
	i_instr_handler(void);
	~i_instr_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, std::wstring buff) override;
	
};

