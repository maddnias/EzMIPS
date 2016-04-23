#include "mem_segment.h"

// for memcpy
#ifdef __linux__
#include <string.h>
#endif

using namespace std;

mem_segment::mem_segment(std::string identifier,
                         unsigned int max_size, unsigned int base_addr):
	m_segment_identifier(identifier),
    m_segment_size(BUFF_SIZE),
    m_segment_base_addr(base_addr),
    m_max_segment_size(max_size),
    m_mem_block(new char[BUFF_SIZE]){
}


mem_segment::~mem_segment(void){
    if(m_mem_block != NULL){
        delete m_mem_block;
    }
}

std::string mem_segment::get_segment_identifier(){
	return m_segment_identifier;
}

unsigned int mem_segment::get_segment_base_addr(){
	return m_segment_base_addr;
}

unsigned int mem_segment::get_segment_size(){
	return m_segment_size;
}

int32_t mem_segment::read_word(unsigned int addr){
	if(!is_in_range(addr)){
		return -1;
	}
    // Check if address is relative to 0 or segment base addr
    if(is_relative_to_base_addr(addr)){
        return *(int32_t*)(m_mem_block+(addr-m_segment_base_addr));
    } else {
        return *(int32_t*)(m_mem_block+addr);
    }
}

// TODO: error handling
void mem_segment::write_word(unsigned int addr, int32_t data){
	if(is_in_range(addr)){
        if(is_relative_to_base_addr(addr)){
            *(int32_t*)(m_mem_block+(addr-m_segment_base_addr)) = data;
        } else {
            *(int32_t*)(m_mem_block+addr) = data;
        }
    }
}

void mem_segment::grow()
{
    if(m_segment_size + BUFF_SIZE <= m_max_segment_size){
        // TODO: better way?
        char *tmp = new char[m_segment_size];
        memcpy(tmp, m_mem_block, m_segment_size);
        delete m_mem_block;
        m_mem_block = new char[m_segment_size + BUFF_SIZE];
        memcpy(m_mem_block, tmp, m_segment_size + BUFF_SIZE);
        m_segment_size += BUFF_SIZE;
        delete tmp;
    } else {
        // TODO: out of memory
    }
}

bool mem_segment::is_relative_to_base_addr(unsigned int addr){
    return addr > m_segment_base_addr;
}

bool mem_segment::is_in_range(unsigned int addr){
    if(is_relative_to_base_addr(addr)){
        if((addr-m_segment_base_addr) >= 0
            && (addr-m_segment_base_addr) <= m_max_segment_size){
            if(addr-m_segment_base_addr > m_segment_size){
                grow();
            }
            return true;
        }
    } else {
        if(addr >= 0 && addr <= m_max_segment_size){
            if(addr > m_segment_size){
                grow();
            }
            return true;
        }
    }
}

