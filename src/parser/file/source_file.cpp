#include "../../include/source_file.h"
#include <memory>
#include <locale>
#include <qdebug.h>
#include <fstream>
#include "windows.h"
#include <locale>

using namespace std;

source_file::source_file(mips_str file):
	m_filename(file),
    m_pos(0),
    m_size(0)
{
}

source_file::~source_file(void)
{
	delete m_src;
}

bool source_file::save(){
    std::locale::global(std::locale(""));
#if _WIN32
    string filename(m_filename.begin(), m_filename.end());
    ofstream fout(filename, ios::out|ios::binary);
#elif __linux__
    ofstream fout(filename, ios::out);
#endif

    try {
        fout.write(m_src, m_size);
    } catch(...){
        return false;
    }
    fout.flush();
    fout.close();
    return true;
}

bool source_file::load(){
    src_sanity_check();

#if _WIN32
    string filename(m_filename.begin(), m_filename.end());
    mips_f_stream fin(filename, mips_f_stream::in|mips_f_stream::binary);
#elif __linux__
    mips_f_stream fin(m_filename, mips_f_stream::in|mips_f_stream::binary);
#endif


	fin.seekg(0, ios::end);
	m_size = fin.tellg();
	fin.seekg(0, ios::beg);

    m_src = new mips_char[m_size];

	try{
		fin.read(m_src, m_size);
	} catch(...){
		return false;
	}
	return true;
}

void source_file::set_data(int size, mips_char *data){
    src_sanity_check();
    m_pos = 0;
    m_size = size;
    m_src = new mips_char[size];
    memcpy(m_src, data, size);
}

bool source_file::eof(){
	return m_pos > m_size;
}

bool source_file::fail(){
	return false;
}

mips_char source_file::peek(){
	if(!is_in_range()){
		return -1;
	}
	return m_src[m_pos];
}

mips_char source_file::peek(int forward_count){
	if(!is_in_range(forward_count)){
		return -1;
	}
	return m_src[m_pos+forward_count];
}

mips_char source_file::get(){
	if(!is_in_range()){
		return -1;
	}
	return m_src[m_pos++];
}

//TODO: is_in_range() ?
void source_file::move_to(int count, STREAM_POS pos){
	switch(pos){
	case STREAM_POS_START:
		m_pos = count;
		break;
	case STREAM_POS_CUR:
		m_pos += count;
		break;
	case STREAM_POS_END:
		m_pos = BUFF_SIZE - count;
		break;
	}
}

bool source_file::is_in_range(){
	return is_in_range(1);
}

bool source_file::is_in_range(int count){
	return m_pos + count >= 0 && m_pos + count <= m_size +1;
}

void source_file::src_sanity_check(){
    if(m_src != NULL){
        delete m_src;
    }
}

