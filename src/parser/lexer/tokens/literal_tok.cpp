#include "literal_tok.h"


literal_tok::literal_tok(LITERAL_TYPE type, unsigned int tok_row, unsigned int tok_col):
    mips_token(LITERAL_TOK, tok_row, tok_col, mips_null_str){
		switch(type){
		case LITERAL_TYPE_STRING:
            set_formatted_prefix(identifier_string);
			break;
		case LITERAL_TYPE_INT:
            set_formatted_prefix(identifier_int);
			break;
		case LITERAL_TYPE_COMMENT:
            set_formatted_prefix(identifier_comment);
			break;
		}
}


literal_tok::~literal_tok(void)
{
}

void literal_tok::set_type(LITERAL_TYPE directive){
	m_type = directive;
}

LITERAL_TYPE literal_tok::get_type(){
	return m_type;
}
