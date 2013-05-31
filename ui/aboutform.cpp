#include "aboutform.h"
#include "ui_aboutform.h"

AboutForm::AboutForm(QWidget *parent) : QDialog(parent), ui(new Ui::AboutForm) {

    ui->setupUi(this);
    ui->label_version->setText( "1.0 beta" );

}

AboutForm::~AboutForm() {
    delete ui;
}
