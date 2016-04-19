#include "mips_assembler.h"
#include "r_instr_tok_rule.h"
#include "parser/lexer/tokens/instr_base_tok.h"
#include "thirdparty/format.h"

using namespace std;

mips_assembler::mips_assembler(source_file *file):
    m_file(file)
{
    init_assembler();
}

mips_assembler::~mips_assembler()
{

}

parser_context* mips_assembler::assemble(runtime_context &runtime_ctx)
{
    mips_tokenizer t;
    parser_context *parserCtx = t.parse_tokens(m_file);

    ensure_rules(parserCtx);
    return parserCtx;
}

void mips_assembler::ensure_rules(parser_context *ctx)
{
    for(mips_tok_vector::iterator it = ctx->get_parsed_tokens()->begin();
        it != ctx->get_parsed_tokens()->end();it++){
        switch((*it)->get_tok_type()){
        case TOKEN_TYPE::INSTR_TOK:
            switch(static_cast<instr_base_tok*>(*it)->get_instr_type()){
            case INSTRUCTION_I:

                break;
            case INSTRUCTION_J:

                break;
            case INSTRUCTION_PSEUDO:

                break;
            case INSTRUCTION_R:
                // TODO: pointer instead of dereference
                if(m_r_instr_tok_rule.follows_rule(*ctx->get_parsed_tokens(), it, ctx)){
                    it += m_r_instr_tok_rule.get_required_tok_count();
                }
                break;
            }

            break;
        case TOKEN_TYPE::REG_TOK:

        break;
        case TOKEN_TYPE::UNDEFINED_TOK:
            ctx->push_err((*it)->get_tok_row(), (*it)->get_tok_col(),
                                "Undefined token: \"{}\"", (*it)->get_raw_tok());
            break;
        }
    }

}

void mips_assembler::init_assembler()
{
    m_r_instr_tok_rule = r_instr_tok_rule();
}


