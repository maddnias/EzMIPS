#ifndef SOURCE_READER_H
#define SOURCE_READER_H

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
    bool is_eof(int look_ahead);
	void eat_whitespace();
	int read();
    std::string read_int();
    std::string read_int(int peek_start);
    std::string read_hex_int();
    std::string read_hex_int(int peek_start);
	int peek();		
	int peek(int forward_count);
	void move_to(int count, STREAM_POS pos);
    std::string read_until(char ender);
    std::string read_until(std::vector<char> enders);
	void advance(int forward_count);
	bool is_integer(wint_t val);
	bool is_legal_identifier_start(wint_t val);
    bool matches(std::string str);
    bool matches_unique(std::string str);
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

#endif
