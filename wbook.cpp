#include "wbook.h"
#include "ui_wbook.h"

Wbook::Wbook(QWidget *parent) : QWidget(parent), ui(new Ui::Wbook){
    ui->setupUi(this);
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(emitIndexChange(int)));
}

Wbook::~Wbook(){
    delete ui;
}

void Wbook::createTab(int index, QString title, Ssheet *worksheet){
    ui->tabWidget->insertTab(index, worksheet, title);
}

void Wbook::selectTab(int tab){
    // 0 for no selection and 1 -> for created tabs.
    ui->tabWidget->setCurrentIndex(tab);
}

void Wbook::selectCell(int row, int column){
    ui->tabWidget->currentWidget()->childAt(row+1,column+1)->setFocus();
}

void Wbook::emitIndexChange(int index){
    emit changedIndex(index);
}

