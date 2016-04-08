#pragma once
#include "mips_instr.h"
class mips_instr_add :
	public mips_instr
{
public:
	mips_instr_add(void);
	~mips_instr_add(void);

	INSTR_TYPE get_instr_type() override;
	std::wstring get_expanded_name() override;
	std::wstring get_mnemonic() override;
	int get_opcode() override;
	int get_funct() override;
};

