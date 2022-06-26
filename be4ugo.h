#ifndef BE4UGO_H
#define BE4UGO_H

#include <QDialog>
#include <QTableWidget>
#include "editor.h"
namespace Ui {
class be4Ugo;
}

class be4Ugo : public QDialog
{
    Q_OBJECT

public:
    QTableWidget* table;
    explicit be4Ugo(QWidget *parent = nullptr);
    void fill_table(QTabWidget* data);
    ~be4Ugo();

private:
    Ui::be4Ugo *ui;
    QStringList labels = {"file", "location"};
    void closeEvent(QCloseEvent*) override;

private slots:
    void cancel() {done(0);};
    void save() {done(1);};
    void leave() {done(-1);};
};

#endif // BE4UGO_H
