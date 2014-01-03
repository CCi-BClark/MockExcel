#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <excelmockwidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void defaultData(void);

protected slots:
    void select(void);

private:
    ExcelMockWidget *excel;
    QVBoxLayout *vbox;
    QPushButton *button1;
};

#endif // MAINWINDOW_H
