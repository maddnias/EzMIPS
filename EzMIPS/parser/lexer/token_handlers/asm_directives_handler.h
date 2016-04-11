#pragma once
#include "token_handler.h"

class asm_directives_handler
	: public mips_token_handler
{
public:
	asm_directives_handler(void);
	~asm_directives_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, std::wstring buff) override;
	
};

