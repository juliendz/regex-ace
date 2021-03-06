#ifndef PYTHON_H
#define PYTHON_H

#include <Python.h>
#include <QString>
#include <QDebug>
#include <QMessageBox>


class Python{

public:
    Python( );
    ~Python( );

    int error;
    int startup;
    void process_regex(QString regex, QString input , QString replacement, long* flags,
                   QString &findall, QString &split, QString &sub, QString &err_msg );

private:
    PyObject *module;
    PyObject *func;

};

#endif // PYTHON_H
