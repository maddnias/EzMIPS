#include "mips_highlighter.h"

mips_highlighter::mips_highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    QStringList keywordPatterns;
    keywordPatterns << "\\badd\\b" << "\\baddi\\b" << "\\baddiu"
                    << "\\baddu\\b" << "\\band\\b" << "\\bandi\\b"
                    << "\\bbeq\\b" << "\\bbne\\b" << "\\bdiv\\b"
                    << "\\bdivu\\b" << "\\bj\\b" << "\\bjal\\b"
                    << "\\bjr\\b" << "\\blbu\\b" << "\\blhu\\b"
                    << "\\blui\\b" << "\\blw\\b" << "\\bmfhi\\b"
                    << "\\bmflo\\b" << "\\bmfc0\\b" << "\\bmult\\b"
                    << "\\bmultu\\b" << "\\bnor\\b" << "\\bxor\\b"
                    << "\\bor\\b" << "\\bori\\b" << "\\bsb\\b"
                    << "\\bsb\\b" << "\\bslt\\b" << "\\bslti\\b"
                    << "\\bsltiu\\b" << "\\bsltu\\b" << "\\bsll\\b"
                    << "\\bsrl\\b" << "\\bsra\\b" << "\\bsub\\b"
                    << "\\bsubu\\b" << "\\bsw\\b" << "\\bblt\\b"
                    << "\\bbgt\\b" << "\\bble\\b" << "\\bneg\\b"
                    << "\\bnot\\b" << "\\bge\\b" << "\\bli\\b"
                    << "\\bla\\b" << "\\bmove\\b" << "\\bsge\b"
                    << "\\bsgt\\b";

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    registerFormat.setForeground(Qt::darkRed);
    QStringList registerPatterns;
    registerPatterns << "\\$1" << "\\$2" << "\\$3"
                     << "\\$4" << "\\$5" << "\\$6"
                     << "\\$7" << "\\$8" << "\\$9"
                     << "\\$10" << "\\$11" << "\\$12"
                     << "\\$13" << "\\$14" << "\\$15"
                     << "\\$16" << "\\$17" << "\\$18"
                     << "\\$19" << "\\$20" << "\\$21"
                     << "\\$22" << "\\$23" << "\\$24"
                     << "\\$25" << "\\$26" << "\\$27"
                     << "\\$28" << "\\$29" << "\\$30"
                     << "\\$31" << "\\$zero" << "\\$at"
                     << "\\$v0" << "\\$v1" << "\\$a0"
                     << "\\$a1" << "\\$a2" << "\\$a3"
                     << "\\$t0" << "\\$t1" << "\\$t2"
                     << "\\$t3" << "\\$t4" << "\\$t5"
                     << "\\$t6" << "\\$t7" << "\\$s0"
                     << "\\$s1" << "\\$s2" << "\\$s3"
                     << "\\$s4" << "\\$s5" << "\\$s6"
                     << "\\$s7" << "\\$t8" << "\\$t9"
                     << "\\$k0" << "\\$k1" << "\\$gp"
                     << "\\$sp" << "\\$fp" << "\\$ra";

    foreach (const QString &pattern, registerPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = registerFormat;
        highlightingRules.append(rule);
    }

    directiveFormat.setForeground(Qt::magenta);
    directiveFormat.setFontWeight(QFont::Bold);
    QStringList directivePatterns;
    directivePatterns << "\\.data\\b" << "\\.kdata\\b" << "\\.ktext\\b"
                      << "\\.ktext\\b" << "\\.text\\b";

    foreach (const QString &pattern, directivePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = directiveFormat;
        highlightingRules.append(rule);
    }

    datatypeFormat.setForeground(Qt::magenta);
    QStringList datatypePatterns;
    datatypePatterns << "\\.ascii\\b" << "\\.asciiz\\b" << "\\.byte\\b"
                     << "\\.double\\b" << "\\.float\\b" << "\\.half\\b"
                     << "\\.space\\b" << "\\.word\\b";

    foreach (const QString &pattern, datatypePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = datatypeFormat;
        highlightingRules.append(rule);
    }

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("#[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);
}

void mips_highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);
}
