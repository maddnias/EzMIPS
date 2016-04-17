#ifndef R_INSTR_HANDLER_H
#define R_INSTR_HANDLER_H

#include "token_handler.h"

#define instr_add   "add"
#define instr_addu  "addu"
#define instr_and   "and"
#define instr_div   "div"
#define instr_divu  "divu"
#define instr_jr    "jr"
#define instr_mfhi  "mfhi"
#define instr_mflo  "mflo"
#define instr_mfc0  "mfc0"
#define instr_mult  "mult"
#define instr_multu "multu"
#define instr_nor   "nor"
#define instr_xor   "xor"
#define instr_or    "or"
#define instr_slt   "slt"
#define instr_sltu  "sltu"
#define instr_sll   "sl"
#define instr_srl   "sr"
#define instr_sra   "sra"
#define instr_sub   "sub"
#define instr_subu  "subu"

class r_instr_handler :
	public mips_token_handler
{
public:
	r_instr_handler(void);
	~r_instr_handler(void);

    virtual mips_token* parse_token(parser_context &ctx, std::string buff) override;
};

#endif
