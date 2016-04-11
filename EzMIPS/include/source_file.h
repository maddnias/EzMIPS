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

	bool load();
	bool eof();
	bool fail();
    mips_char peek();
    mips_char peek(int forward_count);
    mips_char get();
	void move_to(int count, STREAM_POS pos);

private:
	bool is_in_range();
	bool is_in_range(int count);

    mips_char *m_src;
	unsigned int m_size;
	unsigned int m_pos;
    mips_str m_filename;
    mips_str_stream m_data;
};

#endif
