#ifndef MIPS_INSTR_H
#define MIPS_INSTR_H

#include "mips_operand_container.h"
#include <string>
#include "parser/lexer/tokens/instr_base_tok.h"
#include <stdint.h>

enum INSTR_TYPE{
	INSTR_TYPE_I = 0x1,
	INSTR_TYPE_J = 0x2,
	INSTR_TYPE_R = 0x4,
	INSTR_TYPE_PSEUDO = 0x8
};

class mips_instr
{
public:
    mips_instr(void);
    mips_instr(INSTRUCTION_TYPE type, std::string expanded_name,
               std::string mnemonic, int opcode, int funct,
               mips_operand &op1, mips_operand &op2, mips_operand &op3);
    ~mips_instr(void);

    INSTRUCTION_TYPE get_instr_type();
    std::string get_expanded_name();
    std::string get_mnemonic();
    int get_opcode();
    int get_funct();

    int32_t m_dat;

private:
    INSTRUCTION_TYPE m_instr_type;
    std::string m_expanded_name;
    std::string m_mnemonic;
    int m_opcode;
    int m_funct;

protected:
    mips_operand m_operand1;
    mips_operand m_operand2;
    mips_operand m_operand3;
};

#endif
