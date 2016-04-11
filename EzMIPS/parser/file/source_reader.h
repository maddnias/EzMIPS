#pragma once
#include <memory>
#include <fstream>
#include <vector>
#include "..\..\include\source_file.h"

class source_reader
{
public:
	source_reader(source_file *input);
	~source_reader();

	bool is_eof();
	void eat_whitespace();
	int read();
	std::wstring read_int();
	std::wstring read_int(int peek_start);
	std::wstring read_hex_int();
	std::wstring read_hex_int(int peek_start);
	int peek();		
	int peek(int forward_count);
	void move_to(int count, STREAM_POS pos);
	std::wstring read_until(wchar_t ender);
	std::wstring read_until(std::vector<wchar_t> enders);
	void advance(int forward_count);
	bool is_integer(wint_t val);
	bool is_legal_identifier_start(wint_t val);
	bool matches(std::wstring str);
	bool matches_unique(std::wstring str);
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
