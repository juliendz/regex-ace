#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm) {

    ui->setupUi(this);

    //Connections
    connect( this->ui->btn_Python, SIGNAL( clicked( ) ), this, SLOT( start_python_session( ) ) );
}

MainForm::~MainForm( ) {

    delete ui;
}

void MainForm::start_python_session( ) {

    PythonForm* form = new PythonForm( );

    this->ui->tabWidget->addTab( form, "Python" );

}
