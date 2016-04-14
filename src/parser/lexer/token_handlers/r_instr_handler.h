#pragma once
#include "token_handler.h"

#ifdef _WIN32
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
#elif __linux__
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
#endif

class r_instr_handler :
	public mips_token_handler
{
public:
	r_instr_handler(void);
	~r_instr_handler(void);

	virtual mips_token_ptr parse_token(parser_ctx &ctx, mips_str buff) override;
};

