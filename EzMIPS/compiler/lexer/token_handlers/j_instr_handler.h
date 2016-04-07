#pragma once
#include "token_handler.h"

class j_instr_handler
	: public mips_token_handler
{
public:
	j_instr_handler(ParserCtxPtr ctx);
	~j_instr_handler(void);
	
	virtual mips_token_ptr parse_token(ParserCtxPtr ctx) override;
	
};

