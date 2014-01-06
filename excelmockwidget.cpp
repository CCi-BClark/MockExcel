#include "excelmockwidget.h"

ExcelMockWidget::ExcelMockWidget(QWidget *parent) : QWidget(parent) {
    book = new Wbook;
    QVBoxLayout *container;
    container = new QVBoxLayout;
    container->addWidget(book);
    setLayout(container);
    connect(book,SIGNAL(changedIndex(int)),this,SLOT(emitIndexChange(int)));
}

ExcelMockWidget::~ExcelMockWidget(){

}

void ExcelMockWidget::addCell(int row, int column, QVariant cell){
    sheet->setCell(row,column,cell);
}

void ExcelMockWidget::addSheet(int index, QString title){
    Ssheet *newSheet(sheet);
    book->createTab(index, title, newSheet);
    //book->createTab(index, title, sheet);
}

void ExcelMockWidget::setSheetProperties(int rows, int columns, QStringList headers){
    sheet = new Ssheet;
    sheet->setSheetColumnSpan(columns);
    sheet->setSheetRowSpan(rows);
    sheet->setSheetHeaders(headers);
}

void ExcelMockWidget::emitIndexChange(int index){
    emit indexChanged(index);
}

void ExcelMockWidget::select(int row, int column){
    sheet = static_cast<Ssheet*>(book->getCurrentWidget());
    sheet->selectCell(row, column);
    //sheet->selectCell(row,column);
    //book->selectCell(row, column);
}
