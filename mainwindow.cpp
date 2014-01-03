#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent){
    QWidget *mainW = new QWidget;
    excel = new ExcelMockWidget;
    vbox = new QVBoxLayout;
    button1 = new QPushButton("Select");

    setCentralWidget(mainW);

    defaultData();

    vbox->addWidget(excel);
    vbox->addWidget(button1);

    mainW->setLayout(vbox);

    connect(button1, SIGNAL(clicked()),this,SLOT(select()));
}

MainWindow::~MainWindow(){
}

void MainWindow::defaultData(){
    int sheets = 3;
    int columns = 3;
    int rows = 10;

    for (int i = 0; i < sheets; ++i) {
        QStringList headers;
        for (int z = 0; z < columns; ++z) {
            QString itemNum;
            itemNum.setNum(z+1);
            headers << QString("Item ").append(itemNum);
        }
        excel->setSheetProperties(rows,columns,headers);
        for (int r = 1; r <= rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                QVariant item(c);
                excel->addCell(r,c,item);
            }
        }
        QString num;
        num.setNum(i+1);
        excel->addSheet(i,QString("Tab ").append(num));
    }
}

void MainWindow::select(){
    excel->select(1,2);
}
