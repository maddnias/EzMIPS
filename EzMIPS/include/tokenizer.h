#pragma once
#include "..\compiler\lexer\token.h"
#include "..\compiler\lexer\parser_context.h"
#include "..\compiler\lexer\source_reader.h"
#include "..\compiler\lexer\token_handlers\asm_directives_handler.h"
#include "..\compiler\lexer\token_handlers\r_instr_handler.h"
#include "..\compiler\lexer\token_handlers\j_instr_handler.h"
#include "..\compiler\lexer\token_handlers\reg_handler.h"

#include <vector>
#include <fstream>
#include <memory>

enum LEXER_FLAGS{
	LEXER_FLAG_ALL = 0x1,
	LEXER_FLAG_LABEL = 0x2,
	LEXER_FLAG_DIRECTIVES = 0x4,
	LEXER_FLAG_INSTR = 0x8,
	LEXER_FLAG_LABEL_POOL = 0x10,
	LEXER_FLAG_OPERAND_REG = 0x20
};

inline LEXER_FLAGS operator|(LEXER_FLAGS a, LEXER_FLAGS b){
	return static_cast<LEXER_FLAGS>(static_cast<int>(a) | static_cast<int>(b));
}

class mips_tokenizer
{
public:
	mips_tokenizer(void);
	mips_tok_vector parse_tokens(std::wistream &input);
private:
	/* functions */
	mips_token_ptr next_token(LEXER_FLAGS flags);

	std::wstring read_identifier();

	void init_tokenizer(std::wistream &input);
	void deinit_tokenizer();

	bool has_lexer_flag(LEXER_FLAGS input, LEXER_FLAGS tester);
	bool is_legal_label(std::wstring input);

	/* members */
	parser_ctx *m_ctx;
	asm_directives_handler m_asm_directives_handler;
	r_instr_handler m_r_instr_handler;
	j_instr_handler j_r_instr_handler;
	reg_handler m_reg_handler;
};
