#include "pseudo_instr_handler.h"
#include "../tokens/pseudo_instr_tok.h"

#include <list>

using namespace std;

pseudo_instr_handler::pseudo_instr_handler(){

}


pseudo_instr_handler::~pseudo_instr_handler(void) {
}

mips_token_ptr pseudo_instr_handler::parse_token(parser_ctx &ctx, mips_str buff){	
	bool successFlag = true;	
	pseudo_instr_tok *tok = NULL;

    if(buff == instr_blt){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_blt);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_bgt){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_bgt);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_ble){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_ble);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_neg){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_neg);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_not){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_not);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_bge){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_bge);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_li){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_li);
		ctx.get_src_reader()->advance(2);

    } else if(buff == instr_la){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_la);
		ctx.get_src_reader()->advance(2);

    } else if(buff == instr_move){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_move);
		ctx.get_src_reader()->advance(4);

    } else if(buff == instr_sge){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_sge);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_sgt){
		tok = new pseudo_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_sgt);
		ctx.get_src_reader()->advance(3);

	} else {
		return NULL;
	}

	return mips_token_ptr(tok);
}
