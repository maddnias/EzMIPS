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
                it += 4;
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

    // initiate funct map
    m_funct_map[INSTRUCTION_CODE::ADD] = 0x20;
    m_funct_map[INSTRUCTION_CODE::ADDU] = 0x21;
    m_funct_map[INSTRUCTION_CODE::SUB] = 0x22;
    m_funct_map[INSTRUCTION_CODE::SUBU] = 0x23;
    m_funct_map[INSTRUCTION_CODE::MULT] = 0x18;
    m_funct_map[INSTRUCTION_CODE::MULTU] = 0x19;
    m_funct_map[INSTRUCTION_CODE::DIV] = 0x1A;
    m_funct_map[INSTRUCTION_CODE::DIVU] = 0x1B;
    m_funct_map[INSTRUCTION_CODE::SLT] = 0x2A;
    m_funct_map[INSTRUCTION_CODE::SLTU] = 0x2B;
    m_funct_map[INSTRUCTION_CODE::AND] = 0x24;
    m_funct_map[INSTRUCTION_CODE::OR] = 0x25;
    m_funct_map[INSTRUCTION_CODE::XOR] = 0x26;
    m_funct_map[INSTRUCTION_CODE::NOR] = 0x27;

    // initiate opcode map
    m_op_map[INSTRUCTION_CODE::ADDI] = 0x8 << 0x1A;
    m_op_map[INSTRUCTION_CODE::ADDIU] = 0x9 << 0x1A;
    m_op_map[INSTRUCTION_CODE::SLTI] = 0xA << 0x1A;
    m_op_map[INSTRUCTION_CODE::SLTIU] = 0xB << 0x1A;
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
            mips_instr *tmpInstr = parse_instr(it);
            curSeg->write_word(idxMap[curSegId], tmpInstr->m_dat);
            delete tmpInstr;
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

//TODO: fix negative number support
//TODO: maybe just return int32_t instead of mips_instr*
mips_instr* mips_assembler::parse_instr(vector<mips_token*>::iterator &tok_it){
    // We trust that rules have been enforced here
    mips_operand op1, op2, op3;
    reg_tok rTok1, rTok2, rTok3;
    short immOp1;
    instr_base_tok *bTok = static_cast<instr_base_tok*>(*tok_it);
    mips_instr *instr = new mips_instr();

    switch(bTok->get_instr_code()){
    // 3 register R-instructions
    case INSTRUCTION_CODE::ADD:
    case INSTRUCTION_CODE::ADDU:
    case INSTRUCTION_CODE::SUB:
    case INSTRUCTION_CODE::SUBU:
    case INSTRUCTION_CODE::SLT:
    case INSTRUCTION_CODE::SLTU:
    case INSTRUCTION_CODE::AND:
    case INSTRUCTION_CODE::OR:
    case INSTRUCTION_CODE::NOR:
    case INSTRUCTION_CODE::XOR:
            read_registers(rTok1, rTok2, rTok3, tok_it);
            op1 = get_reg_operand(rTok1);
            op2 = get_reg_operand(rTok2);
            op3 = get_reg_operand(rTok3);

            instr->m_dat = op2.m_int_data << 0x15;
            instr->m_dat |= op3.m_int_data << 0x10;
            instr->m_dat |= op1.m_int_data << 0xB;
            instr->m_dat |= m_funct_map[bTok->get_instr_code()];

            tok_it += 4;
        break;
    // 2 register R-instructions
    case INSTRUCTION_CODE::MULT:
    case INSTRUCTION_CODE::MULTU:
    case INSTRUCTION_CODE::DIV:
    case INSTRUCTION_CODE::DIVU:
        read_registers(rTok1, rTok2, tok_it);
        op1 = get_reg_operand(rTok1);
        op2 = get_reg_operand(rTok2);

        instr->m_dat = op1.m_int_data << 0x15;
        instr->m_dat |= op2.m_int_data << 0x10;
        instr->m_dat |= m_funct_map[bTok->get_instr_code()];

        tok_it += 3;
        break;

    // I-instructions
    case INSTRUCTION_CODE::ADDI:
    case INSTRUCTION_CODE::ADDIU:
    case INSTRUCTION_CODE::SLTI:
    case INSTRUCTION_CODE::SLTIU:
        read_registers(rTok1, rTok2, tok_it);
        op1 = get_reg_operand(rTok1);
        op2 = get_reg_operand(rTok2);
        //TODO: do it in one line?
        tok_it += 3;
        read_imm_operand(immOp1, tok_it);

        instr->m_dat = m_op_map[bTok->get_instr_code()];
        instr->m_dat |= op2.m_int_data << 0x15;
        instr->m_dat |= op1.m_int_data << 0x10;
        instr->m_dat |= immOp1;

        tok_it += 1;
        break;
    }

    return instr;
}

void mips_assembler::read_registers(reg_tok &tok1, vector<mips_token*>::iterator &tok_it)
{
    tok1 = *static_cast<reg_tok*>(*(tok_it+1));
}

void mips_assembler::read_registers(reg_tok &tok1, reg_tok &tok2, vector<mips_token*>::iterator &tok_it)
{
    tok1 = *static_cast<reg_tok*>(*(tok_it+1));
    tok2 = *static_cast<reg_tok*>(*(tok_it+2));
}

void mips_assembler::read_registers(reg_tok &tok1, reg_tok &tok2,
                                    reg_tok &tok3, vector<mips_token*>::iterator &tok_it)
{
    tok1 = *static_cast<reg_tok*>(*(tok_it+1));
    tok2 = *static_cast<reg_tok*>(*(tok_it+2));
    tok3 = *static_cast<reg_tok*>(*(tok_it+3));
}

void mips_assembler::read_imm_operand(short &dat, vector<mips_token*>::iterator &tok_it){
    mips_token* test = *tok_it;
    dat = stoi((*(tok_it))->get_raw_tok());
}

mips_operand mips_assembler::get_reg_operand(reg_tok &tok)
{
    if(isalpha(tok.get_raw_tok()[1])){
        return mips_operand(m_reg_map[tok.get_raw_tok()]);
    } else {
        return mips_operand(stoi(tok.get_raw_tok().substr(1, tok.get_raw_tok().length()-1)));
    }
}


