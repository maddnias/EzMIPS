#pragma once
#include "platform_dependencies.h"

#include <string>

enum OPERAND_TYPE{
	OPERAND_IMMEDIATE = 0x1,
	OPERAND_REGISTER = 0x2,
	OPERAND_LABEL_REF = 0x4
};

class mips_operand_container
{
public:
	mips_operand_container(void);
	mips_operand_container(mips_str str_data, int int_data);
	~mips_operand_container(void);

	mips_str m_str_data;
	int m_int_data;
};

typedef mips_operand_container mips_operand;
