#ifndef TOKEN_RULE_H
#define TOKEN_RULE_H

#include "tokenizer.h"

class token_rule
{
public:
    token_rule();
    virtual bool follows_rule(mips_tok_vector &tokens,
                      unsigned int idx, parser_ctx &ctx) = 0;
};

#endif // TOKEN_RULE_H
