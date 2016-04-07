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