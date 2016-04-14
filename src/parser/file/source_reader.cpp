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

bool source_reader::is_eof(int look_ahead){
    return m_input->eof(look_ahead);
}

void source_reader::eat_whitespace(){
	int curChar;
    while(isspace(curChar = read())){
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

std::string source_reader::read_int(){
	return read_int(0);
}

std::string source_reader::read_int(int peek_start){
	int counter = peek_start;
    std::string finalBuff;
	while(is_integer(peek(counter))){
		finalBuff += peek(counter++);
	}
	return finalBuff;
}

std::string source_reader::read_hex_int(){
	return read_hex_int(0);
}

std::string source_reader::read_hex_int(int peek_start){
    std::string finalBuff;
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

std::string source_reader::read_until(char ender){
    vector<char> v;
	v.push_back(ender);
	return read_until(v);
}

std::string source_reader::read_until(vector<char> enders){
	bool flag = true;
    std::string outBuff;
	for(int i = 0;flag;i++){
        if(is_eof(i)){
            return outBuff;
        }
		outBuff += peek(i);
        for(vector<char>::iterator it = enders.begin();it != enders.end();it++){
            if(*it == peek(i) || is_eof()){
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
    return isalpha(val) != 0;
}

bool source_reader::matches(std::string str){
	for(unsigned int i = 0;i < str.length();i++){
		if(peek(i) != str.at(i)){
			return false;
		}
	}
	return true;
}

bool source_reader::matches_unique(std::string str){
    char test = peek(0);
	for(unsigned int i = 0;i < str.length();i++){
		if(peek(i) != str.at(i)){
			return false;
		}
	}
    return isspace(peek(str.length())) != 0;
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
