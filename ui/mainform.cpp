#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainForm) {

    ui->setupUi(this);

    //Connections
    connect( this->ui->btn_Python, SIGNAL( clicked( ) ), this, SLOT( start_python_session( ) ) );
    connect( this->ui->actionPython, SIGNAL( triggered( ) ), this, SLOT( start_python_session( ) ) );
    connect( this->ui->actionAbout_RegexAce, SIGNAL( triggered( ) ), this, SLOT( show_about( ) ) );
    connect( this->ui->actionExit, SIGNAL( triggered( ) ), this, SLOT( close( ) ) );
    connect( this->ui->tabWidget, SIGNAL( tabCloseRequested( int ) ) , this, SLOT( close_session_tab( int ) ) );
}

MainForm::~MainForm( ) {

    delete ui;
}

void MainForm::start_python_session( ) {

    PythonForm* form = new PythonForm( );

    int index = this->ui->tabWidget->addTab( form, QIcon( QString::fromUtf8( ":/new/regxace_resource/python.png" ) ), "Python" );
    this->ui->tabWidget->setCurrentIndex( index );

}

void MainForm::show_about( ){
    AboutForm *abtform = new AboutForm( );
    abtform->setModal( true );
    abtform->show( );
}

void MainForm::close_session_tab( int index ){

    if( index != 0 ){
        this->ui->tabWidget->removeTab( index );
    }
}
