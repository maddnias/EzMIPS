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

int _tmain(int argc, _TCHAR* argv[])
{

	std::wifstream ws;
	ws.open("C:\\TestScript.txt", std::wifstream::binary);
	mips_tokenizer t = mips_tokenizer();

	//auto start_time = std::chrono::high_resolution_clock::now();
	mips_tok_vector toks = t.parse_tokens(ws);
	//auto current_time = std::chrono::high_resolution_clock::now();

	//auto duration = std::chrono::duration_cast<std::chrono::duration<float>>(current_time - start_time).count();
	//std::cout<<"Tokens parsed per second: "<< toks.size()/duration <<'\n';

	/*for(mips_tok_vector::iterator it = toks.begin();it != toks.end();it++){
		std::wcout << (*it)->get_formatted_token() << std::endl;
	}*/

	//while(true){
	//	std::wstring s;
	//	std::wstringstream ws;
	//	mips_tokenizer t(ws);
	//	std::wcin >> s;
	//	ws << s;
	//	t.parse_tokens();
	//}

	return 0;
}

