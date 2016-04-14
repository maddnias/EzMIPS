#pragma once
#include "../parser/lexer/token.h"
#include "../parser/parser_context.h"
#include "../parser/file/source_reader.h"
#include "../parser/lexer/token_handlers/asm_directives_handler.h"
#include "../parser/lexer/token_handlers/r_instr_handler.h"
#include "../parser/lexer/token_handlers/j_instr_handler.h"
#include "../parser/lexer/token_handlers/i_instr_handler.h"
#include "../parser/lexer/token_handlers/pseudo_instr_handler.h"
#include "../parser/lexer/token_handlers/reg_handler.h"
#include "../parser/lexer/token_handlers/literal_handler.h"

#include <vector>
#include <fstream>
#include <memory>

enum LEXER_FLAGS{
	LEXER_FLAG_ALL = 0x1,
	LEXER_FLAG_LABEL = 0x2,
	LEXER_FLAG_DIRECTIVES = 0x4,
	LEXER_FLAG_INSTR = 0x8,
	LEXER_FLAG_LABEL_POOL = 0x10,
	LEXER_FLAG_OPERAND_REG = 0x20,
	LEXER_FLAG_LITERAL = 0x40
};

inline LEXER_FLAGS operator|(LEXER_FLAGS a, LEXER_FLAGS b){
	return static_cast<LEXER_FLAGS>(static_cast<int>(a) | static_cast<int>(b));
}

class mips_tokenizer
{
public:
	mips_tokenizer(void);
	~mips_tokenizer(void);

	mips_tok_vector parse_tokens(source_file *input);
private:
	/* functions */
	mips_token_ptr next_token(LEXER_FLAGS flags);

    std::string read_identifier();

	void init_tokenizer(source_file *input);
	void deinit_tokenizer();

	bool has_lexer_flag(LEXER_FLAGS input, LEXER_FLAGS tester);
    bool is_legal_label(std::string input);

	/* members */
	std::vector<source_file*> m_src_files;

	parser_ctx *m_ctx;
	asm_directives_handler m_asm_directives_handler;
	r_instr_handler m_r_instr_handler;
	j_instr_handler m_j_instr_handler;
	i_instr_handler m_i_instr_handler;
	pseudo_instr_handler m_pseudo_instr_handler;
	reg_handler m_reg_handler;
	literal_handler m_literal_handler;
};
