#pragma once
#include "token_handler.h"

class literal_handler
	: public mips_token_handler
{
public:
	literal_handler(void);
	~literal_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, mips_str buff) override;
	
};

