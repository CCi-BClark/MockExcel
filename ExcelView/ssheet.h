#ifndef SSHEET_H
#define SSHEET_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class Ssheet;
}

class Ssheet : public QWidget{
    Q_OBJECT
public:
    explicit Ssheet(QWidget *parent = 0);
    ~Ssheet();
    void setSheetTitle(QString title);
    void setSheetRowSpan(int n);
    void setSheetColumnSpan(int n);
    void setSheetHeaders(QStringList headers);
    void setCell(int row, int column, QVariant cell);

    void selectRow(int row);
    void selectCell(int row, int column);
private:
    Ui::Ssheet *ui;
};

#endif // SSHEET_H
