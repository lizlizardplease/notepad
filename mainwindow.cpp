#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>

void MainWindow::createfilemenu(){
    QPixmap newpix("../notepad/resources/new.png");
    QPixmap openpix("../notepad/resources/open.png");
    QPixmap savepix("../notepad/resources/save.png");
    QPixmap saveallpix("../notepad/resources/saveall.png");

    QToolBar *toolbar = addToolBar("Tool Bar");

    QAction* newfile = new QAction(newpix, "Новый файл", this);
    newfile->setText("&Новый файл");
    newfile->setShortcut(QKeySequence("CTRL+N"));
    newfile->setStatusTip("Создать новый файл");
    newfile->setWhatsThis("Создать новый файл");
    newfile->setToolTip("Новый файл");
    toolbar->addAction(newfile);
    connect(newfile, SIGNAL(triggered()), SLOT(new_file()));

    QAction* openfile = new QAction(openpix, "Открыть файл", this);
    openfile->setText("&Открыть файл");
    openfile->setShortcut(QKeySequence("CTRL+O"));
    openfile->setStatusTip("Открыть существующий файл");
    openfile->setWhatsThis("Открыть существующий файл");
    openfile->setToolTip("Открыть файл");
    connect(openfile, SIGNAL(triggered()), SLOT(open()));
    toolbar->addAction(openfile);

    QAction* savefile = new QAction(savepix, "Сохранить файл", this);
    savefile->setText("&Сохранить файл");
    savefile->setShortcut(QKeySequence("CTRL+S"));
    savefile->setStatusTip("Сохранить изменения в файле");
    savefile->setWhatsThis("Сохранить изменения в файле");
    savefile->setToolTip("Сохранить файл");
    connect(savefile, SIGNAL(triggered()), SLOT(save()));
    toolbar->addAction(savefile);

    QAction* savefileas = new QAction("Сохранить файл как", this);
    savefileas->setText("&Сохранить файл как");
    savefileas->setStatusTip("Сохранить файл как...");
    savefileas->setWhatsThis("Сохранить файл как...");
    savefileas->setToolTip("Сохранить файл как...");
    connect(savefileas, SIGNAL(triggered()), SLOT(saveas()));

    QAction* saveall = new QAction(saveallpix, "Сохранить все", this);
    saveall->setText("&Сохранить все");
    saveall->setShortcut(QKeySequence("CTRL+SHIFT+S"));
    saveall->setStatusTip("Сохранить изменения во всех файлах");
    saveall->setWhatsThis("Сохранить изменения во всех файлах");
    saveall->setToolTip("Сохранить все изменения");
    connect(saveall, SIGNAL(triggered()), SLOT(saveall()));
    toolbar->addAction(saveall);

    QAction* closefile = new QAction("Закрыть файл", this);
    closefile->setText("&Закрыть");
    closefile->setShortcut(QKeySequence("CTRL+W"));
    closefile->setStatusTip("Закрыть текущий файл");
    closefile->setWhatsThis("Закрыть текущий файл");
    closefile->setToolTip("Закрыть файл");
    connect(closefile, SIGNAL(triggered()), SLOT(close()));

    QAction* closeall = new QAction("Закрыть все файлы", this);
    closeall->setText("&Закрыть все");
    closeall->setShortcut(QKeySequence("CTRL+SHIFT+W"));
    closeall->setStatusTip("Закрыть все файлы");
    closeall->setWhatsThis("Закрыть все файлы");
    closeall->setToolTip("Закрыть все файлы");
    connect(closeall, SIGNAL(triggered()), SLOT(closeall()));

    QMenu* menu = new QMenu("&Файл", this);
    menu->addAction(newfile);
    menu->addAction(openfile);
    menu->addAction(savefile);
    menu->addAction(savefileas);
    menu->addAction(saveall);
    menu->addAction(closefile);
    menu->addAction(closeall);
    menu->addAction("&Выйти", qApp, SLOT(closeAllWindows()), QKeySequence("CTRL+Q"));
    menu->addSeparator();
    menuBar()->addMenu(menu);
    menuBar()->addSeparator();

    toolbar->setOrientation(Qt::Vertical);
    toolbar->addSeparator();
    ui->horizontalLayout->addWidget(toolbar);
}
void MainWindow::createeditmenu(){
    QAction* cut = new QAction("Вырезать", this);
    cut->setText("&Вырезать");
    cut->setShortcut(QKeySequence("CTRL+X"));
    cut->setStatusTip("Вырезать");
    cut->setWhatsThis("Вырезать");
    cut->setToolTip  ("Вырезать текст");
    connect(cut, SIGNAL(triggered()), SLOT(cut()));

    QAction* copy = new QAction("Копировать", this);
    copy->setText("&Копировать");
    copy->setShortcut(QKeySequence("CTRL+C"));
    copy->setStatusTip("Копировать");
    copy->setWhatsThis("Копировать");
    copy->setToolTip  ("Копировать текст");
    connect(copy, SIGNAL(triggered()), SLOT(copy()));

    QAction* paste = new QAction("Вставить текст", this);
    paste->setText("&Вставить");
    paste->setShortcut(QKeySequence("CTRL+V"));
    paste->setStatusTip("Вставить");
    paste->setWhatsThis("Вставить"         );
    paste->setToolTip  ("Вставить");
    connect(paste, SIGNAL(triggered()), SLOT(paste()));

    QAction* clear = new QAction("Очистить", this);
    clear->setText("&Очистить");
    clear->setShortcut(QKeySequence("CTRL+DEL"));
    clear->setStatusTip("Очистить документ");
    clear->setWhatsThis("Очистить документ");
    clear->setToolTip  ("Очистить документ");
    connect(clear, SIGNAL(triggered()), SLOT(clear()));

    QAction* selectall = new QAction("Select All", this);
    selectall->setText("&Select all");
    selectall->setShortcut(QKeySequence("CTRL+A"));
    selectall->setStatusTip("Select the whole text");
    selectall->setWhatsThis("Select the whole text");
    selectall->setToolTip  ("Select the whole text");
    connect(selectall, SIGNAL(triggered()), SLOT(selectall()));

    QMenu* edit = new QMenu("&Правка", this);
    edit->addAction(cut);
    edit->addAction(copy);
    edit->addAction(paste);
    edit->addAction(clear);
    edit->addAction(selectall);
    menuBar()->addMenu(edit);
    menuBar()->addSeparator();
}
void MainWindow::createviewmenu(){
    QAction* sh_exp = new QAction("Показать проводник", this);
    sh_exp->setText("&Показать проводник");
    sh_exp->setStatusTip("Показать проводник");
    sh_exp->setWhatsThis("Показать проводник");
    connect(sh_exp, SIGNAL(triggered()), SLOT(show_exp()));

    QAction* sh_br = new QAction("Открытые документы", this);
    sh_br->setText("&Показать обозреватель открытых документов");
    sh_br->setStatusTip("Показать обозреватель открытых документов");
    sh_br->setWhatsThis("Показать обозреватель открытых документов");
    connect(sh_br, SIGNAL(triggered()), SLOT(show_br()));

    QMenu* view = new QMenu("&Вид", this);
    view->addAction(sh_exp);
    view->addAction(sh_br);
    menuBar()->addMenu(view);
    menuBar()->addSeparator();
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createfilemenu();
    createeditmenu();
    createviewmenu();
    filesysmodel = new QFileSystemModel(this);
    filesysmodel->setRootPath(QDir::homePath());
    filesysview = new QTreeView(this);
    filesysview->setModel(filesysmodel);
    connect(filesysview, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(tabbydock(QModelIndex)));
    explorer = new QDockWidget("File explorer", this);
    explorer->setWidget(filesysview);
    explorer->setFeatures(QDockWidget::DockWidgetClosable);
    explorer->hide();
    addDockWidget(Qt::RightDockWidgetArea, explorer);

    open_model = new QStringListModel(open_list, this);
    open_view = new QListView(this);
    open_view->setModel(open_model);
    open_view->setEditTriggers(QListView::NoEditTriggers);
    connect(open_view, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(choose_tab(QModelIndex)));

    open_browser = new QDockWidget("Opened files list", this);
    open_browser->setWidget(open_view);
    open_browser->setFeatures(QDockWidget::DockWidgetClosable);
    open_browser->hide();
    addDockWidget(Qt::LeftDockWidgetArea, open_browser);


    open_tabs = new QTabWidget;
    open_tabs->setTabShape(QTabWidget::Triangular);
    open_tabs->setTabPosition(QTabWidget::North);
    open_tabs->setTabsClosable(true);
    open_tabs->setForegroundRole(QPalette::Light);
    connect(open_tabs, SIGNAL(tabCloseRequested(int)),this, SLOT(close_tab(int)));
    ui->horizontalLayout->addWidget(open_tabs);
    statusBar()->showMessage("Ready", 3000);
}



MainWindow::~MainWindow()
{
        delete ui;
}

void MainWindow::new_file(){
    editor *pageWidget_0 = new editor;
    pageWidget_0->setBackgroundRole(QPalette::Base);
    cnt++;
    QString name = "document " + QString::number(cnt);
    open_list << name;
    open_tabs->addTab(pageWidget_0, name);
    add_data(name);
}

void MainWindow::open(){
    QString strfilter;

    
    QString path = QFileDialog::getOpenFileName(this, "Выберете файл", QDir::homePath(), "All files (*.*)", &strfilter);
    QFile* file;
    if(!path.isEmpty())
        file = new QFile(path);
    else
        return;
    if(!file->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("Не удалось открыть файл");
        msgBox.exec();
    }
    else{
        strfilter = path.section(".", 1, 1);
        editor *another = new editor(this, strfilter);
        another->setBackgroundRole(QPalette::Base);
        cnt++;
        another->location = path;
        path = path.section("/", -1, -1);
        open_list << path;
        open_tabs->addTab(another, path);
        another->setPlainText(file->readAll());
        add_data(path);
    }
}
void MainWindow::remove_data(const QString &filename)
{
    auto index = open_model->stringList().indexOf(filename);
    if(index != -1)
        open_model->removeRow(index);
}

void MainWindow::add_data(const QString &filename)
{
    int amnt = open_model->rowCount();
    auto index = open_model->stringList().indexOf(filename);
    if (index == -1) {
        open_model->insertRow(amnt);
        QModelIndex model_idx = open_model->index(amnt, 0);
        open_model->setData(model_idx, filename);
        open_view->setCurrentIndex(model_idx);
    }
    else {
        QModelIndex model_idx = open_model->index(index, 0);
        open_view->setCurrentIndex(model_idx);
    }
}

void MainWindow::close_tab(int index){
    if(ifsave())
        save();
    remove_data(open_tabs->tabText(index));
    open_tabs->removeTab(index);
    open_list.removeAt(index);
}

void MainWindow::save(){
    saving(open_tabs->tabText(open_tabs->currentIndex()));
}
bool MainWindow::saving(const QString &filename){
    QString error;
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    QSaveFile file(filename);
    if (file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&file);
        editor* cur_text = static_cast<editor*>(open_tabs->currentWidget());
        out << cur_text->toPlainText();
        cur_text->document()->setModified(false);

        if(!file.commit())
                error = tr("Cannot write file");
        }
    else
            error = tr("Cannot open file for writing");
        QGuiApplication::restoreOverrideCursor();
        if (!error.isEmpty()) {
            QMessageBox::warning(this, tr("Some troubles"), error);
            return false;
        }

        statusBar()->showMessage(tr("File saved"), 2000);
        return true;
}
void MainWindow::saveas(){
    QString filename = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), QDir::homePath());
    saving(filename);
    static_cast<editor*>(open_tabs->currentWidget())->location = filename;
    filename = filename.section("/", -1, -1);
    open_list.replace(open_tabs->currentIndex(), filename);
    open_tabs->setTabText(open_tabs->currentIndex(), filename);
    add_data(filename);
}
bool MainWindow::ifsave(){
    QMessageBox::StandardButton reply = QMessageBox::question(this, tr("Сохранение"), tr("Сохранить файл?"),
    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
        return true;
    else
        return false;
}
void MainWindow::close(){
    close_tab(open_tabs->currentIndex());
}
void MainWindow::closeall(){
    for(int i = 0; i < open_model->rowCount(); i++){
        close_tab(0);
    }
}
void MainWindow::saveall(){
    for(int i = 0; i < open_model->rowCount(); i++){
        saving(open_tabs->tabText(i));
    }
}
void MainWindow::clear(){
    static_cast<editor*>(open_tabs->currentWidget())->clear();
}
void MainWindow::cut(){
    static_cast<editor*>(open_tabs->currentWidget())->cut();
}
void MainWindow::copy(){
    static_cast<editor*>(open_tabs->currentWidget())->copy();
}
void MainWindow::paste(){
    static_cast<editor*>(open_tabs->currentWidget())->paste();
}
void MainWindow::selectall(){
    static_cast<editor*>(open_tabs->currentWidget())->selectAll();
}
void MainWindow::show_exp(){
    explorer->show();
}
void MainWindow::show_br(){
    open_browser->show();
}
void MainWindow::choose_tab(QModelIndex index){
    open_tabs->setCurrentIndex(index.row());
}
void MainWindow::tabbydock(QModelIndex index){
    QString filename = filesysmodel->fileInfo(index).absoluteFilePath();
        int tab_ind = open_list.indexOf(filename);
        if (tab_ind != -1){
            open_tabs->setCurrentIndex(tab_ind);
            auto list_idx = open_model->stringList().indexOf(filename);
            QModelIndex model_idx = open_model->index(list_idx, 0);
            open_view->setCurrentIndex(model_idx);
        }

        else {
            QFile file(filename);
            if (file.open(QIODevice::ReadOnly | QFile::Text)) {
                QFileInfo fileInfo(file);
                QString strfilter = fileInfo.suffix();
                editor *another = new editor(this, strfilter);
                another->setBackgroundRole(QPalette::Base);
                cnt++;
                QString path = fileInfo.path();
                path = path.section("/", -1, -1);
                open_list << path;
                open_tabs->addTab(another, path);
                another->setPlainText(file.readAll());
                add_data(path);
            }
        }

}
void MainWindow::closeEvent(QCloseEvent* event)
{
    dialog = new be4Ugo(this);
    dialog->fill_table(open_tabs);
    int res = dialog->exec();
    if (res == 0) event->ignore();
    else {
        if (res == 1)
            saveall();
        event->accept();
    }
}
