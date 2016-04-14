#pragma once
#include "platform_dependencies.h"
#include "token_handler.h"

#ifdef _WIN32
    #define reg_at      "$at"
    #define reg_zero    "$zero"
    #define reg_sp      "$sp"
    #define reg_gp      "$gp"
    #define reg_fp      "$fp"
    #define reg_ra      "$ra"
#elif __linux__
    #define reg_at      "$at"
    #define reg_zero    "$zero"
    #define reg_sp      "$sp"
    #define reg_gp      "$gp"
    #define reg_fp      "$fp"
    #define reg_ra      "$ra"
#endif

class reg_handler
	: public mips_token_handler
{
public:
	reg_handler(void);
	~reg_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, mips_str buff) override;

private:
	int parse_reg_number(mips_str &buff, parser_context &ctx);
};

