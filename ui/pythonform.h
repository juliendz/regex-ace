#ifndef PYTHONFORM_H
#define PYTHONFORM_H

#include <QWidget>
#include <QMessageBox>
#include "../headers/python.h"

namespace Ui {
class PythonForm;
}

class PythonForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit PythonForm(QWidget *parent = 0);
    ~PythonForm();
    
private:
    Ui::PythonForm *ui;
    Python* pyobj;

public slots:
    void process_regex( );
};

#endif // PYTHONFORM_H
