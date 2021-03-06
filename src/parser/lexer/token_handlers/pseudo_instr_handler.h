#ifndef PSEUDO_INSTR_HANDLER_H
#define PSEUDO_INSTR_HANDLER_H

#include "token_handler.h"

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

class pseudo_instr_handler
	: public mips_token_handler
{
public:
	pseudo_instr_handler(void);
	~pseudo_instr_handler(void);
	
    virtual mips_token* parse_token(parser_context &ctx, std::string buff) override;
	
};

#endif
