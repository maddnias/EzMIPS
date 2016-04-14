#ifndef PLATFORM_DEPENDENCIES_H
#define PLATFORM_DEPENDENCIES_H
#include <fstream>
#include <string>

#ifdef _WIN32
    #define mips_null_str L""
    #define mips_str std::wstring
    #define mips_char wchar_t
    #define mips_str_stream std::stringstream
    #define mips_f_stream std::wifstream
    #define mips_of_stream std::wofstream
    #define mips_isspace std::iswspace
    #define mips_isalpha std::iswalpha
    #define MAKE_QSTRING(str) QString::fromStdWString(str)
    #define FROM_QSTRING(str) str.toStdWString();
#elif __linux__
    #define mips_null_str ""
    #define mips_str std::string
    #define mips_char char
    #define mips_str_stream std::stringstream
    #define mips_f_stream std::ifstream
    #define mips_of_stream std::ofstream
    #define mips_isspace std::isspace
    #define mips_isalpha std::isalpha
    #define MAKE_QSTRING(str) QString(str)
    #define FROM_QSTRING(str) std::string(str.toStdString())
#endif

#endif // PLATFORM_DEPENDENCIES_H
