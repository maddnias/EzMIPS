#include "j_instr_handler.h"
#include "..\tokens\j_instr_tok.h"
#include "..\tokens\asm_directive_tok.h"

#include <list>

using namespace std;

j_instr_handler::j_instr_handler(){

}


j_instr_handler::~j_instr_handler(void) {
}

mips_token_ptr j_instr_handler::parse_token(parser_ctx &ctx, wstring buff){
	if(ctx.get_src_reader()->peek() != 'j'){
		return false;
	}
	
	bool successFlag = true;	
	j_instr_tok *tok = NULL;

	if(buff == L"j"){
		tok = new j_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"j");
		ctx.get_src_reader()->advance(1);

	} else if (buff == L"jal"){
		tok = new j_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"jal");
		ctx.get_src_reader()->advance(3);

	} else {
		return NULL;
	}

	return mips_token_ptr(tok);
}