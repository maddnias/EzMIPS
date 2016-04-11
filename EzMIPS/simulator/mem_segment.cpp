#include "mem_segment.h"

using namespace std;

mem_segment::mem_segment(std::wstring identifier, unsigned int size, unsigned int base_addr):
	m_segment_identifier(identifier),
	m_segment_size(size),
	m_segment_base_addr(base_addr)
{
}


mem_segment::~mem_segment(void)
{
}

wstring mem_segment::get_segment_identifier(){
	return m_segment_identifier;
}

unsigned int mem_segment::get_segment_base_addr(){
	return m_segment_base_addr;
}

unsigned int mem_segment::get_segment_size(){
	return m_segment_size;
}

__int32 mem_segment::read_word(unsigned int addr){
	if(!is_in_range(addr)){
		return -1;
	}
	return *(__int32*)(m_mem_block+(addr-m_segment_base_addr));
}

// TODO: error handling
void mem_segment::write_word(unsigned int addr, __int32 data){
	if(is_in_range(addr)){
		*(__int32*)(m_mem_block+(addr-m_segment_base_addr)) = data;
	}
}

bool mem_segment::is_in_range(unsigned int addr){
	return (addr-m_segment_base_addr) >= 0 
		&& (addr-m_segment_base_addr) <= m_segment_size;
}

