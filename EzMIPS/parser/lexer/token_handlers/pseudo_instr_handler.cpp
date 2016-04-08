#include "pseudo_instr_handler.h"
#include "..\tokens\pseudo_instr_tok.h"

#include <list>

using namespace std;

pseudo_instr_handler::pseudo_instr_handler(){

}


pseudo_instr_handler::~pseudo_instr_handler(void) {
}

mips_token_ptr pseudo_instr_handler::parse_token(parser_ctx &ctx, wstring buff){	
	bool successFlag = true;	
	pseudo_instr_tok *tok = NULL;

	if(buff == L"blt"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"blt");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"bgt"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"bgt");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"ble"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"ble");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"neg"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"neg");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"not"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"not");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"bge"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"bge");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"li"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"li");
		ctx.get_src_reader()->advance(2);

	} else if(buff == L"la"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"la");
		ctx.get_src_reader()->advance(2);

	} else if(buff == L"move"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"move");
		ctx.get_src_reader()->advance(4);

	} else if(buff == L"sge"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"sge");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"sgt"){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"sgt");
		ctx.get_src_reader()->advance(3);

	} else {
		return NULL;
	}

	return mips_token_ptr(tok);
}