#ifndef R_INSTR_TOK_RULE_H
#define R_INSTR_TOK_RULE_H
#include "token_rule.h"


class r_instr_tok_rule
        : public token_rule
{
public:
    r_instr_tok_rule();
    ~r_instr_tok_rule();

    unsigned int get_required_tok_count() override;
    bool follows_rule(mips_tok_vector &tokens,
                      mips_tok_vector::iterator tok_it,
                      parser_context *ctx) override;
};

#endif // R_INSTR_TOK_RULE_H
