#ifndef PARSER_CONTEXT_H
#define PARSER_CONTEXT_H

#include "lexer/token.h"
#include "parser_error.h"
#include "file/source_reader.h"
#include "source_file.h"
#include <vector>
#include <string>
#include "thirdparty/format.h"

class parser_context{
public:
	parser_context(void);
	parser_context(source_file *input);
	~parser_context(void);

    void push_err(std::string err_desc, mips_token *tok);
    void push_err(parser_error *err);

    template <typename... Args>
    void push_err(mips_token *tok, const char *format,
                     const Args & ... args) {
      push_err(new parser_error(fmt::format(format, args...), tok,
                                tok->get_tok_row(), tok->get_tok_col()));
    }

    void push_token(mips_token *token);
	void push_label(std::string label);
	
	bool pool_contains_label(std::string label);

	source_reader* get_src_reader();
	mips_tok_vector* get_parsed_tokens();
    std::vector<parser_error*>* get_parser_errors();

private:
	unsigned int m_current_row;
	unsigned int m_current_col;
    std::vector<parser_error*> m_parser_errors;
	source_reader *m_src_reader;
	mips_tok_vector *m_parsed_tokens;
	std::vector<std::string> m_label_pool;
};

#endif
