#ifndef PRINTFORM_H
#define PRINTFORM_H

#include <QWidget>

namespace Ui {
class PrintForm;
}

class PrintForm : public QWidget
{
    Q_OBJECT

public:
    explicit PrintForm(QWidget *parent = 0);
    ~PrintForm();

private:
    Ui::PrintForm *ui;
};

#endif // PRINTFORM_H
