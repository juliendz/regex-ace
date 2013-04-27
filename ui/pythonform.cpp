#include "pythonform.h"
#include "ui_pythonform.h"

PythonForm::PythonForm(QWidget *parent) : QWidget(parent), ui(new Ui::PythonForm) {

    ui->setupUi(this);

    //Create the python regex object
    this->pyobj = new Python;

    //connections
    connect( this->ui->txtBox_regexp, SIGNAL( textChanged( ) ), this, SLOT( process_regex( ) ) );
    connect( this->ui->btn_test, SIGNAL( clicked( ) ), this, SLOT( process_regex( ) ) );
}

PythonForm::~PythonForm() {

    delete ui;
}

void PythonForm::process_regex( ){

    QString err_msg, findall, split, sub;
    QString regex = this->ui->txtBox_regexp->toPlainText( );
    QString input = this->ui->txtBox_input->toPlainText( );

    //Update the re.complile() label
    QString str_compile = "re.compile( '" + regex + "' ) ";
    this->ui->label_py_compile->setText( str_compile );

    //Update the re.findall() label
    pyobj->process_regex( regex, input, findall, split, sub, err_msg );
    this->ui->label_py_err_msg->setText( err_msg );
    this->ui->txtBox_py_findall->setText( findall );
    this->ui->txtBox_py_split->setText( split );
    this->ui->txtBox_py_sub->setText( sub );

}