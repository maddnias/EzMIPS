#pragma once

#include <string>

class mem_segment
{
public:
	mem_segment(std::wstring identifier, unsigned int size, 
		unsigned int base_addr);
	~mem_segment(void);

	std::wstring get_segment_identifier();
	unsigned int get_segment_base_addr();
	unsigned int get_segment_size();
	__int32 read_word(unsigned int addr);
	void write_word(unsigned int addr, __int32 data);

private:
	std::wstring m_segment_identifier;
	unsigned int m_segment_size;
	unsigned int m_segment_base_addr;
	char *m_mem_block;

	bool is_in_range(unsigned int addr);
};

