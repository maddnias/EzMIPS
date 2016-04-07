#include "j_instr_handler.h"
#include "..\tokens\j_instr_tok.h"
#include "..\tokens\asm_directive_tok.h"

#include <list>

using namespace std;

j_instr_handler::j_instr_handler(ParserCtxPtr ctx):
	mips_token_handler(ctx){

}


j_instr_handler::~j_instr_handler(void) {
}

mips_token_ptr j_instr_handler::parse_token(ParserCtxPtr ctx){
	if(ctx->get_src_reader()->peek() != 'j'){
		return false;
	}
	
	bool successFlag = true;	
	j_instr_tok *tok = NULL;

	if(ctx->get_src_reader()->matches_unique(L"j")){
		tok = new j_instr_tok(INSTRUCTION_J, ctx->get_src_reader()->get_current_row(),
			ctx->get_src_reader()->get_current_col(), 0x02, 0xFF);
		tok->set_raw_tok(L"j");
		ctx->get_src_reader()->advance(1);
	} else if(ctx->get_src_reader()->matches_unique(L"jal")){
		tok = new j_instr_tok(INSTRUCTION_J, ctx->get_src_reader()->get_current_row(),
			ctx->get_src_reader()->get_current_col(), 0x03, 0xFF);
		tok->set_raw_tok(L"jal");
		ctx->get_src_reader()->advance(3);
	}

	successFlag = tok != NULL;
	if(successFlag){
		return mips_token_ptr(tok);
	} 
	return NULL;
}