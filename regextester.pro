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
    ui/pythonform.cpp \
    ui/aboutform.cpp

HEADERS  += \
    headers/python.h \
    ui/mainform.h \
    ui/pythonform.h \
    ui/aboutform.h

FORMS    += \
    ui/mainform.ui \
    ui/pythonform.ui \
    ui/aboutform.ui

win32:CONFIG(release, debug|release): LIBS += -LC:/Python27/libs/ -lpython27
else:unix:CONFIG(debug, debug|release): LIBS += -L/usr/lib/python2.7/config/ -lpython2.7

win32:INCLUDEPATH += C:/Python27/include/
win32:DEPENDPATH += C:/Python27/include/
unix:INCLUDEPATH += /usr/include/python2.7
unix:DEPENDPATH += /usr/include/python2.7

RESOURCES += \
    resources/resources.qrc
