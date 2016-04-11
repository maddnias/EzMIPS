#pragma once
#include <list>
#include <string>

using namespace std;

const wchar_t *asm_directives_set[] = {L".data", L".text", L".align", L".ascii", L".asciiz"};
const list<wstring> asm_directives(asm_directives_set,
								   asm_directives_set + sizeof(asm_directives_set) / sizeof(*asm_directives_set));

const wchar_t *r_type_instr_set[] = {L"add", L"addu", L"and", L"div", L"divu", L"jr", L"mfhi", L"mflo", L"mfc0", L"mult",
	L"multu", L"nor", L"xor", L"or", L"slt", L"sltu", L"sll", L"srl", L"sra", L"sub", L"subu"};
const list<wstring> r_type_instructions(r_type_instr_set,
										r_type_instr_set + sizeof(r_type_instr_set) / sizeof(*r_type_instr_set));

const wchar_t *j_type_instr_set[] = {L"j", L"jal"};
const list<wstring> j_type_instructions(j_type_instr_set,
										j_type_instr_set + sizeof(j_type_instr_set) / sizeof(*j_type_instr_set));

const wchar_t *i_type_instr_set[] = {L"addi", L"addiu", L"andi", L"beq", L"bne", L"lbu", L"lhu", L"lui", L"lw", L"ori",
	L"sb", L"sh", L"slti", L"sltiu", L"sw"};
const list<wstring> i_type_instructions(i_type_instr_set,
										i_type_instr_set + sizeof(i_type_instr_set) / sizeof(*i_type_instr_set));

const wchar_t *pseudo_type_instr_set[] = {L"blt", L"bgt", L"ble", L"neg", L"not", L"bge", L"li", L"la", L"move", L"sge", L"sgt"};
const list<wstring> pseudo_type_instructions(pseudo_type_instr_set,
										pseudo_type_instr_set + sizeof(pseudo_type_instr_set) / sizeof(*pseudo_type_instr_set));

const wchar_t *reg_name_set[] = {L"$zero", L"$at", L"$v0", L"$v1", L"$a0", L"$a1", L"$a2", L"$a3", L"$t0", L"$t1", L"$t2", L"$t3",
	L"$t4", L"$t5", L"$t6", L"$t7", L"$s0", L"$s1", L"$s2", L"$s3", L"$s4", L"$s5", L"$s6", L"$s7", L"$t8", L"$t9", L"$k0", L"$k1",
	L"$gp", L"$sp", L"$fp", L"$ra"};
const list<wstring> reg_names(reg_name_set,
										reg_name_set + sizeof(reg_name_set) / sizeof(*reg_name_set));