#include "parser_error.h"

using namespace std;

ParserError::ParserError(std::wstring error_desc, unsigned int err_row,
						 unsigned int err_col):
m_err_desc(error_desc),
m_err_row(err_row),
m_err_col(err_col){
	
}


ParserError::~ParserError(void){
}

std::wstring ParserError::get_err_desc(){
	return m_err_desc;
}