#ifndef MIPS_ASSEMBLER_H
#define MIPS_ASSEMBLER_H
#include "source_file.h"


class mips_assembler
{
public:
    mips_assembler(source_file *file);

private:
    source_file *m_file;
};

#endif // MIPS_ASSEMBLER_H
