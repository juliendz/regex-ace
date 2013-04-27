#ifndef PYTHON_H
#define PYTHON_H

#include <Python.h>
#include <QString>
#include <QDebug>

class Python{

public:
    Python( );
    ~Python( );

    int error;
    void process_regex(QString regex, QString input , QString &findall, QString &split, QString &sub, QString &err_msg);

private:
    PyObject *module;
    PyObject *func;

};

#endif // PYTHON_H
