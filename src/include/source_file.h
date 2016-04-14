#ifndef SOURCE_FILE_H
#define SOURCE_FILE_H

#include "platform_dependencies.h"
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
    source_file(mips_str file);
	~source_file(void);

    bool save();
    bool load();
    void set_data(int size, mips_char *data);
	bool eof();
	bool fail();
    mips_char peek();
    mips_char peek(int forward_count);
    mips_char get();
	void move_to(int count, STREAM_POS pos);

    mips_str m_filename;

private:
	bool is_in_range();
	bool is_in_range(int count);
    void src_sanity_check();

    std::string to_utf8(const wchar_t* buffer, int len);
    std::string to_utf8(const std::wstring& str);

    mips_char *m_src;
	unsigned int m_size;
	unsigned int m_pos;
};

#endif
