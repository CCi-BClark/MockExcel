#ifndef WBOOK_H
#define WBOOK_H

#include <QWidget>
#include <QTabWidget>
#include <ExcelView/ssheet.h>

namespace Ui {
class Wbook;
}

class Wbook : public QWidget{
    Q_OBJECT

public:
    explicit Wbook(QWidget *parent = 0);
    ~Wbook();    
    void createTab(int index, QString title, Ssheet *worksheet);
    void selectTab(int tab);
    void selectCell(int row, int column);
    int getCurrentTab(void);
    QWidget *getCurrentWidget(void);
signals:
    void changedIndex(int);
public slots:
    void emitIndexChange(int index);

protected:

private:
    Ui::Wbook *ui;
};

#endif // WBOOK_H
