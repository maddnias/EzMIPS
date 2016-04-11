#pragma once
#include "..\token.h"

enum LITERAL_TYPE{
	LITERAL_TYPE_STRING = 0x1,
	LITERAL_TYPE_INT = 0x2,
	LITERAL_TYPE_COMMENT = 0x4
};

class literal_tok :
	public mips_token
{
public:
	literal_tok(LITERAL_TYPE type, unsigned int tok_row, unsigned int tok_col);
	~literal_tok(void);

	void set_type(LITERAL_TYPE directive);
	LITERAL_TYPE get_type();

private:
	LITERAL_TYPE m_type;
};

