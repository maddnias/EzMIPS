#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T15:42:43
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

CONFIG(debug, debug|release) {
    DESTDIR = build/debug
}
CONFIG(release, debug|release) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u

INCLUDEPATH += "EzMIPS/"\
            "EzMIPS/include/"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EzMIPS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    EzMIPS/parser/file/source_file.cpp \
    EzMIPS/parser/file/source_reader.cpp \
    EzMIPS/parser/lexer/token_handlers/asm_directives_handler.cpp \
    EzMIPS/parser/lexer/token_handlers/i_instr_handler.cpp \
    EzMIPS/parser/lexer/token_handlers/j_instr_handler.cpp \
    EzMIPS/parser/lexer/token_handlers/literal_handler.cpp \
    EzMIPS/parser/lexer/token_handlers/pseudo_instr_handler.cpp \
    EzMIPS/parser/lexer/token_handlers/r_instr_handler.cpp \
    EzMIPS/parser/lexer/token_handlers/reg_handler.cpp \
    EzMIPS/parser/lexer/token_handlers/token_handler.cpp \
    EzMIPS/parser/lexer/tokens/asm_directive_tok.cpp \
    EzMIPS/parser/lexer/tokens/i_instr_tok.cpp \
    EzMIPS/parser/lexer/tokens/instr_base_tok.cpp \
    EzMIPS/parser/lexer/tokens/j_instr_tok.cpp \
    EzMIPS/parser/lexer/tokens/label_decl_tok.cpp \
    EzMIPS/parser/lexer/tokens/label_ref_tok.cpp \
    EzMIPS/parser/lexer/tokens/literal_tok.cpp \
    EzMIPS/parser/lexer/tokens/pseudo_instr_tok.cpp \
    EzMIPS/parser/lexer/tokens/r_instr_tok.cpp \
    EzMIPS/parser/lexer/tokens/reg_tok.cpp \
    EzMIPS/parser/lexer/tokens/undefined_tok.cpp \
    EzMIPS/parser/lexer/token.cpp \
    EzMIPS/parser/lexer/tokenizer.cpp \
    EzMIPS/parser/parser_context.cpp \
    EzMIPS/parser/parser_error.cpp \
    EzMIPS/simulator/assembler/mips_instr_writer.cpp \
    EzMIPS/simulator/instructions/mips_instr.cpp \
    EzMIPS/simulator/instructions/mips_instr_add.cpp \
    EzMIPS/simulator/instructions/mips_operand_container.cpp \
    EzMIPS/simulator/executor.cpp \
    EzMIPS/simulator/mem_segment.cpp \
    EzMIPS/simulator/runtime_context.cpp \

HEADERS  += mainwindow.h \
    EzMIPS/include/executor.h \
    EzMIPS/include/source_file.h \
    EzMIPS/include/tokenizer.h \
    EzMIPS/parser/file/source_reader.h \
    EzMIPS/parser/lexer/token_handlers/asm_directives_handler.h \
    EzMIPS/parser/lexer/token_handlers/i_instr_handler.h \
    EzMIPS/parser/lexer/token_handlers/j_instr_handler.h \
    EzMIPS/parser/lexer/token_handlers/literal_handler.h \
    EzMIPS/parser/lexer/token_handlers/pseudo_instr_handler.h \
    EzMIPS/parser/lexer/token_handlers/r_instr_handler.h \
    EzMIPS/parser/lexer/token_handlers/reg_handler.h \
    EzMIPS/parser/lexer/token_handlers/token_handler.h \
    EzMIPS/parser/lexer/tokens/asm_directive_tok.h \
    EzMIPS/parser/lexer/tokens/i_instr_tok.h \
    EzMIPS/parser/lexer/tokens/instr_base_tok.h \
    EzMIPS/parser/lexer/tokens/j_instr_tok.h \
    EzMIPS/parser/lexer/tokens/label_decl_tok.h \
    EzMIPS/parser/lexer/tokens/label_ref_tok.h \
    EzMIPS/parser/lexer/tokens/literal_tok.h \
    EzMIPS/parser/lexer/tokens/pseudo_instr_tok.h \
    EzMIPS/parser/lexer/tokens/r_instr_tok.h \
    EzMIPS/parser/lexer/tokens/reg_tok.h \
    EzMIPS/parser/lexer/tokens/undefined_tok.h \
    EzMIPS/parser/lexer/instr_sets.h \
    EzMIPS/parser/lexer/token.h \
    EzMIPS/parser/parser_context.h \
    EzMIPS/parser/parser_error.h \
    EzMIPS/simulator/assembler/mips_instr_writer.h \
    EzMIPS/simulator/instructions/mips_instr.h \
    EzMIPS/simulator/instructions/mips_instr_add.h \
    EzMIPS/simulator/instructions/mips_operand_container.h \
    EzMIPS/simulator/mem_segment.h \
    EzMIPS/simulator/runtime_context.h \
    EzMIPS/platform_dependencies.h

FORMS    += mainwindow.ui
