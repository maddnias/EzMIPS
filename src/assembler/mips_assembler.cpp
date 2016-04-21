#include "mips_assembler.h"
#include "r_instr_tok_rule.h"
#include "parser/lexer/tokens/instr_base_tok.h"
#include "thirdparty/format.h"
#include "parser/lexer/tokens/literal_tok.h"
#include "parser/lexer/tokens/asm_directive_tok.h"
#include "assembler/mips_instr_writer.h"
#include <map>

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

    runtime_ctx.init_context();

    ensure_rules(parserCtx);
    write_segments(runtime_ctx, parserCtx->get_parsed_tokens());

    return parserCtx;
}

// TODO: finish rule ensuring
void mips_assembler::ensure_rules(parser_context *ctx)
{
    for(mips_tok_vector::iterator it = ctx->get_parsed_tokens()->begin();
        it != ctx->get_parsed_tokens()->end();){
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
                    it += m_r_instr_tok_rule.get_required_tok_count() +1;
                }
                break;
            }

            break;
        /*case TOKEN_TYPE::LITERAL_TOK:
            switch(static_cast<literal_tok*>(*it)->get_type()){
            case LITERAL_TYPE_COMMENT:
                it++;
                break;
            }
            it++;

            break;*/
        case TOKEN_TYPE::UNDEFINED_TOK:
            ctx->push_err(*it, "Undefined token: \"{}\"",
                          (*it)->get_raw_tok());
            it++;
            break;
        default:
            ctx->push_err(*it, "Unexpected token: \"{}\"",
                          (*it)->get_raw_tok());
            it++;
            break;
        }
    }

}

void mips_assembler::init_assembler()
{
    m_r_instr_tok_rule = r_instr_tok_rule();
}

void mips_assembler::write_segments(runtime_context &ctx, std::vector<mips_token*> *tokens)
{
    mips_instr_writer writer;

    map<string, int> idxMap;
    idxMap[".text"] = 0;
    idxMap[".data"] = 0;

    // set default segment to text
    string curSegId = ".text";
    int idx = idxMap[curSegId];
    mem_segment *curSeg = ctx.get_segment(curSegId);

    for(vector<mips_token*>::iterator it = tokens->begin();
        it != tokens->end();){
        switch((*it)->get_tok_type()){
        case TOKEN_TYPE::INSTR_TOK:
        {
            mips_instr tmpInstr = parse_instr(tokens, it);
            break;
        }
            //TODO: implement all
        case TOKEN_TYPE::ASM_DIRECTIVE_TOK:
            idxMap[curSegId] = idx;
            switch(static_cast<asm_directive_tok*>(*it)->get_directive()){
            case DIRECTIVE_TEXT:
                curSegId = ".text";
                idx = idxMap[curSegId];
                curSeg = ctx.get_segment(curSegId);
                break;
            case DIRECTIVE_DATA:
                curSegId = ".data";
                idx = idxMap[curSegId];
                curSeg = ctx.get_segment(curSegId);
                break;
            }

            break;
        }
    }
}

mips_instr mips_assembler::parse_instr(vector<mips_token*> *tokens,
                                       vector<mips_token*>::iterator &tok_it){

}


