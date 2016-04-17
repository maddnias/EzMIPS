#ifndef TOKEN_RULE_H
#define TOKEN_RULE_H

#include "tokenizer.h"

class token_rule
{
public:
    token_rule();
    virtual ~token_rule();

    virtual unsigned int get_required_tok_count() = 0;
    virtual bool follows_rule(mips_tok_vector &tokens,
                              mips_tok_vector::iterator tok_it,
                              parser_context &ctx) = 0;
};

#endif // TOKEN_RULE_H
