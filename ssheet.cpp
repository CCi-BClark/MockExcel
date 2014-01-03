#include "ssheet.h"
#include "ui_ssheet.h"
#include <QItemSelectionModel>
Ssheet::Ssheet(QWidget *parent) : QWidget(parent), ui(new Ui::Ssheet){
    ui->setupUi(this);

    ui->table->verticalHeader()->setVisible(false);

    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->table->setStyleSheet("QTableWidget {selection-background-color: black; selection-color: white}");

    ui->table->setShowGrid(false);
}

Ssheet::~Ssheet(){
    delete ui;
}

void Ssheet::setSheetTitle(QString title){
    ui->table->setObjectName(title);
}

void Ssheet::setSheetRowSpan(int n){
    ui->table->setRowCount(n);
}

void Ssheet::setSheetColumnSpan(int n){
    ui->table->setColumnCount(n);
}

void Ssheet::setSheetHeaders(QStringList headers){
    ui->table->setHorizontalHeaderLabels(headers);
}

void Ssheet::setCell(int row, int column, QVariant cell){
    QTableWidgetItem *input = new QTableWidgetItem;
    input->setData(0,cell);
    ui->table->setItem(row-1,column,input);
}

void Ssheet::selectCell(int row, int column){
    ui->table->setCurrentCell(row,column);
}

