// EzMIPS.UI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tokenizer.h"
#include <sstream>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <codecvt>
#include <chrono>
#include "source_file.h"

int _tmain(int argc, _TCHAR* argv[])
{
	source_file *t = new source_file(L"C:\\TestScript.txt");
	t->load();

	mips_tokenizer t2;
	auto start_time = std::chrono::high_resolution_clock::now();

	auto tokens = t2.parse_tokens(t);

	auto current_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<float>>(current_time - start_time).count();
	std::cout<<"Tokens parsed per second: "<< tokens.size()/duration <<'\n';
	
	return 0;
}

