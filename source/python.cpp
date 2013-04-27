#include "../headers/python.h"

Python::Python( ){

    //Py_SetPythonHome( "C:\\Python27" );
    Py_Initialize( );
    PyObject *module_name = PyUnicode_FromString( "scripts.regex" );
    this->module = PyImport_Import( module_name );
    Py_DECREF( module_name );

    if( this->module == NULL ){
        //TODO:Error handling
    }

    this->func = PyObject_GetAttrString( this->module, "process_regex" );

    if( !this->func && !PyCallable_Check( this->func ) ){
        //TODO:Error handling
    }
}


Python::~Python( ){

    Py_XDECREF( this->func );
    Py_DECREF( this->module );
    Py_Finalize();
}

void Python::process_regex( QString regex, QString input, QString &findall, QString &split, QString &sub, QString &err_msg ){

    PyObject *py_str_regex = PyString_FromString( regex.toStdString( ).c_str( ) );
    PyObject *py_str_input = PyString_FromString( input.toStdString( ).c_str( ) );


    PyObject *args = PyTuple_New( 2 );
    if ( args == NULL ) {
        PyErr_SetString( PyExc_ReferenceError, "attempt to access a null- pointer" );
    }
    PyTuple_SetItem( args, 0, py_str_regex );
    PyTuple_SetItem( args, 1, py_str_input );

    PyObject *retval = PyObject_CallObject( this->func, args );
    Py_DECREF( args );

    if( retval == NULL ){
        //TODO:Error handling
        Py_DECREF( this->func );
        Py_DECREF( this->module );
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
