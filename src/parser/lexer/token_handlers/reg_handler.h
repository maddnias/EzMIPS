#ifndef REG_HANDLER_H
#define REG_HANDLER_H

#include "token_handler.h"

#define reg_at      "$at"
#define reg_zero    "$zero"
#define reg_sp      "$sp"
#define reg_gp      "$gp"
#define reg_fp      "$fp"
#define reg_ra      "$ra"

class reg_handler
	: public mips_token_handler
{
public:
	reg_handler(void);
	~reg_handler(void);
	
    virtual mips_token* parse_token(parser_context &ctx, std::string buff) override;

private:
	int parse_reg_number(std::string &buff, parser_context &ctx);
};

#endif
