#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H
#include <QTextCharFormat>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QFile>
#include <QXmlStreamReader>

class highlighter : public QSyntaxHighlighter
{
public:
    highlighter(QTextDocument *parent = 0, const QString& kind = "");

protected:
    void highlightBlock(const QString &text) override;
private:

    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression = QRegularExpression("'");
    QRegularExpression commentEndExpression =  QRegularExpression("'");
    QTextCharFormat multiLineCommentFormat;
};

#endif // HIGHLIGHTER_H
