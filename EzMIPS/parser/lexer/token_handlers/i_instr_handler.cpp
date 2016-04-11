#include "i_instr_handler.h"
#include "..\tokens\i_instr_tok.h"

#include <list>

using namespace std;

i_instr_handler::i_instr_handler(){

}


i_instr_handler::~i_instr_handler(void) {
}

mips_token_ptr i_instr_handler::parse_token(parser_ctx &ctx, std::wstring buff){	
	bool successFlag = true;	
	i_instr_tok *tok = NULL;

	if(buff == L"addi"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"addi");
		ctx.get_src_reader()->advance(4);
	} else if(buff == L"addiu"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"addiu");
		ctx.get_src_reader()->advance(5);

	} else if(buff == L"beq"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"beq");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"bne"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"bne");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"lbu"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"lbu");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"lhu"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"lhu");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"lui"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"lui");
		ctx.get_src_reader()->advance(3);

	} else if(buff == L"lw"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"lw");
		ctx.get_src_reader()->advance(2);

	} else if(buff == L"sb"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"sb");
		ctx.get_src_reader()->advance(2);

	} else if(buff == L"sh"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"sh");
		ctx.get_src_reader()->advance(2);

	} else if(buff == L"slti"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"slti");
		ctx.get_src_reader()->advance(4);

	} else if(buff == L"sltiu"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"sltiu");
		ctx.get_src_reader()->advance(5);

	} else if(buff == L"sw"){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		tok->set_raw_tok(L"sw");
		ctx.get_src_reader()->advance(2);

	} else {
		return NULL;
	}

	return mips_token_ptr(tok);
}