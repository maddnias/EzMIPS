#pragma once
#include "token_handler.h"

#ifdef _WIN32
    #define instr_addi  "addi"
    #define instr_addiu "addiu"
    #define instr_andi  "andi"
    #define instr_beq   "beq"
    #define instr_bne   "bne"
    #define instr_lbu   "lbu"
    #define instr_lhu   "lhu"
    #define instr_lui   "lui"
    #define instr_lw    "lw"
    #define instr_ori   "ori"
    #define instr_sb    "sb"
    #define instr_sh    "sh"
    #define instr_slti  "slti"
    #define instr_sltiu "sltiu"
    #define instr_sw    "sw"
#elif __linux__
    #define instr_addi  "addi"
    #define instr_addiu "addiu"
    #define instr_andi  "andi"
    #define instr_beq   "beq"
    #define instr_bne   "bne"
    #define instr_lbu   "lbu"
    #define instr_lhu   "lhu"
    #define instr_lui   "lui"
    #define instr_lw    "lw"
    #define instr_ori   "ori"
    #define instr_sb    "sb"
    #define instr_sh    "sh"
    #define instr_slti  "slti"
    #define instr_sltiu "sltiu"
    #define instr_sw    "sw"
#endif

class i_instr_handler
	: public mips_token_handler
{
public:
	i_instr_handler(void);
	~i_instr_handler(void);
	
	virtual mips_token_ptr parse_token(parser_ctx &ctx, mips_str buff) override;
	
};

