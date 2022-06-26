#ifndef EDITOR_H
#define EDITOR_H
#include <QPlainTextEdit>
#include <QCompleter>
#include <QStringListModel>
#include <QShortcut>
#include "highlighter.h"


class editor : public QPlainTextEdit
{
   public:
       editor(QWidget* parent = nullptr, const QString &filter = "cpp");
       QString location;

   private:
       QStringListModel* model;

       //void CreateConnections();
      // void highlightCurrentLine();
};

#endif // EDITOR_H
