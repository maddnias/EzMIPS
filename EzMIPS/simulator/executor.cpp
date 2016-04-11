#include "..\include\executor.h"


executor::executor(void)
{
}


executor::~executor(void)
{
}

void executor::init_executor(mips_tok_vector tokens){
	m_ctx = new runtime_context();
	m_ctx->init_context();
}