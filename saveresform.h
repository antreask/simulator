#ifndef SAVERESFORM_H
#define SAVERESFORM_H

#include <QWidget>

namespace Ui {
class saveResForm;
}

class saveResForm : public QWidget
{
    Q_OBJECT

public:
    explicit saveResForm(QWidget *parent = 0);
    ~saveResForm();

private:
    Ui::saveResForm *ui;
};

#endif // SAVERESFORM_H
