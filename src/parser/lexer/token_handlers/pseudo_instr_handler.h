#pragma once
#include "token_handler.h"

#ifdef _WIN32
    #define instr_blt   L"blt"
    #define instr_bgt   L"bgt"
    #define instr_ble   L"ble"
    #define instr_neg   L"neg"
    #define instr_not   L"not"
    #define instr_bge   L"bge"
    #define instr_li    L"li"
    #define instr_la    L"la"
    #define instr_move  L"move"
    #define instr_sge   L"sge"
    #define instr_sgt   L"sgt"
#elif __linux__
    #define instr_blt   "blt"
    #define instr_bgt   "bgt"
    #define instr_ble   "ble"
    #define instr_neg   "neg"
    #define instr_not   "not"
    #define instr_bge   "bge"
    #define instr_li    "li"
    #define instr_la    "la"
    #define instr_move  "move"
    #define instr_sge   "sge"
    #define instr_sgt   "sgt"
#endif

class pseudo_instr_handler
	: public mips_token_handler
{
public:
	pseudo_instr_handler(void);
	~pseudo_instr_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, mips_str buff) override;
	
};

