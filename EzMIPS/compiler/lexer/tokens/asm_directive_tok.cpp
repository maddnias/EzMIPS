
#include "asm_directive_tok.h"


asm_directive_tok::asm_directive_tok(unsigned int tok_row, unsigned int tok_col):
	mips_token(ASM_DIRECTIVE_TOK, tok_row, tok_col, L"ASM_DIRECTIVE: "){
}


asm_directive_tok::~asm_directive_tok(void)
{
}

void asm_directive_tok::set_directive(ASSEMBLER_DIRECTIVE directive){
	m_directive = directive;
}

ASSEMBLER_DIRECTIVE asm_directive_tok::get_directive(){
	return m_directive;
}
