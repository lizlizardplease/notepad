#include "highlighter.h"

highlighter::highlighter(QTextDocument *parent, const QString& kind): QSyntaxHighlighter(parent)
{
    QFile* file = new QFile("../notepad/resources/settings.xml");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Couldn't open file";
           return;
    }
    HighlightingRule rule;
    QXmlStreamReader reader(file);
    while(!(reader.name().toString() == "syntax" && ((reader.attributes().value("ext_list").toString().contains(kind)) ||
            (reader.attributes().value("ext_list").toString() == "def")))){
        reader.readNextStartElement();
    }
    if(reader.hasError()) {
        qDebug() << reader.errorString();
    }
    reader.readNextStartElement();
    while((!(reader.name().toString() == "mcomment" || reader.name().toString() == "syntax") ) && !reader.hasError()) {
        if(reader.name().toString() == "rule"){
            reader.readNext();
            QColor color;
            color.setNamedColor(reader.attributes().value("foreground").toString());
            int fw = reader.attributes().value("font_weight").toInt();
            reader.readNextStartElement();
            reader.readNextStartElement();
            while (reader.name().toString() == "pattern"){
                rule.format.setFontWeight(fw);
                rule.pattern = QRegularExpression(reader.attributes().value("value").toString());
                rule.format.setForeground(color);
                highlightingRules.append(rule);
                reader.readNext();
                reader.readNext();
            }
        }
        reader.readNextStartElement();
       }
       if (reader.name().toString() == "mcomment"){
           QColor color;
           color.setNamedColor(reader.attributes().value("foreground").toString());
           multiLineCommentFormat.setForeground(color);
           multiLineCommentFormat.setFontItalic(reader.attributes().value("italic").toInt());
           multiLineCommentFormat.setFontWeight(reader.attributes().value("font_weight").toInt());
           commentStartExpression = QRegularExpression(reader.attributes().value("start").toString());
           commentEndExpression = QRegularExpression(reader.attributes().value("end").toString());
       }
       if(reader.hasError()) {
           qDebug() << reader.errorString();
       }
       reader.clear();
}

void highlighter::highlightBlock(const QString &text)
{
    for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
   setCurrentBlockState(0);
   int startIndex = 0;
   if (previousBlockState() != 1){
        startIndex = text.indexOf(commentStartExpression);
   }
   while (startIndex >= 0) {
           QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
           int endIndex = match.capturedStart();
           int commentLength = 0;
           if (endIndex == -1) {
               setCurrentBlockState(1);
               commentLength = text.length() - startIndex;
           } else {
               commentLength = endIndex - startIndex
                               + match.capturedLength();
           }
           setFormat(startIndex, commentLength, multiLineCommentFormat);
           startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
       }
}
