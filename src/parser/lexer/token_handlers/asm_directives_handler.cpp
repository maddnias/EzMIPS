#include "asm_directives_handler.h"
#include "../tokens/asm_directive_tok.h"

#include <list>

using namespace std;

asm_directives_handler::asm_directives_handler(){

}


asm_directives_handler::~asm_directives_handler(void) {
}

mips_token_ptr asm_directives_handler::parse_token(parser_ctx &ctx, std::string buff){
	if(ctx.get_src_reader()->peek() != '.'){
		return false;
	}

	// Advance past '.'
	ctx.get_src_reader()->advance(1);	
	asm_directive_tok *tok = NULL;

    if(buff == align_directive){
		tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(align_directive);
		tok->set_directive(DIRECTIVE_ALIGN);
		ctx.get_src_reader()->advance(5);

    } else if(buff == asciiz_directive){
		tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(asciiz_directive);
		tok->set_directive(DIRECTIVE_ASCIIZ);
		ctx.get_src_reader()->advance(6);

    } else if(buff == ascii_directive){
		tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(ascii_directive);
		tok->set_directive(DIRECTIVE_ASCII);
		ctx.get_src_reader()->advance(5);

    } else if(buff == data_directive){
		tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(data_directive);
		tok->set_directive(DIRECTIVE_DATA);
		ctx.get_src_reader()->advance(4);

    } else if(buff == text_directive){
		tok = new asm_directive_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(text_directive);
		tok->set_directive(DIRECTIVE_TEXT);
		ctx.get_src_reader()->advance(4);
	} else {
		return NULL;
	}

	return mips_token_ptr(tok);
}
