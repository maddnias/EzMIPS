#pragma once
#include "token_handler.h"

class reg_handler
	: public mips_token_handler
{
public:
	reg_handler(void);
	~reg_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, std::wstring buff) override;

private:
	int parse_reg_number(std::wstring &buff, parser_context &ctx);
};

