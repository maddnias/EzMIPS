#ifndef MIPS_HIGHLIGHTER_H
#define MIPS_HIGHLIGHTER_H
#include <QSyntaxHighlighter>


class mips_highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    mips_highlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat keywordFormat;
    QTextCharFormat registerFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat directiveFormat;
    QTextCharFormat datatypeFormat;
};

#endif // MIPS_HIGHLIGHTER_H
