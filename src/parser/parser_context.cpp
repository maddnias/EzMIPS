#include "parser_context.h"
#include <algorithm>

using namespace std;

parser_context::parser_context():
m_current_col(0),
m_current_row(0){

}

parser_context::parser_context(source_file *input):
	m_current_col(0),
	m_current_row(0),
	m_src_reader(new source_reader(input)),
	m_parsed_tokens(new mips_tok_vector()){
}

parser_context::~parser_context(void){
	delete m_src_reader;
    for(mips_tok_vector::iterator it = m_parsed_tokens->begin();
        it != m_parsed_tokens->end();it++){
        delete *it;
    }
    for(vector<parser_error*>::iterator it = m_parser_errors.begin();
        it != m_parser_errors.end();it++){
        delete *it;
    }
	delete m_parsed_tokens;
}

void parser_context::push_err(std::string err_desc, mips_token *tok){
    m_parser_errors.push_back(new parser_error(err_desc, tok,
                                               m_current_row, m_current_col));
}

void parser_context::push_err(parser_error *err)
{
    m_parser_errors.push_back(err);
}


void parser_context::push_token(mips_token* token){
	m_parsed_tokens->push_back(token);
}

void parser_context::push_label(std::string label){
	m_label_pool.push_back(label);
}
	
bool parser_context::pool_contains_label(std::string label){
	return std::find(m_label_pool.begin(), m_label_pool.end(), label) != m_label_pool.end();
	//for(vector<std::string>::iterator it = m_label_pool.begin();it != m_label_pool.end();it++){
	//	if(*it == label){
	//		return true;
	//	}
	//}
	//return false;
}

source_reader* parser_context::get_src_reader(){
	return m_src_reader;
}

//TODO: make m_parsed_tokens non-pointer
mips_tok_vector* parser_context::get_parsed_tokens(){
    return m_parsed_tokens;
}

std::vector<parser_error *>* parser_context::get_parser_errors(){
    return &m_parser_errors;
}
