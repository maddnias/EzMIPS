#pragma once
#include "platform_dependencies.h"
#include "stdint.h"

#include <string>

class mem_segment
{
public:
	mem_segment(mips_str identifier, unsigned int size, 
		unsigned int base_addr);
	~mem_segment(void);

	mips_str get_segment_identifier();
	unsigned int get_segment_base_addr();
	unsigned int get_segment_size();
    int32_t read_word(unsigned int addr);
    void write_word(unsigned int addr, int32_t data);

private:
	mips_str m_segment_identifier;
	unsigned int m_segment_size;
	unsigned int m_segment_base_addr;
	char *m_mem_block;

	bool is_in_range(unsigned int addr);
};
