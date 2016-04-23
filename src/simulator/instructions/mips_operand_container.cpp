#include "mips_operand_container.h"

using namespace std;

mips_operand_container::mips_operand_container():
m_str_data(""),
m_int_data(0){

}

mips_operand_container::mips_operand_container(string str_data):
m_str_data(str_data),
m_int_data(0){

}

mips_operand_container::mips_operand_container(int int_data):
m_str_data(""),
m_int_data(int_data){

}

mips_operand_container::mips_operand_container(std::string str_data,
											   int int_data):
m_str_data(str_data),
m_int_data(int_data){
}


mips_operand_container::~mips_operand_container(void){
}
