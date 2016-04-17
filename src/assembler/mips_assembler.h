#ifndef MIPS_ASSEMBLER_H
#define MIPS_ASSEMBLER_H
#include "source_file.h"
#include "runtime_context.h"
#include "token_rule.h"
#include "r_instr_tok_rule.h"

class mips_assembler
{
public:
    mips_assembler(source_file *file);
    ~mips_assembler();

    parser_context assemble(runtime_context &runtime_ctx);
    void ensure_rules(parser_context &ctx);

private:
    source_file *m_file;
    r_instr_tok_rule m_r_instr_tok_rule;

    void init_assembler();
};

#endif // MIPS_ASSEMBLER_H
