#include "be4ugo.h"
#include "ui_be4ugo.h"
#include <QPushButton>

be4Ugo::be4Ugo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::be4Ugo)
{
    ui->setupUi(this);
    setWindowTitle(tr("Несохраненные документы"));
    table = new QTableWidget(0, 2, this);
    table->setHorizontalHeaderLabels(labels);
    QPushButton* cancel = new QPushButton("Закрыть", this);
    QPushButton* save = new QPushButton("Сохранить все", this);
    QPushButton* leave = new QPushButton("Не сохранять", this);
    ui->gridLayout->addWidget(table, 1, 1, 10, 2, Qt::AlignHCenter);
    ui->gridLayout->addWidget(cancel, 11, 1, Qt::AlignJustify);
    ui->gridLayout->addWidget(leave, 11, 3, Qt::AlignJustify);
    connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    ui->gridLayout->addWidget(save, 11, 2, Qt::AlignJustify);
    connect(save, SIGNAL(clicked()), this, SLOT(save()));
    connect(leave, SIGNAL(clicked()), this, SLOT(leave()));
}
void be4Ugo::fill_table(QTabWidget *data){
    for(int i=0; i < data->count(); i++){
        editor* current = static_cast<editor*>(data->widget(i));
        if (current->document()->isModified()){
            table->insertRow(i);
            table->setItem(i, 0, new QTableWidgetItem(data->tabText(i)));
            table->setItem(i, 1, new QTableWidgetItem(current->location));
        }
    }
}
be4Ugo::~be4Ugo()
{
    accept();
    delete ui;
}
void be4Ugo::closeEvent(QCloseEvent* event)
{
    event->ignore();
}

