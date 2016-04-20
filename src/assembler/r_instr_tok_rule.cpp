#include "r_instr_tok_rule.h"

using namespace std;

r_instr_tok_rule::r_instr_tok_rule(){

}

r_instr_tok_rule::~r_instr_tok_rule(){

}

unsigned int r_instr_tok_rule::get_required_tok_count(){
    return 3;
}

bool r_instr_tok_rule::follows_rule(mips_tok_vector &tokens,
                                    mips_tok_vector::iterator &tok_it,
                                    parser_context *ctx){
    unsigned int dist = distance(tok_it+1, tokens.end());

    if(dist < get_required_tok_count()){
        ctx->push_err(*tok_it,
                     "Too few operands for instruction; \"{}\": got: {:d} expected: {:d}",
                     (*tok_it)->get_raw_tok(), dist, get_required_tok_count());
        tok_it += dist;
        return false;
    }

    for(unsigned int i = 1;i <= get_required_tok_count();i++){
        if((*(tok_it+i))->get_tok_row() != (*tok_it)->get_tok_row()){
            ctx->push_err(*tok_it,
                         "Too few or invalid operands for instruction; \"{}\", expected: {}",
                         (*tok_it)->get_raw_tok(), "$t1, $t2, $t3");
            tok_it += i;
            return false;
        }
        if((*(tok_it+i))->get_tok_type() != TOKEN_TYPE::REG_TOK){
            ctx->push_err(*tok_it,
                         "Invalid operand for instruction: \"{0}\": \"{1}\", expected: {0} {2}",
                         (*tok_it)->get_raw_tok(), (*(tok_it+i))->get_raw_tok(), "$t1, $t2, $t3");
            tok_it += i;
            return false;
        }
    }

    return true;
}
