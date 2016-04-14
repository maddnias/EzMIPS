#include "../../include/source_file.h"
#include <memory>
#include <locale>
#include <qdebug.h>
#include <fstream>

using namespace std;

source_file::source_file(std::string file):
	m_filename(file),
    m_pos(0),
    m_size(0),
    m_src(NULL)
{
}

source_file::~source_file(void)
{
	delete m_src;
}

bool source_file::save(){
    ofstream fout(m_filename, ios::out);

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
    std::ifstream fin(filename, std::ifstream::in|std::ifstream::binary);
#elif __linux__
    std::ifstream fin(m_filename, std::ifstream::in|std::ifstream::binary);
#endif


	fin.seekg(0, ios::end);
	m_size = fin.tellg();
	fin.seekg(0, ios::beg);

    m_src = new char[m_size];

	try{
		fin.read(m_src, m_size);
	} catch(...){
		return false;
	}
	return true;
}

void source_file::set_data(int size, char *data){
    src_sanity_check();
    m_pos = 0;
    m_size = size;
    m_src = new char[size];
    memcpy(m_src, data, size);
}

bool source_file::eof(){
    return m_pos > m_size;
}

bool source_file::eof(int look_ahead){
    return m_pos+look_ahead > m_size;
}

bool source_file::fail(){
	return false;
}

char source_file::peek(){
	if(!is_in_range()){
		return -1;
	}
	return m_src[m_pos];
}

char source_file::peek(int forward_count){
	if(!is_in_range(forward_count)){
		return -1;
	}
	return m_src[m_pos+forward_count];
}

char source_file::get(){
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

