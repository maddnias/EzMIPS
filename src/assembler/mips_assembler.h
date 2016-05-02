#ifndef MIPS_ASSEMBLER_H
#define MIPS_ASSEMBLER_H
#include "source_file.h"
#include "runtime_context.h"
#include "token_rule.h"
#include "r_instr_tok_rule.h"
#include "simulator/instructions/mips_instr.h"
#include "parser/lexer/tokens/reg_tok.h"
#include <map>


class mips_assembler
{
public:
    mips_assembler(source_file *file);
    ~mips_assembler();

    parser_context* assemble(runtime_context &runtime_ctx);
    void ensure_rules(parser_context *ctx);

private:
    source_file *m_file;
    r_instr_tok_rule m_r_instr_tok_rule;
    std::map<std::string, int> m_reg_map;
    std::map<INSTRUCTION_CODE, char> m_funct_map;

    void init_assembler();
    void write_segments(runtime_context &ctx, std::vector<mips_token*> *tokens);
    mips_instr* parse_instr(std::vector<mips_token*>::iterator &tok_it);

    void read_registers(reg_tok &tok1,
                        std::vector<mips_token*>::iterator &tok_it);
    void read_registers(reg_tok &tok1, reg_tok &tok2,
                        std::vector<mips_token*>::iterator &tok_it);
    void read_registers(reg_tok &tok1, reg_tok &tok2, reg_tok &tok3,
                        std::vector<mips_token*>::iterator &tok_it);

    mips_operand get_reg_operand(reg_tok &tok);
};

#endif // MIPS_ASSEMBLER_H
