#include "excelview.h"

ExcelView::ExcelView(QWidget *parent) : QWidget(parent){
    book = new Wbook;
    QVBoxLayout *container;
    container = new QVBoxLayout;
    container->addWidget(book);
    setLayout(container);
    connect(book,SIGNAL(changedIndex(int)),this,SLOT(emitIndexChange(int)));}

ExcelView::~ExcelView()
{

}

void ExcelView::addCell(int row, int column, QVariant cell){
    sheet->setCell(row,column,cell);}

void ExcelView::addSheet(int index, QString title){
    Ssheet *newSheet(sheet);
    book->createTab(index, title, newSheet);
}

void ExcelView::setSheetProperties(int rows, int columns, QStringList headers){
    sheet = new Ssheet;
    sheet->setSheetColumnSpan(columns);
    sheet->setSheetRowSpan(rows);
    sheet->setSheetHeaders(headers);
}

void ExcelView::emitIndexChange(int index){
    emit indexChanged(index);
}

void ExcelView::select(int row, int column){
    sheet = static_cast<Ssheet*>(book->getCurrentWidget());
    sheet->selectCell(row, column);
}
