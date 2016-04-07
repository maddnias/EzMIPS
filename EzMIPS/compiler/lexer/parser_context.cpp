#pragma once
#include "parser_context.h"

using namespace std;

parser_context::parser_context():
m_current_col(0),
m_current_row(0){

}

parser_context::parser_context(std::wistream &input):
	m_current_col(0),
	m_current_row(0),
	m_src_reader(new SourceReader(input)),
	m_parsed_tokens(new mips_tok_vector()){
}

parser_context::~parser_context(void){
	delete m_src_reader;
	delete m_parsed_tokens;
}

void parser_context::push_err(wstring err_desc){
	m_parser_errors.push_back(ParserErrorPtr(new ParserError(err_desc,
		m_current_row, m_current_col)));
}

void parser_context::push_token(mips_token_ptr token){
	m_parsed_tokens->push_back(token);
}

void parser_context::push_label(std::wstring label){
	m_label_pool.push_back(label);
}
	
bool parser_context::pool_contains_label(std::wstring label){
	for(vector<wstring>::iterator it = m_label_pool.begin();it != m_label_pool.end();it++){
		if(*it == label){
			return true;
		}
	}
	return false;
}

SourceReader* parser_context::get_src_reader(){
	return m_src_reader;
}

mips_tok_vector* parser_context::get_parsed_tokens(){
	return m_parsed_tokens;
}