#include "source_reader.h"

using namespace std;

source_reader::source_reader(source_file *input):
m_input(input),
m_current_col(0),
m_current_row(0){
}

source_reader::~source_reader(){

}

bool source_reader::is_eof(){
	return m_input->eof() || m_input->fail();
}

void source_reader::eat_whitespace(){
	int curChar;
	while(iswspace(curChar = read())){
		if(curChar == '\n'){
			advance_row();
			reset_col();
		}
	};
	decrement_col();
	m_input->move_to(-1, STREAM_POS_CUR);
}

int source_reader::read(){
	advance_col();
	return m_input->get();
}

mips_str source_reader::read_int(){
	return read_int(0);
}

mips_str source_reader::read_int(int peek_start){
	int counter = peek_start;
	mips_str finalBuff;
	while(is_integer(peek(counter))){
		finalBuff += peek(counter++);
	}
	return finalBuff;
}

mips_str source_reader::read_hex_int(){
	return read_hex_int(0);
}

mips_str source_reader::read_hex_int(int peek_start){
	mips_str finalBuff;
	int counter = peek_start;
	while(is_integer(peek(counter)) 
		|| is_legal_identifier_start(peek(counter))){
			finalBuff += peek(counter++);
	}
	return finalBuff;
}

int source_reader::peek(){
	return m_input->peek();
}

int source_reader::peek(int forward_count){
	return m_input->peek(forward_count);
}

void source_reader::move_to(int count, STREAM_POS pos){
	return m_input->move_to(count, pos);
}

mips_str source_reader::read_until(mips_char ender){
	vector<mips_char> v;
	v.push_back(ender);
	return read_until(v);
}

mips_str source_reader::read_until(vector<mips_char> enders){
	bool flag = true;
	mips_str outBuff;
	for(int i = 0;flag;i++){
		outBuff += peek(i);
		for(vector<mips_char>::iterator it = enders.begin();it != enders.end();it++){
			if(*it == peek(i)){
				flag = false;
				break;
			}
		}
	}
	return outBuff;
}

void source_reader::advance(int forward_count){
	for(int i = 0;i < forward_count;i++){
		read();
	}
}

bool source_reader::is_integer(wint_t val){
	return iswdigit(val) != 0;
}

bool source_reader::is_legal_identifier_start(wint_t val){
	return iswalpha(val) != 0;
}

bool source_reader::matches(mips_str str){
	for(unsigned int i = 0;i < str.length();i++){
		if(peek(i) != str.at(i)){
			return false;
		}
	}
	return true;
}

bool source_reader::matches_unique(mips_str str){
	mips_char test = peek(0);
	for(unsigned int i = 0;i < str.length();i++){
		if(peek(i) != str.at(i)){
			return false;
		}
	}
	return iswspace(peek(str.length())) != 0;
}


void source_reader::reset(){
	m_current_col = 0;
	m_current_row = 0;
	m_input->move_to(0, STREAM_POS_START);
}

void source_reader::advance_row(){
	m_current_row++;
}

void source_reader::reset_col(){
	m_current_col = 0;
}

void source_reader::advance_col(){
	m_current_col++;
}

void source_reader::decrement_col(){
	m_current_col--;
}

void source_reader::decrement_col(unsigned int count){
	m_current_col -= count;
}

unsigned int source_reader::get_current_row(){
	return m_current_row;
}

unsigned int source_reader::get_current_col(){
	return m_current_col;
}