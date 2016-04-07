#include "asm_directives_handler.h"
#include "..\tokens\asm_directive_tok.h"

#include <list>

using namespace std;

asm_directives_handler::asm_directives_handler(){

}


asm_directives_handler::~asm_directives_handler(void) {
}

mips_token_ptr asm_directives_handler::parse_token(parser_ctx &ctx){
	if(ctx.get_src_reader()->peek() != '.'){
		return false;
	}

	// Advance past '.'
	ctx.get_src_reader()->advance(1);
	
	bool successFlag = true;
	int curCol = ctx.get_src_reader()->get_current_col();
	int firstChar = ctx.get_src_reader()->peek();
	
	asm_directive_tok *tok = NULL;

	switch(firstChar){
	case 'a':
		if(ctx.get_src_reader()->matches_unique(L"align")){
			tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
				ctx.get_src_reader()->get_current_col());
			tok->set_raw_tok(L".align");
			tok->set_directive(DIRECTIVE_ALIGN);
			ctx.get_src_reader()->advance(5);
			break;

		} else if(ctx.get_src_reader()->matches_unique(L"asciiz")){
			tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
				ctx.get_src_reader()->get_current_col());
			tok->set_raw_tok(L".asciiz");
			tok->set_directive(DIRECTIVE_ASCIIZ);
			ctx.get_src_reader()->advance(6);
			break;
		} else if(ctx.get_src_reader()->matches_unique(L"ascii")){
			tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
				ctx.get_src_reader()->get_current_col());
			tok->set_raw_tok(L".ascii");
			tok->set_directive(DIRECTIVE_ASCII);
			ctx.get_src_reader()->advance(5);
			break;
		} else {
			// TODO: go back approtiate
			successFlag = false;
		}

		break;
	case 'd':
		if(ctx.get_src_reader()->matches_unique(L"data")){
			tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
				ctx.get_src_reader()->get_current_col());
			tok->set_raw_tok(L".data");
			tok->set_directive(DIRECTIVE_DATA);
			ctx.get_src_reader()->advance(4);
			break;
		}
		break;
	case 't':
		if(ctx.get_src_reader()->matches_unique(L"text")){
			tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
				ctx.get_src_reader()->get_current_col());
			tok->set_raw_tok(L".text");
			tok->set_directive(DIRECTIVE_TEXT);
			ctx.get_src_reader()->advance(4);
			break;
		}
		break;

	default:

		break;
	}

	successFlag = tok != NULL;
	if(successFlag){
		return mips_token_ptr(tok);
	}

	return NULL;
}