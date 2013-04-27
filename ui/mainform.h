#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include "pythonform.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
    
private:
    Ui::MainForm *ui;

public slots:
    void start_python_session( );
};

#endif // MAINFORM_H
