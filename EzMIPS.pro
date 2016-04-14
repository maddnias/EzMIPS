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
                                                                       ^
QMAKE_CXXFLAGS_WARN_ON += -Wno-reorder
QMAKE_CXXFLAGS_WARN_ON += -Wunused-parameter

INCLUDEPATH += "src/"\
            "src/include/"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EzMIPS
TEMPLATE = app


SOURCES += src/main.cpp\
    src/parser/file/source_file.cpp \
    src/parser/file/source_reader.cpp \
    src/parser/lexer/token_handlers/asm_directives_handler.cpp \
    src/parser/lexer/token_handlers/i_instr_handler.cpp \
    src/parser/lexer/token_handlers/j_instr_handler.cpp \
    src/parser/lexer/token_handlers/literal_handler.cpp \
    src/parser/lexer/token_handlers/pseudo_instr_handler.cpp \
    src/parser/lexer/token_handlers/r_instr_handler.cpp \
    src/parser/lexer/token_handlers/reg_handler.cpp \
    src/parser/lexer/token_handlers/token_handler.cpp \
    src/parser/lexer/tokens/asm_directive_tok.cpp \
    src/parser/lexer/tokens/i_instr_tok.cpp \
    src/parser/lexer/tokens/instr_base_tok.cpp \
    src/parser/lexer/tokens/j_instr_tok.cpp \
    src/parser/lexer/tokens/label_decl_tok.cpp \
    src/parser/lexer/tokens/label_ref_tok.cpp \
    src/parser/lexer/tokens/literal_tok.cpp \
    src/parser/lexer/tokens/pseudo_instr_tok.cpp \
    src/parser/lexer/tokens/r_instr_tok.cpp \
    src/parser/lexer/tokens/reg_tok.cpp \
    src/parser/lexer/tokens/undefined_tok.cpp \
    src/parser/lexer/token.cpp \
    src/parser/lexer/tokenizer.cpp \
    src/parser/parser_context.cpp \
    src/parser/parser_error.cpp \
    src/simulator/assembler/mips_instr_writer.cpp \
    src/simulator/instructions/mips_instr.cpp \
    src/simulator/instructions/mips_instr_add.cpp \
    src/simulator/instructions/mips_operand_container.cpp \
    src/simulator/executor.cpp \
    src/simulator/mem_segment.cpp \
    src/simulator/runtime_context.cpp \
    src/gui/mips_highlighter.cpp \
    src/gui/editor_window.cpp \
    src/gui/mainwindow.cpp

HEADERS  += \
    src/include/executor.h \
    src/include/source_file.h \
    src/include/tokenizer.h \
    src/parser/file/source_reader.h \
    src/parser/lexer/token_handlers/asm_directives_handler.h \
    src/parser/lexer/token_handlers/i_instr_handler.h \
    src/parser/lexer/token_handlers/j_instr_handler.h \
    src/parser/lexer/token_handlers/literal_handler.h \
    src/parser/lexer/token_handlers/pseudo_instr_handler.h \
    src/parser/lexer/token_handlers/r_instr_handler.h \
    src/parser/lexer/token_handlers/reg_handler.h \
    src/parser/lexer/token_handlers/token_handler.h \
    src/parser/lexer/tokens/asm_directive_tok.h \
    src/parser/lexer/tokens/i_instr_tok.h \
    src/parser/lexer/tokens/instr_base_tok.h \
    src/parser/lexer/tokens/j_instr_tok.h \
    src/parser/lexer/tokens/label_decl_tok.h \
    src/parser/lexer/tokens/label_ref_tok.h \
    src/parser/lexer/tokens/literal_tok.h \
    src/parser/lexer/tokens/pseudo_instr_tok.h \
    src/parser/lexer/tokens/r_instr_tok.h \
    src/parser/lexer/tokens/reg_tok.h \
    src/parser/lexer/tokens/undefined_tok.h \
    src/parser/lexer/instr_sets.h \
    src/parser/lexer/token.h \
    src/parser/parser_context.h \
    src/parser/parser_error.h \
    src/simulator/assembler/mips_instr_writer.h \
    src/simulator/instructions/mips_instr.h \
    src/simulator/instructions/mips_instr_add.h \
    src/simulator/instructions/mips_operand_container.h \
    src/simulator/mem_segment.h \
    src/simulator/runtime_context.h \
    src/gui/mips_highlighter.h \
    src/gui/editor_window.h \
    src/gui/mainwindow.h

FORMS    += \
    src/gui/editor_window.ui \
    src/gui/mainwindow.ui
