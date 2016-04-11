#include "mips_operand_container.h"

using namespace std;

mips_operand_container::mips_operand_container(wstring str_data, 
											   int int_data):
m_str_data(str_data),
m_int_data(int_data){
}


mips_operand_container::~mips_operand_container(void){
}
