#include "../headers/python.h"

Python::Python( ){

    Py_Initialize( );
    PyObject* sysPath = PySys_GetObject((char*)"path");
    PyList_Append(sysPath, PyString_FromString("."));
    PyObject *module_name = PyUnicode_FromString("scripts.regex");
    this->module = PyImport_Import( module_name );
    Py_DECREF( module_name );

    if( this->module == NULL ){
        this->startup = 1;
        QMessageBox msgBox;
        msgBox.setText( "FATAL: Could not load python regex script" );
        msgBox.exec();
        return;
    }

    this->func = PyObject_GetAttrString( this->module, "process_regex" );

    if( !this->func && !PyCallable_Check( this->func ) ){
        this->startup = 1;
        QMessageBox msgBox;
        msgBox.setText( "FATAL: Could not import script function" );
        msgBox.exec();
        return;
    }
    this->startup = 0;
}


Python::~Python( ){

    Py_XDECREF( this->func );
    Py_DECREF( this->module );
    Py_Finalize();
}

void Python::process_regex(QString regex, QString input, QString replace, long *flags, QString &findall,
                QString &split, QString &sub, QString &err_msg ){

    PyObject *py_str_regex = PyString_FromString( regex.toStdString( ).c_str( ) );
    PyObject *py_str_input = PyString_FromString( input.toStdString( ).c_str( ) );
    PyObject *py_str_replace = PyString_FromString( replace.toStdString( ).c_str( ) );


    PyObject *args = PyTuple_New( 10 );
    if ( args == NULL ) {
        PyErr_SetString( PyExc_ReferenceError, "attempt to access a null- pointer" );
    }
    PyTuple_SetItem( args, 0, py_str_regex );
    PyTuple_SetItem( args, 1, py_str_input );
    PyTuple_SetItem( args, 2, py_str_replace );
    PyTuple_SetItem( args, 3, PyInt_FromLong( flags[0] ) );
    PyTuple_SetItem( args, 4, PyInt_FromLong( flags[1] ) );
    PyTuple_SetItem( args, 5, PyInt_FromLong( flags[2] ) );
    PyTuple_SetItem( args, 6, PyInt_FromLong( flags[3] ) );
    PyTuple_SetItem( args, 7, PyInt_FromLong( flags[4] ) );
    PyTuple_SetItem( args, 8, PyInt_FromLong( flags[5] ) );
    PyTuple_SetItem( args, 9, PyInt_FromLong( flags[6] ) );

    PyObject *retval = PyObject_CallObject( this->func, args );
    Py_DECREF( args );

    if( retval == NULL ){
        QMessageBox msgBox;
        msgBox.setText( "FATAL: Call to script function failed" );
        msgBox.exec();
        Py_DECREF( this->func );
        Py_DECREF( this->module );
        return;
    }

    //Get the error message (if any)
    PyObject *o_errmsg = PyTuple_GetItem( retval, 0 );
    char* cstr_o_errmsg = PyString_AsString( o_errmsg );

    //Get the regex results
    PyObject *o_findall = PyTuple_GetItem( retval, 1 );
    char* cstr_o_findall = PyString_AsString( o_findall );
    PyObject *o_split = PyTuple_GetItem( retval, 2 );
    char* cstr_o_split = PyString_AsString( o_split );
    PyObject *o_sub = PyTuple_GetItem( retval, 3 );
    char* cstr_o_sub = PyString_AsString( o_sub );

    Py_DECREF( retval );

    err_msg = QString::fromLocal8Bit( cstr_o_errmsg );
    findall = QString::fromLocal8Bit( cstr_o_findall );
    split = QString::fromLocal8Bit( cstr_o_split );
    sub = QString::fromLocal8Bit( cstr_o_sub );

}
