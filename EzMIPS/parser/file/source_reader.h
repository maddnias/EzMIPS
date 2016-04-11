#pragma once
#include <memory>
#include <fstream>
#include <vector>
#include "source_file.h"

class source_reader
{
public:
	source_reader(source_file *input);
	~source_reader();

	bool is_eof();
	void eat_whitespace();
	int read();
    mips_str read_int();
    mips_str read_int(int peek_start);
    mips_str read_hex_int();
    mips_str read_hex_int(int peek_start);
	int peek();		
	int peek(int forward_count);
	void move_to(int count, STREAM_POS pos);
    mips_str read_until(mips_char ender);
    mips_str read_until(std::vector<mips_char> enders);
	void advance(int forward_count);
	bool is_integer(wint_t val);
	bool is_legal_identifier_start(wint_t val);
    bool matches(mips_str str);
    bool matches_unique(mips_str str);
	void reset();

	void advance_row();
	void reset_col();
	void advance_col();
	void decrement_col();
	void decrement_col(unsigned int count);

	unsigned int get_current_row();
	unsigned int get_current_col();

private:
	unsigned int m_current_row;
	unsigned int m_current_col;
	source_file *m_input;
};
