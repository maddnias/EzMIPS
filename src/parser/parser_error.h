#ifndef PARSER_ERROR_H
#define PARSER_ERROR_H

#include <string>
#include <vector>
#include <memory>

class parser_error
{
public:
    parser_error(std::string err_desc, unsigned int err_row,
		unsigned int err_col);
    ~parser_error(void);

    std::string get_error_desc();
    unsigned int get_error_row();
    unsigned int get_error_col();

private:
	std::string m_err_desc;
	unsigned int m_err_row;
	unsigned int m_err_col;
};

#endif
