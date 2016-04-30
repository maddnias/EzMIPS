#include "reg_handler.h"
#include "../tokens/reg_tok.h"

#include <list>

using namespace std;

reg_handler::reg_handler(){

}


reg_handler::~reg_handler(void) {
}

mips_token* reg_handler::parse_token(parser_context &ctx, string buff){
    char firstChar = ctx.get_src_reader()->peek();
    char nextChar = ctx.get_src_reader()->peek(1);
    string finalBuff;
	finalBuff += firstChar;

	reg_tok *tok = NULL;

	if(ctx.get_src_reader()->is_integer(nextChar)){
        ctx.get_src_reader()->advance(1);
		finalBuff += ctx.get_src_reader()->read_int();

		// Only accept within range 0-31
		int regNumber = 0;
		try {
            regNumber = stoi(finalBuff.substr(1, finalBuff.length()-1), nullptr, 10);
		} catch(...){
			// Invalid number
            ctx.get_src_reader()->move_to(-1, STREAM_POS::STREAM_POS_CUR);
			return NULL;
		}
		
		if(regNumber >= 0 && regNumber <= 31){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
		}
        ctx.get_src_reader()->move_to(-1, STREAM_POS::STREAM_POS_CUR);
	}

	switch(nextChar){
	case 'a':
        if(ctx.get_src_reader()->matches(reg_at)){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
            finalBuff = reg_at;
		} else if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);
		
			// Only accept within range a0-a3
			if(regNumber >= 0 && regNumber <= 3){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'z':
        if(ctx.get_src_reader()->matches(reg_zero)){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
            finalBuff = reg_zero;
		}
		break;
	case 't':
		if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range t0-t9
			if(regNumber >= 0 && regNumber <= 9){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 's':
        if(ctx.get_src_reader()->matches(reg_sp)){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
            finalBuff =reg_sp;
		} else if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range s0-s8
			if(regNumber >= 0 && regNumber <= 8){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'v':
		if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range v0-v1
			if(regNumber >= 0 && regNumber <= 1){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'k':
		if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range k0-k1
			if(regNumber >= 0 && regNumber <= 1){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'g':
        if(ctx.get_src_reader()->matches(reg_gp)){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
            finalBuff = reg_gp;
		}
		break;
	case 'f':
        if(ctx.get_src_reader()->matches(reg_fp)){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
            finalBuff = reg_fp;
		} else if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range f0-f31
			if(regNumber >= 0 && regNumber <= 31){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'r':
        if(ctx.get_src_reader()->matches(reg_ra)){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
            finalBuff = reg_ra;
		}
		break;
	}

	if(tok != NULL){
		tok->set_raw_tok(finalBuff);
		ctx.get_src_reader()->advance(finalBuff.length());
        return tok;
	}
	return NULL;
}

int reg_handler::parse_reg_number(string &finalBuff, parser_context &ctx){
	finalBuff += ctx.get_src_reader()->peek(1);
	finalBuff += ctx.get_src_reader()->read_int(2);
	int regNumber = 0;
	try {
		regNumber = stoi(finalBuff.substr(2, finalBuff.length() -2), 0, 10);
	} catch(...){
		return -1;
	}
	return regNumber;
}
