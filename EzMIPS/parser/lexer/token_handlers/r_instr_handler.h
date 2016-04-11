#pragma once
#include "token_handler.h"
class r_instr_handler :
	public mips_token_handler
{
public:
	r_instr_handler(void);
	~r_instr_handler(void);

	virtual mips_token_ptr parse_token(parser_ctx &ctx, std::wstring buff) override;
};

