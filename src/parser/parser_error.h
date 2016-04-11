#pragma once
#include "platform_dependencies.h"

#include <string>
#include <vector>
#include <memory>

class ParserError
{
public:
	ParserError(mips_str err_desc, unsigned int err_row,
		unsigned int err_col);
	~ParserError(void);

	mips_str get_err_desc();

private:
	mips_str m_err_desc;
	unsigned int m_err_row;
	unsigned int m_err_col;
};

typedef std::shared_ptr<ParserError> ParserErrorPtr;
typedef std::vector<ParserErrorPtr> ParserErrorVector;
