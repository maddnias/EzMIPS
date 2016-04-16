#include "r_instr_tok_rule.h"

r_instr_tok_rule::r_instr_tok_rule()
{

}

bool r_instr_tok_rule::follows_rule(mips_tok_vector &tokens,
                                    unsigned int idx, parser_ctx &ctx){
    if(idx + 3 < tokens.size()){
        return false;
    }
    for(int i = 1;i <= 3;i++){
        if(tokens.at(i+idx)->get_tok_type() != TOKEN_TYPE::REG_TOK){
            ctx.push_err(new parser_error("", tokens.at(i+idx)->get_tok_row(),
                                          tokens.at(i+idx)->get_tok_col()));
            return false;
        }
    }
    return true;
}
