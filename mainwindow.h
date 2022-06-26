#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QMainWindow>
#include <QTabWidget>
#include <QDockWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QStringListModel>
#include <QListView>
#include <QMessageBox>
#include <QSaveFile>
#include <QHBoxLayout>

#include "editor.h"
#include "be4ugo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent*) override;

private:
    Ui::MainWindow *ui;
    QFileSystemModel *filesysmodel;
    QTreeView *filesysview;
    QDockWidget *explorer;
    QDockWidget *open_browser;
    QTabWidget *open_tabs;
    QStringList open_list;
    QStringListModel* open_model;
    QListView* open_view;
    int cnt = 0;
    be4Ugo* dialog;

    void createfilemenu();
    void createeditmenu();
    void createviewmenu();
    void add_data(const QString &filename);
    void remove_data(const QString &filename);
    bool ifsave();
    bool saving(const QString &filename);
    
    

private slots:
   void close_tab(int index);
   void new_file();
   void open();
   void save();
   void saveas();
   void close();
   void saveall();
   void closeall();
   void clear();
   void cut();
   void copy();
   void paste();
   void selectall();
   void show_exp();
   void show_br();
   void choose_tab(QModelIndex index);
   void tabbydock(QModelIndex);
};
#endif // MAINWINDOW_H
