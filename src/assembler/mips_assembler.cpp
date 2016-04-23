#include "mips_assembler.h"
#include "r_instr_tok_rule.h"
#include "parser/lexer/tokens/instr_base_tok.h"
#include "thirdparty/format.h"
#include "parser/lexer/tokens/literal_tok.h"
#include "parser/lexer/tokens/asm_directive_tok.h"
#include "assembler/mips_instr_writer.h"
#include <map>
#include <stdint.h>

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
    if(parserCtx->get_parser_errors()->size() == 0){
        write_segments(runtime_ctx, parserCtx->get_parsed_tokens());
    }

    return parserCtx;
}

// TODO: finish rule ensuring
// TODO: add rules for what segment its writing to
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

void mips_assembler::init_assembler(){
    m_r_instr_tok_rule = r_instr_tok_rule();

    // initiate register mappings
    m_reg_map["$zero"] = 0;
    m_reg_map["$at"] = 1;
    m_reg_map["$v0"] = 2;
    m_reg_map["$v1"] = 3;
    m_reg_map["$a0"] = 4;
    m_reg_map["$a1"] = 5;
    m_reg_map["$a2"] = 6;
    m_reg_map["$a3"] = 7;
    m_reg_map["$t0"] = 8;
    m_reg_map["$t1"] = 9;
    m_reg_map["$t2"] = 10;
    m_reg_map["$t3"] = 11;
    m_reg_map["$t4"] = 12;
    m_reg_map["$t5"] = 13;
    m_reg_map["$t6"] = 14;
    m_reg_map["$t7"] = 15;
    m_reg_map["$s0"] = 16;
    m_reg_map["$s1"] = 17;
    m_reg_map["$s2"] = 18;
    m_reg_map["$s3"] = 19;
    m_reg_map["$s4"] = 20;
    m_reg_map["$s5"] = 21;
    m_reg_map["$s6"] = 22;
    m_reg_map["$s7"] = 23;
    m_reg_map["$t8"] = 24;
    m_reg_map["$t9"] = 25;
    m_reg_map["$k0"] = 26;
    m_reg_map["$k1"] = 27;
    m_reg_map["$gp"] = 28;
    m_reg_map["$sp"] = 29;
    m_reg_map["$fp"] = 30;
    m_reg_map["$ra"] = 31;

}

void mips_assembler::write_segments(runtime_context &ctx, std::vector<mips_token*> *tokens){
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
            curSeg->write_word(idxMap[curSegId], tmpInstr.m_dat);
            idxMap[curSegId] += sizeof(int32_t);
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
    // We trust that rules have been enforced here
    mips_operand op1, op2, op3;
    reg_tok rTok1, rTok2, rTok3;
    int i;
    instr_base_tok *bTok = static_cast<instr_base_tok*>(*tok_it);
    mips_instr instr;

    switch(bTok->get_instr_code()){
        case INSTRUCTION_CODE::ADD:
            read_registers(3, rTok1, rTok2, rTok3, tok_it);
            if(isalpha(rTok1.get_raw_tok()[1])){
                op1 = mips_operand(m_reg_map[rTok1.get_raw_tok()]);
            }
            if(isalpha(rTok2.get_raw_tok()[1])){
                op2 = mips_operand(m_reg_map[rTok2.get_raw_tok()]);
            }
            if(isalpha(rTok2.get_raw_tok()[1])){
                op3 = mips_operand(m_reg_map[rTok3.get_raw_tok()]);
            }

            instr = mips_instr(bTok->get_instr_type(), "Add", "add", 0x0, 0x20,
                              op1, op2, op3);

            instr.m_dat = op2.m_int_data << 0x15;
            instr.m_dat |= op3.m_int_data << 0x10;
            instr.m_dat |= op1.m_int_data << 0xB;
            instr.m_dat |= 0x20;

            tok_it += 4;

            return instr;
        break;
    }
}

void mips_assembler::read_registers(int count, reg_tok &tok1, reg_tok &tok2,
                                    reg_tok &tok3, vector<mips_token*>::iterator &tok_it)
{
    if(count == 1){
        tok1 = *static_cast<reg_tok*>(*(tok_it+1));
    } else if(count == 2){
        tok1 = *static_cast<reg_tok*>(*(tok_it+1));
        tok2 = *static_cast<reg_tok*>(*(tok_it+2));
    } else if(count == 3){
        tok1 = *static_cast<reg_tok*>(*(tok_it+1));
        tok2 = *static_cast<reg_tok*>(*(tok_it+2));
        tok3 = *static_cast<reg_tok*>(*(tok_it+3));
    } else {
        // TODO: should never happen
    }
}


