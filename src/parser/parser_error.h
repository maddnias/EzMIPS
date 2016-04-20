#ifndef PARSER_ERROR_H
#define PARSER_ERROR_H

#include <string>
#include <vector>
#include "lexer/token.h"
#include <memory>

class parser_error
{
public:
    parser_error(std::string err_desc, mips_token *tok, unsigned int err_row,
		unsigned int err_col);
    ~parser_error(void);

    mips_token* get_tok();
    std::string get_error_desc();
    unsigned int get_error_row();
    unsigned int get_error_col();

private:
    mips_token *m_tok;
	std::string m_err_desc;
	unsigned int m_err_row;
	unsigned int m_err_col;
};

#endif
