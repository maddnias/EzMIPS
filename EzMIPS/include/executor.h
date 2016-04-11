#pragma once

#include "tokenizer.h"
#include "..\simulator\runtime_context.h"

class executor
{
public:
	executor(void);
	~executor(void);

	void init_executor(mips_tok_vector tokens);
	void exec();
	void exec_one();
	void exec_until_breakpoint();

	runtime_context* get_ctx();
private:
	runtime_context *m_ctx;

	void assemble_instructions();	
};

