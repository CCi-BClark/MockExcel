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

int Wbook::getCurrentTab(){
    return ui->tabWidget->currentIndex();
}

QWidget* Wbook::getCurrentWidget(){
    return ui->tabWidget->currentWidget();
}

void Wbook::emitIndexChange(int index){
    emit changedIndex(index);
}

