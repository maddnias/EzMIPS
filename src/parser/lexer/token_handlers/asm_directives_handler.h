#ifndef ASM_DIRECTIVES_HANDLER_H
#define ASM_DIRECTIVES_HANDLER_H

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
	
    virtual mips_token* parse_token(parser_context &ctx, std::string buff) override;
	
};

#endif
