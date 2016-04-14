#ifndef SOURCE_FILE_H
#define SOURCE_FILE_H


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
    source_file(std::string file);
	~source_file(void);

    bool save();
    bool load();
    void set_data(int size, char *data);
	bool eof();
    bool eof(int look_ahead);
	bool fail();
    char peek();
    char peek(int forward_count);
    char get();
	void move_to(int count, STREAM_POS pos);

    std::string m_filename;

private:
	bool is_in_range();
	bool is_in_range(int count);
    void src_sanity_check();

    char *m_src;
	unsigned int m_size;
	unsigned int m_pos;
};

#endif
