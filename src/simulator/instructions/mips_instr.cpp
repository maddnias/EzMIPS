#include "mips_instr.h"

mips_instr::mips_instr(INSTR_TYPE type, std::string expanded_name,
                       std::string mnemonic, int opcode, int funct):
m_instr_type(type),
m_expanded_name(expanded_name),
m_mnemonic(mnemonic),
m_opcode(opcode),
m_funct(funct){

}

mips_instr::~mips_instr(void)
{
}
