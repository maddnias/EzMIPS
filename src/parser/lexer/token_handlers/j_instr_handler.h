#pragma once
#include "token_handler.h"

#ifdef _WIN32
    #define instr_j "j"
    #define instr_jal "ja"
#elif __linux__
    #define instr_j "j"
    #define instr_jal "ja"
#endif

class j_instr_handler
	: public mips_token_handler
{
public:
	j_instr_handler(void);
	~j_instr_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, mips_str buff) override;
	
};

