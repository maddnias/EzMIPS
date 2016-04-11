#include "..\..\include\tokenizer.h"
#include "tokens\undefined_tok.h"
#include "tokens\label_decl_tok.h"
#include "tokens\label_ref_tok.h"
#include "tokens\reg_tok.h"
#include "instr_sets.h"

#include <cctype>
#include <sstream>
#include <list>

using namespace std;

#define get_src_reader m_ctx->get_src_reader

mips_tokenizer::mips_tokenizer(){
}

mips_tokenizer::~mips_tokenizer(){
	delete m_ctx;
}


mips_tok_vector mips_tokenizer::parse_tokens(source_file *input){
	init_tokenizer(input);
	// First pass to create label pool
	while(!get_src_reader()->is_eof()){
		next_token(LEXER_FLAG_LABEL_POOL);
	}
	get_src_reader()->reset();

	// Second pass to get all tokens
	while(!get_src_reader()->is_eof()){
		next_token(LEXER_FLAG_ALL);
	}
	mips_tok_vector output = *m_ctx->get_parsed_tokens();
	deinit_tokenizer();
	return output;
}

mips_token_ptr mips_tokenizer::next_token(LEXER_FLAGS flags){
	get_src_reader()->eat_whitespace();
	if(get_src_reader()->is_eof()){
		return NULL;
	}

	mips_token_ptr curTok;
	wchar_t curChar = get_src_reader()->peek();

	// Check if next token is an assembler directive
	// TODO: optimera
	if(has_lexer_flag(flags, LEXER_FLAG_DIRECTIVES) 
		&& curChar == '.'){
		for(list<wstring>::const_iterator it = asm_directives.begin();it != asm_directives.end();it++){
			if(get_src_reader()->matches_unique(*it)){
				if((curTok = m_asm_directives_handler.parse_token(*m_ctx, *it)) != NULL){
					m_ctx->push_token(curTok);
				}
				return curTok;
			}
		}
	}

	// Check if next token is an R-type instruction
	if(has_lexer_flag(flags, LEXER_FLAG_INSTR) 
		&& get_src_reader()->is_legal_identifier_start(curChar)){
		for(list<wstring>::const_iterator it = r_type_instructions.begin();it != r_type_instructions.end();it++){
			if(get_src_reader()->matches_unique(*it)){
				if((curTok = m_r_instr_handler.parse_token(*m_ctx, *it)) != NULL){
					m_ctx->push_token(curTok);
				}
				return curTok;
			}
		}
	}
	

	// Check if next token is a J-type instruction
	if(has_lexer_flag(flags, LEXER_FLAG_INSTR) 
		&& get_src_reader()->is_legal_identifier_start(curChar)){
		for(list<wstring>::const_iterator it = j_type_instructions.begin();it != j_type_instructions.end();it++){
			if(get_src_reader()->matches_unique(*it)){
				if((curTok = m_j_instr_handler.parse_token(*m_ctx, *it)) != NULL){
					m_ctx->push_token(curTok);
				}
				return curTok;
			}
		}
	}

	// Check if next token is a I-type instruction
	if(has_lexer_flag(flags, LEXER_FLAG_INSTR) 
		&& get_src_reader()->is_legal_identifier_start(curChar)){
		for(list<wstring>::const_iterator it = i_type_instructions.begin();it != i_type_instructions.end();it++){
			if(get_src_reader()->matches_unique(*it)){
				if((curTok = m_i_instr_handler.parse_token(*m_ctx, *it)) != NULL){
					m_ctx->push_token(curTok);
				}
				return curTok;
			}
		}
	}

	// Check if next token is a pseudo instruction
	if(has_lexer_flag(flags, LEXER_FLAG_INSTR) 
		&& get_src_reader()->is_legal_identifier_start(curChar)){
		for(list<wstring>::const_iterator it = pseudo_type_instructions.begin();it != pseudo_type_instructions.end();it++){
			if(get_src_reader()->matches_unique(*it)){
				curTok = m_pseudo_instr_handler.parse_token(*m_ctx, *it);
				if(curTok != NULL){
					m_ctx->push_token(curTok);
				}
				return curTok;
			}
		}
	}

	// Check if next token is a register
	if(has_lexer_flag(flags, LEXER_FLAG_OPERAND_REG)){
		if(curChar == '$'){
			if((curTok = m_reg_handler.parse_token(*m_ctx, L"")) != NULL){
				m_ctx->push_token(curTok);
				return curTok;
			}
		}
	}

	// Check if next token is a literal
	if(has_lexer_flag(flags, LEXER_FLAG_LITERAL)){
		if(curChar == '#'
			|| curChar == '"'
			|| get_src_reader()->is_integer(curChar)
			|| curChar == '-'){
				if((curTok = m_literal_handler.parse_token(*m_ctx, L"")) != NULL){
					m_ctx->push_token(curTok);
					return curTok;
				}
		}
	}
		
	// No known token was found
	curTok = mips_token_ptr(new undefined_tok(get_src_reader()->get_current_row(),
		get_src_reader()->get_current_col()));

	char curChar2;
	while(!iswspace(curChar2 = get_src_reader()->read()) && !get_src_reader()->is_eof()){
		// TODO: fix temporary , solution
		if(curChar2 == ','){
			return NULL;
		}
		// Potential label token
		if(curChar2 == ':'){
			if(has_lexer_flag(flags, LEXER_FLAG_LABEL_POOL)){
				if(is_legal_label(curTok->get_raw_tok())){
					m_ctx->push_label(curTok->get_raw_tok());
					curTok = NULL;
					return curTok;
				}
			} else if(has_lexer_flag(flags, LEXER_FLAG_LABEL)){
				if(is_legal_label(curTok->get_raw_tok())){
					wstring lbl = curTok->get_raw_tok();
					curTok = mips_token_ptr(new label_decl_tok(get_src_reader()->get_current_row(),
						get_src_reader()->get_current_col()));
					curTok->set_raw_tok(lbl);
					m_ctx->push_token(curTok);
					return curTok;
				}
			}
		}
		curTok->append_raw_tok(curChar2);
	}

	// Detect label reference
	if(get_src_reader()->is_legal_identifier_start(curChar)
		&& has_lexer_flag(flags, LEXER_FLAG_LABEL)){
			if(m_ctx->pool_contains_label(curTok->get_raw_tok())){
				wstring lbl = curTok->get_raw_tok();
				curTok = mips_token_ptr(new label_ref_tok(get_src_reader()->get_current_row(),
					get_src_reader()->get_current_col()));
				curTok->set_raw_tok(lbl);
				m_ctx->push_token(curTok);
				return curTok;
			}
	}

	if(!has_lexer_flag(flags, LEXER_FLAG_LABEL_POOL)){
		m_ctx->push_token(curTok);
	}
	return curTok;
}

wstring mips_tokenizer::read_identifier(){
	wstring outStr;
	/* we can do is_integer() since we know first char is a legal identifier start */
	while(get_src_reader()->is_integer(get_src_reader()->peek()) 
		|| get_src_reader()->is_legal_identifier_start(get_src_reader()->peek())){
		outStr.push_back(get_src_reader()->read());
	}
	return outStr;
}

void mips_tokenizer::init_tokenizer(source_file *input){
	m_ctx = new parser_ctx(input);
}

void mips_tokenizer::deinit_tokenizer(){
}

bool mips_tokenizer::has_lexer_flag(LEXER_FLAGS input, LEXER_FLAGS tester){
	if((input & LEXER_FLAG_ALL) == LEXER_FLAG_ALL){
		if(tester == LEXER_FLAG_LABEL_POOL){
			return false;
		}
		return true;
	}
	return (input & tester) == tester;
}

bool mips_tokenizer::is_legal_label(wstring input){
	if(!get_src_reader()->is_legal_identifier_start(input.at(0))){
		return false;
	}
	for(wstring::iterator it = input.begin()+1;it != input.end();it++){
		if(!get_src_reader()->is_legal_identifier_start(*it)
			&& !get_src_reader()->is_integer(*it)){
				return false;
		}
	}
	return true;
}