#include "r_instr_handler.h"
#include "../tokens/r_instr_tok.h"

using namespace std;

r_instr_handler::r_instr_handler()
{
}


r_instr_handler::~r_instr_handler(void)
{
}

mips_token* r_instr_handler::parse_token(parser_context &ctx, std::string buff){
		bool successFlag = true;
		r_instr_tok *tok = NULL;

        if(buff == instr_add){
            tok = new r_instr_tok(INSTRUCTION_CODE::ADD,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_add);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_addu){
            tok = new r_instr_tok(INSTRUCTION_CODE::ADDU,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_addu);
            ctx.get_src_reader()->advance(4);

        } else if(buff == instr_and){
            tok = new r_instr_tok(INSTRUCTION_CODE::AND,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_and);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_div){
            tok = new r_instr_tok(INSTRUCTION_CODE::DIV,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_div);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_divu){
            tok = new r_instr_tok(INSTRUCTION_CODE::DIVU,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_divu);
            ctx.get_src_reader()->advance(4);

        } else if(buff == instr_jr){
            tok = new r_instr_tok(INSTRUCTION_CODE::JR,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_jr);
            ctx.get_src_reader()->advance(2);

        } else if(buff == instr_mfhi){
            tok = new r_instr_tok(INSTRUCTION_CODE::MFHI,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_mfhi);
            ctx.get_src_reader()->advance(4);

        } else if(buff == instr_mflo){
            tok = new r_instr_tok(INSTRUCTION_CODE::MFLO,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_mflo);
            ctx.get_src_reader()->advance(4);

        } else if(buff == instr_mfc0){
            tok = new r_instr_tok(INSTRUCTION_CODE::MFC0,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col()); // special
            tok->set_raw_tok(instr_mfc0);
            ctx.get_src_reader()->advance(4);

        } else if(buff == instr_mult){
            tok = new r_instr_tok(INSTRUCTION_CODE::MULT,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_mult);
            ctx.get_src_reader()->advance(4);

        } else if(buff == instr_multu){
            tok = new r_instr_tok(INSTRUCTION_CODE::MULTU,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_multu);
            ctx.get_src_reader()->advance(5);

        } else if(buff == instr_nor){
            tok = new r_instr_tok(INSTRUCTION_CODE::NOR,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_nor);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_xor){
            tok = new r_instr_tok(INSTRUCTION_CODE::XOR,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_xor);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_or){
            tok = new r_instr_tok(INSTRUCTION_CODE::OR,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_or);
            ctx.get_src_reader()->advance(2);

        } else if(buff == instr_slt){
            tok = new r_instr_tok(INSTRUCTION_CODE::SLT,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_slt);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_sltu){
            tok = new r_instr_tok(INSTRUCTION_CODE::SLTU,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_sltu);
            ctx.get_src_reader()->advance(4);

        } else if(buff == instr_sll){
            tok = new r_instr_tok(INSTRUCTION_CODE::SLL,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_sll);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_srl){
            tok = new r_instr_tok(INSTRUCTION_CODE::SRL,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_srl);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_sra){
            tok = new r_instr_tok(INSTRUCTION_CODE::SRA,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_sra);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_sub){
            tok = new r_instr_tok(INSTRUCTION_CODE::SUB,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_sub);
            ctx.get_src_reader()->advance(3);

        } else if(buff == instr_subu){
            tok = new r_instr_tok(INSTRUCTION_CODE::SUBU,
                                  INSTRUCTION_R,
                                  ctx.get_src_reader()->get_current_row(),
                                  ctx.get_src_reader()->get_current_col());
            tok->set_raw_tok(instr_subu);
            ctx.get_src_reader()->advance(4);
        } else {
            successFlag = false;
        }
		
		successFlag = tok != NULL;
		if(successFlag){
            return tok;
		}

		return NULL;
}
