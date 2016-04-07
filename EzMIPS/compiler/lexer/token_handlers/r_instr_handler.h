#pragma once
#include "token_handler.h"
class r_instr_handler :
	public mips_token_handler
{
public:
	r_instr_handler(ParserCtxPtr ctx);
	~r_instr_handler(void);

	virtual mips_token_ptr parse_token(ParserCtxPtr ctx) override;
};

