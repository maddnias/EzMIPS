#pragma once
#include <string>
#include <vector>
#include <memory>

class ParserError
{
public:
	ParserError(std::wstring err_desc, unsigned int err_row,
		unsigned int err_col);
	~ParserError(void);

	std::wstring get_err_desc();

private:
	std::wstring m_err_desc;
	unsigned int m_err_row;
	unsigned int m_err_col;
};

typedef std::shared_ptr<ParserError> ParserErrorPtr;
typedef std::vector<ParserErrorPtr> ParserErrorVector;