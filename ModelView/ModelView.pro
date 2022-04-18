QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    dialogdelegate.cpp \
    editdialog.cpp \
    gosvo.cpp \
    linedeligate.cpp \
    main.cpp \
    mainwindow.cpp \
    mymodel.cpp

HEADERS += \
    dialogdelegate.h \
    editgosvodialog.h \
    gosvo.h \
    linedeligate.h \
    mainwindow.h \
    mymodel.h

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
