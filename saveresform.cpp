#include "saveresform.h"
#include "ui_saveresform.h"

saveResForm::saveResForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::saveResForm)
{
    ui->setupUi(this);
}

saveResForm::~saveResForm()
{
    delete ui;
}
