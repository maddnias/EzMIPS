#pragma once
#include <memory>
#include <fstream>
#include "..\..\include\source_file.h"

class SourceReader
{
public:
	SourceReader(source_file *input);
	~SourceReader();

	bool is_eof();
	void eat_whitespace();
	int read();
	int peek();		
	int peek(int forward_count);
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
