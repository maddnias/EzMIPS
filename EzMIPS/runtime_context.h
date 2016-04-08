#pragma once
#include <vector>
#include "simulator\instructions\mips_instr.h"

class runtime_context
{
public:
	runtime_context(void);
	~runtime_context(void);

private:
	unsigned int m_pc;
	bool m_allow_self_modification;
	bool m_delayed_branching;
};

