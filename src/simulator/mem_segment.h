#ifndef MEM_SEGMENT_H
#define MEM_SEGMENT_H

#include "stdint.h"

#include <string>

#define BUFF_SIZE 4096

class mem_segment
{
public:
    mem_segment(std::string identifier, unsigned int max_size,
		unsigned int base_addr);
	~mem_segment(void);

	std::string get_segment_identifier();
	unsigned int get_segment_base_addr();
	unsigned int get_segment_size();
    int32_t read_word(unsigned int addr);
    void write_word(unsigned int addr, int32_t data);

private:
	std::string m_segment_identifier;
	unsigned int m_segment_size;
    unsigned int m_max_segment_size;
	unsigned int m_segment_base_addr;
	char *m_mem_block;
    void grow();

    bool is_relative_to_base_addr(unsigned int addr);
	bool is_in_range(unsigned int addr);
};

#endif
