#ifndef RUNTIME_CONTEXT_H
#define RUNTIME_CONTEXT_H

#include <vector>
#include "../simulator/instructions/mips_instr.h"
#include "mem_segment.h"

class runtime_context
{
public:
	runtime_context(void);
	~runtime_context(void);

	mem_segment* get_segment(std::string identifier);
	mem_segment* get_segment(unsigned int addr);

	void init_context();

	unsigned int m_pc;
	bool m_allow_self_modification;
	bool m_delayed_branching;

private:
	std::vector<mem_segment*> m_mem_segments;
};

#endif
