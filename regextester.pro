#-------------------------------------------------
#
# Project created by QtCreator 2013-04-26T21:34:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = regextester
TEMPLATE = app


SOURCES +=  source/main.cpp \
    source/python.cpp \
    ui/mainform.cpp \
    ui/pythonform.cpp

HEADERS  += \
    headers/python.h \
    ui/mainform.h \
    ui/pythonform.h

FORMS    += \
    ui/mainform.ui \
    ui/pythonform.ui

win32:CONFIG(release, debug|release): LIBS += -LC:/Python27/libs/ -lpython27
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Python27/libs/ -lpython27

#INCLUDEPATH += $$PWD/C:/Python27/include/
#DEPENDPATH += $$PWD/C:/Python27/include/
INCLUDEPATH += C:/Python27/include/
DEPENDPATH += C:/Python27/include/
