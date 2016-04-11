#include "token.h"
#include <string>

using namespace std;

mips_token::mips_token(TOKEN_TYPE tok_type, unsigned int tok_row, 
					   unsigned int tok_col, wstring formatted_prefix):
m_tok_type(tok_type),
m_tok_row(tok_row),
m_tok_col(tok_col),
m_formatted_prefix(formatted_prefix){
}

mips_token::~mips_token(void){
}

void mips_token::set_tok_type(TOKEN_TYPE type){
	m_tok_type = type;
}

TOKEN_TYPE mips_token::get_tok_type(){
	return m_tok_type;
}

void mips_token::set_tok_row(unsigned int tok_row){
	m_tok_row = tok_row;
}

unsigned int mips_token::get_tok_row(){
	return m_tok_row;
}

void mips_token::set_tok_col(unsigned int tok_col){
	m_tok_col = tok_col;
}

unsigned int mips_token::get_tok_col(){
	return m_tok_col;
}

void mips_token::set_raw_tok(std::wstring raw_tok){
	m_raw_tok = raw_tok;
}

std::wstring mips_token::get_raw_tok(){
	return m_raw_tok;
}

void mips_token::append_raw_tok(wchar_t chr){
	m_raw_tok += chr;
}

void mips_token::set_formatted_prefix(std::wstring prefix){
	m_formatted_prefix = prefix;
}
wstring mips_token::set_formatted_prefix(){
	return m_formatted_prefix;
}

std::wstring mips_token::get_formatted_token(){
	return m_formatted_prefix + m_raw_tok;
}

mips_token mips_token::operator+(const mips_token& other){
	wstring jointTok = m_raw_tok;
	jointTok = jointTok.append(other.m_raw_tok);
	set_raw_tok(jointTok);
	return *this;
}