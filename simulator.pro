#-------------------------------------------------
#
# Project created by QtCreator 2017-07-05T10:26:58
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT += printsupport
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    codeeditor.cpp \
    parser.cpp \
    registerfile.cpp \
    help.cpp \
    saveresform.cpp \
    menu.cpp \
    printform.cpp \
    datamemory.cpp \
    instructionmemory.cpp \
    CPU/consumer.cpp \
    CPU/event.cpp \
    CPU/exe.cpp \
    CPU/ide.cpp \
    CPU/ife.cpp \
    CPU/mem.cpp \
    CPU/wb.cpp \
    simulator.cpp \
    global_info.cpp

HEADERS += \
        mainwindow.h \
    codeeditor.h \
    registerfile.h \
    saveresform.h \
    printform.h \
    datamemory.h \
    instructionmemory.h \
    CPU/consumer.h \
    CPU/event.h \
    CPU/exe.h \
    CPU/ide.h \
    CPU/ife.h \
    CPU/mem.h \
    CPU/wb.h \
    global_info.h

RESOURCES += \
    menu_icons/images.qrc

FORMS += \
    saveresform.ui \
    printform.ui
