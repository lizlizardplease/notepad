#include "editor.h"
#include <QRect>
#include <QPainter>
#include <QTextBlock>


editor::editor(QWidget *parent, const QString &filter) : QPlainTextEdit(parent)
{
    (void) new highlighter(document(), filter);
    model = new QStringListModel(this);
    //highlightCurrentLine();
    //CreateConnections();
}

/*void editor::CreateConnections()
{
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
}
void editor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;
    QBrush highlightColor = QColor(255, 0, 0, 25);
    selection.format.setBackground(highlightColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);
    setExtraSelections(extraSelections);
}*/
