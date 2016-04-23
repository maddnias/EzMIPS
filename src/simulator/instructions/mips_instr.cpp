#include "mips_instr.h"

mips_instr::mips_instr():
m_dat(0){

}

mips_instr::mips_instr(INSTRUCTION_TYPE type, std::string expanded_name,
                       std::string mnemonic, int opcode, int funct,
                       mips_operand &op1, mips_operand &op2, mips_operand &op3):
m_instr_type(type),
m_expanded_name(expanded_name),
m_mnemonic(mnemonic),
m_opcode(opcode),
m_funct(funct),
m_operand1(op1),
m_operand2(op2),
m_operand3(op3),
m_dat(0){

}

mips_instr::~mips_instr(void)
{
}
