#pragma once
#include <string>
#include <sstream>

enum STREAM_POS{
	STREAM_POS_START = 0x0,
	STREAM_POS_CUR = 0x1,
	STREAM_POS_END = 0x2
};

const unsigned int BUFF_SIZE = 4096;

class source_file
{
public:
	source_file(std::wstring file);
	~source_file(void);

	bool load();
	bool eof();
	bool fail();
	wchar_t peek();
	wchar_t peek(int forward_count);
	wchar_t get();
	void move_to(int count, STREAM_POS pos);

private:
	bool is_in_range();
	bool is_in_range(int count);

	wchar_t *m_src;
	unsigned int m_size;
	unsigned int m_pos;
	std::wstring m_filename;
	std::wstringstream m_data;
};

