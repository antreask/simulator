#include "printform.h"
#include "ui_printform.h"

PrintForm::PrintForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintForm)
{
    ui->setupUi(this);

}

PrintForm::~PrintForm()
{
    delete ui;
}

