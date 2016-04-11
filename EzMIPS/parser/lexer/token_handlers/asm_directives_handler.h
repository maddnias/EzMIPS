#pragma once
#include "token_handler.h"

//TODO: better solution?
#ifdef _WIN32
    #define align_directive L".align"
    #define asciiz_directive L".asciiz"
    #define ascii_directive L".ascii"
    #define data_directive L".data"
    #define text_directive L".text"
#elif __linux__
    #define align_directive ".align"
    #define asciiz_directive ".asciiz"
    #define ascii_directive ".ascii"
    #define data_directive ".data"
    #define text_directive ".text"
#endif

class asm_directives_handler
	: public mips_token_handler
{
public:
	asm_directives_handler(void);
	~asm_directives_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, mips_str buff) override;
	
};

