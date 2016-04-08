#include "..\..\include\source_file.h"
#include <memory>
#include <locale>
#include <fstream>
#include <codecvt>

using namespace std;

source_file::source_file(wstring file):
	m_filename(file),
	m_pos(0)
{
}

source_file::~source_file(void)
{
	delete m_src;
}

bool source_file::load(){
	wifstream fin(m_filename, ifstream::in|ifstream::binary);
	
	fin.seekg(0, ios::end);
	m_size = fin.tellg();
	fin.seekg(0, ios::beg);

	m_src = new wchar_t[m_size];

	try{
		fin.read(m_src, m_size);
	} catch(...){
		return false;
	}

	wstring test;
	while(!eof()){
		test += get();
	}
	return true;
}

bool source_file::eof(){
	return m_pos > m_size;
}

bool source_file::fail(){
	return false;
}

wchar_t source_file::peek(){
	if(!is_in_range()){
		return -1;
	}
	return m_src[m_pos+1];
}

wchar_t source_file::peek(int forward_count){
	if(!is_in_range(forward_count)){
		return -1;
	}
	return m_src[m_pos+forward_count];
}

wchar_t source_file::get(){
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
