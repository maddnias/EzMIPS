#include "mips_instr_add.h"

using namespace std;

mips_instr_add::mips_instr_add(void)
{
}


mips_instr_add::~mips_instr_add(void)
{
}

INSTR_TYPE mips_instr_add::get_instr_type(){
	return INSTR_TYPE_R;
}

mips_str mips_instr_add::get_expanded_name(){
#if _WIN32
	return "add";
#elif __linux__
    return "add";
#endif
}

mips_str mips_instr_add::get_mnemonic(){
#if _WIN32
    return "add";
#elif __linux__
    return "add";
#endif
}

int mips_instr_add::get_opcode(){
	return 0;
}

int mips_instr_add::get_funct(){
	return 0x20;
}
