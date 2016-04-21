#include "j_instr_handler.h"
#include "../tokens/j_instr_tok.h"
#include "../tokens/asm_directive_tok.h"

#include <list>

using namespace std;

j_instr_handler::j_instr_handler(){

}


j_instr_handler::~j_instr_handler(void) {
}

mips_token* j_instr_handler::parse_token(parser_context &ctx, std::string buff){
	if(ctx.get_src_reader()->peek() != 'j'){
        return NULL;
	}
	
	j_instr_tok *tok = NULL;

    if(buff == instr_j){
        tok = new j_instr_tok(INSTRUCTION_CODE::J,
                              ctx.get_src_reader()->get_current_row(),
                              ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_j);
		ctx.get_src_reader()->advance(1);

    } else if (buff == instr_jal){
        tok = new j_instr_tok(INSTRUCTION_CODE::JAL,
                              ctx.get_src_reader()->get_current_row(),
                              ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_jal);
		ctx.get_src_reader()->advance(3);

	} else {
		return NULL;
	}

    return tok;
}
