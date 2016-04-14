#pragma once
#include "platform_dependencies.h"
#include <list>
#include <string>

using namespace std;

#ifdef _WIN32
    const mips_char *asm_directives_set[] = {".data", ".text", ".align", ".ascii", ".asciiz"};
    const mips_char *r_type_instr_set[] = {"add", "addu", "and", "div", "divu", "jr", "mfhi", "mflo", "mfc0", "mult",
        "multu", "nor", "xor", "or", "slt", "sltu", "sl", "sr", "sra", "sub", "subu"};
    const mips_char *j_type_instr_set[] = {"j", "ja"};
    const mips_char *i_type_instr_set[] = {"addi", "addiu", "andi", "beq", "bne", "lbu", "lhu", "lui", "lw", "ori",
        "sb", "sh", "slti", "sltiu", "sw"};
    const mips_char *pseudo_type_instr_set[] = {"blt", "bgt", "ble", "neg", "not", "bge", "li", "la", "move", "sge", "sgt"};
    const mips_char *reg_name_set[] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3",
        "$t4", "$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1",
        "$gp", "$sp", "$fp", "$ra"};
#elif __linux__
    const mips_char *asm_directives_set[] = {".data", ".text", ".align", ".ascii", ".asciiz"};
    const mips_char *r_type_instr_set[] = {"add", "addu", "and", "div", "divu", "jr", "mfhi", "mflo", "mfc0", "mult",
        "multu", "nor", "xor", "or", "slt", "sltu", "sl", "sr", "sra", "sub", "subu"};
    const mips_char *j_type_instr_set[] = {"j", "ja"};
    const mips_char *i_type_instr_set[] = {"addi", "addiu", "andi", "beq", "bne", "lbu", "lhu", "lui", "lw", "ori",
        "sb", "sh", "slti", "sltiu", "sw"};
    const mips_char *pseudo_type_instr_set[] = {"blt", "bgt", "ble", "neg", "not", "bge", "li", "la", "move", "sge", "sgt"};
    const mips_char *reg_name_set[] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3",
        "$t4", "$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1",
        "$gp", "$sp", "$fp", "$ra"};
#endif

const list<mips_str> asm_directives(asm_directives_set,
								   asm_directives_set + sizeof(asm_directives_set) / sizeof(*asm_directives_set));

const list<mips_str> r_type_instructions(r_type_instr_set,
										r_type_instr_set + sizeof(r_type_instr_set) / sizeof(*r_type_instr_set));

const list<mips_str> j_type_instructions(j_type_instr_set,
										j_type_instr_set + sizeof(j_type_instr_set) / sizeof(*j_type_instr_set));

const list<mips_str> i_type_instructions(i_type_instr_set,
										i_type_instr_set + sizeof(i_type_instr_set) / sizeof(*i_type_instr_set));

const list<mips_str> pseudo_type_instructions(pseudo_type_instr_set,
										pseudo_type_instr_set + sizeof(pseudo_type_instr_set) / sizeof(*pseudo_type_instr_set));

const list<mips_str> reg_names(reg_name_set,
										reg_name_set + sizeof(reg_name_set) / sizeof(*reg_name_set));
