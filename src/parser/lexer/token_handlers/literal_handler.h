#ifndef LITERAL_HANDLER_H
#define LITERAL_HANDLER_H

#include "token_handler.h"

class literal_handler
	: public mips_token_handler
{
public:
	literal_handler(void);
	~literal_handler(void);
	
    virtual mips_token* parse_token(parser_context &ctx, std::string buff) override;
	
};

#endif
