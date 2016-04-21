#include "mips_instr_writer.h"


mips_instr_writer::mips_instr_writer(void):
    m_big_endian(false)
{
}


mips_instr_writer::~mips_instr_writer(void)
{
}

void mips_instr_writer::write_instr(const mips_instr &instr, mem_segment &segment,
		unsigned int addr){
			
}
