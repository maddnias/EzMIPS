#ifndef INSTR_SETS_H
#define INSTR_SETS_H

#include <list>
#include <string>

using namespace std;

const char *asm_directives_set[] = {".data", ".text", ".align", ".ascii", ".asciiz"};
const char *r_type_instr_set[] = {"add", "addu", "and", "div", "divu", "jr", "mfhi", "mflo", "mfc0", "mult",
    "multu", "nor", "xor", "or", "slt", "sltu", "sl", "sr", "sra", "sub", "subu"};
const char *j_type_instr_set[] = {"j", "ja"};
const char *i_type_instr_set[] = {"addi", "addiu", "andi", "beq", "bne", "lbu", "lhu", "lui", "lw", "ori",
    "sb", "sh", "slti", "sltiu", "sw"};
const char *pseudo_type_instr_set[] = {"blt", "bgt", "ble", "neg", "not", "bge", "li", "la", "move", "sge", "sgt"};
const char *reg_name_set[] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3",
    "$t4", "$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1",
    "$gp", "$sp", "$fp", "$ra"};

const list<std::string> asm_directives(asm_directives_set,
								   asm_directives_set + sizeof(asm_directives_set) / sizeof(*asm_directives_set));

const list<std::string> r_type_instructions(r_type_instr_set,
										r_type_instr_set + sizeof(r_type_instr_set) / sizeof(*r_type_instr_set));

const list<std::string> j_type_instructions(j_type_instr_set,
										j_type_instr_set + sizeof(j_type_instr_set) / sizeof(*j_type_instr_set));

const list<std::string> i_type_instructions(i_type_instr_set,
										i_type_instr_set + sizeof(i_type_instr_set) / sizeof(*i_type_instr_set));

const list<std::string> pseudo_type_instructions(pseudo_type_instr_set,
										pseudo_type_instr_set + sizeof(pseudo_type_instr_set) / sizeof(*pseudo_type_instr_set));

const list<std::string> reg_names(reg_name_set,
										reg_name_set + sizeof(reg_name_set) / sizeof(*reg_name_set));
#endif
