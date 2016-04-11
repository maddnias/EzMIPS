#pragma once

#include "../../parser_context.h"
#include "../../file/source_reader.h"

#include <memory>

class mips_token_handler
{
public:
	mips_token_handler(void);
	~mips_token_handler(void);

	virtual mips_token_ptr parse_token(parser_ctx &ctx, mips_str buff) = 0;
	std::string get_formatted_token();

private:

};

typedef std::shared_ptr<mips_token_handler> mips_token_handlerPtr;

