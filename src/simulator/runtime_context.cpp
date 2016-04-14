#include "runtime_context.h"

using namespace std;

runtime_context::runtime_context(void)
{
}


runtime_context::~runtime_context(void)
{
	// free allocated memory for memory segments
	for(vector<mem_segment*>::iterator it = m_mem_segments.begin();
		it != m_mem_segments.end();it++){
			delete *it;
	}
}

mem_segment* runtime_context::get_segment(mips_str identifier){
	for(vector<mem_segment*>::iterator it = m_mem_segments.begin();
		it != m_mem_segments.end();it++){
			if((*it)->get_segment_identifier() == identifier){
				return *it;
			}
	}
	return NULL;
}

mem_segment* runtime_context::get_segment(unsigned int addr){
	for(vector<mem_segment*>::iterator it = m_mem_segments.begin();
		it != m_mem_segments.end();it++){
			if(addr >= (*it)->get_segment_base_addr()
				&& addr <= ((*it)->get_segment_base_addr()+(*it)->get_segment_size())){
				return *it;
			}
	}
	return NULL;
}

void runtime_context::init_context(){
#if _WIN32
	m_mem_segments.push_back(new mem_segment(".text", 0, 0x00400000));
	m_mem_segments.push_back(new mem_segment(".data", 0, 0x10010000));
#elif __linux__
    m_mem_segments.push_back(new mem_segment(".text", 0, 0x00400000));
    m_mem_segments.push_back(new mem_segment(".data", 0, 0x10010000));
#endif
}
