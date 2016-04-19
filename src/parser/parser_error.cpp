#include "parser_error.h"

using namespace std;

parser_error::parser_error(std::string error_desc, unsigned int err_row,
						 unsigned int err_col):
m_err_desc(error_desc),
m_err_row(err_row),
m_err_col(err_col){
	
}


parser_error::~parser_error(void){
}

std::string parser_error::get_error_desc(){
    return m_err_desc;
}

unsigned int parser_error::get_error_row(){
    return m_err_row;
}

unsigned int parser_error::get_error_col(){
    return m_err_col;
}
