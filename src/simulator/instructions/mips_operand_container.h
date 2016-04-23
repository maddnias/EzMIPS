#ifndef MIPS_OPERAND_CONTAINER_H
#define MIPS_OPERAND_CONTAINER_H

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
    mips_operand_container(std::string str_data);
    mips_operand_container(int int_data);
	mips_operand_container(std::string str_data, int int_data);
	~mips_operand_container(void);

	std::string m_str_data;
	int m_int_data;
};

typedef mips_operand_container mips_operand;

#endif
