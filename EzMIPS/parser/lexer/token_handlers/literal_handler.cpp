#include "literal_handler.h"
#include "..\tokens\literal_tok.h"

#include <list>

using namespace std;

literal_handler::literal_handler(){

}


literal_handler::~literal_handler(void) {
}

mips_token_ptr literal_handler::parse_token(parser_ctx &ctx, wstring buff){
	wchar_t firstChar = ctx.get_src_reader()->peek();
	wstring finalBuff;
	finalBuff += firstChar;

	literal_tok *tok = NULL;

	// Read integers
	if(firstChar == '-'){
		if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(1))){
			ctx.get_src_reader()->advance(1);
			tok = new literal_tok(LITERAL_TYPE_INT, ctx.get_src_reader()->get_current_row(),
				ctx.get_src_reader()->get_current_col());
			finalBuff += ctx.get_src_reader()->read_int();
		}
	// Hex support
	} else if (ctx.get_src_reader()->peek() == '0'&& ctx.get_src_reader()->peek(1) == 'x') {
			ctx.get_src_reader()->advance(2);
			finalBuff += 'x';
			finalBuff += ctx.get_src_reader()->read_hex_int();

	} else if(ctx.get_src_reader()->is_integer(firstChar)){
		ctx.get_src_reader()->advance(1);
		tok = new literal_tok(LITERAL_TYPE_INT, ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		finalBuff += ctx.get_src_reader()->read_int();
	}

	// Read comments
	if(firstChar == '#'){
		ctx.get_src_reader()->advance(1);
		tok = new literal_tok(LITERAL_TYPE_COMMENT, ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
		finalBuff += ctx.get_src_reader()->read_until('\n');
		// Remove \n
		finalBuff.pop_back();
	}

	// Read strings
	if(firstChar == '"'){
		ctx.get_src_reader()->advance(1);
		finalBuff += ctx.get_src_reader()->read_until('\n');
		finalBuff.pop_back();
		int counter = 0;
		bool endFlag = false;
		for(wstring::iterator it = finalBuff.begin();it != finalBuff.end();it++,counter++){
			if(*it == '"'){
				endFlag = true;
				break;
			}
		}

		if(endFlag){
			tok = new literal_tok(LITERAL_TYPE_STRING, ctx.get_src_reader()->get_current_row(),
				ctx.get_src_reader()->get_current_col());
			finalBuff = finalBuff.substr(counter);
		} else {
			ctx.get_src_reader()->move_to(-1, STREAM_POS_CUR);
		}
	}

	if(tok != NULL){
		tok->set_raw_tok(finalBuff);
		ctx.get_src_reader()->advance(finalBuff.length());
		return mips_token_ptr(tok);
	}
	return NULL;
}