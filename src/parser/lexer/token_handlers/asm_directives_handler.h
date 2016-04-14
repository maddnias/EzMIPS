#pragma once
#include "token_handler.h"

#define align_directive ".align"
#define asciiz_directive ".asciiz"
#define ascii_directive ".ascii"
#define data_directive ".data"
#define text_directive ".text"

class asm_directives_handler
	: public mips_token_handler
{
public:
	asm_directives_handler(void);
	~asm_directives_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, std::string buff) override;
	
};

