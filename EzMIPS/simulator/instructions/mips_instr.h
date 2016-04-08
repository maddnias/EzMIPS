#pragma once
#include "mips_operand_container.h"
#include <string>

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
	~mips_instr(void);

	virtual INSTR_TYPE get_instr_type() = 0;
	virtual std::wstring get_expanded_name() = 0;
	virtual std::wstring get_mnemonic() = 0;
	virtual int get_opcode() = 0;
	virtual int get_funct() = 0;

protected:
	mips_operand m_operand1;
	mips_operand m_operand2;
	mips_operand m_operand3;
};

