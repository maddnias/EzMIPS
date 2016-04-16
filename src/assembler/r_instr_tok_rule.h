#ifndef R_INSTR_TOK_RULE_H
#define R_INSTR_TOK_RULE_H
#include "token_rule.h"


class r_instr_tok_rule
        : public token_rule
{
public:
    r_instr_tok_rule();
    bool follows_rule(mips_tok_vector &tokens,
                           unsigned int idx, parser_ctx &ctx) override;
};

#endif // R_INSTR_TOK_RULE_H
