#pragma once
#include "token_handler.h"

#ifdef _WIN32
    #define instr_add   L"add"
    #define instr_addu  L"addu"
    #define instr_and   L"and"
    #define instr_div   L"div"
    #define instr_divu  L"divu"
    #define instr_jr    L"jr"
    #define instr_mfhi  L"mfhi"
    #define instr_mflo  L"mflo"
    #define instr_mfc0  L"mfc0"
    #define instr_mult  L"mult"
    #define instr_multu L"multu"
    #define instr_nor   L"nor"
    #define instr_xor   L"xor"
    #define instr_or    L"or"
    #define instr_slt   L"slt"
    #define instr_sltu  L"sltu"
    #define instr_sll   L"sll"
    #define instr_srl   L"srl"
    #define instr_sra   L"sra"
    #define instr_sub   L"sub"
    #define instr_subu  L"subu"
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
    #define instr_sll   "sll"
    #define instr_srl   "srl"
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

