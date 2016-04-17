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
                                    mips_tok_vector::iterator tok_it,
                                    parser_context &ctx){
    if(distance(tok_it, tokens.end()) < get_required_tok_count()){
        ctx.push_err(new parser_error("R_INSTR_TOK_RULE: TODO", (*tok_it)->get_tok_row(),
                                      (*tok_it)->get_tok_col()));
        return false;
    }

    tok_it++;
    for(unsigned int i = 0;i < get_required_tok_count();i++,tok_it++){
        if((*tok_it)->get_tok_type() != TOKEN_TYPE::REG_TOK){
            ctx.push_err(new parser_error("R_INSTR_TOK_RULE: TODO", (*tok_it)->get_tok_row(),
                                          (*tok_it)->get_tok_col()));
            return false;
        }
    }
    return true;
}
