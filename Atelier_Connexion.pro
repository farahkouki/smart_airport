#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += core gui serialport
QT       += core gui sql  printsupport charts multimedia multimediawidgets
QT       += core gui sql core network multimedia multimediawidgets charts serialport printsupport widgets
TARGET = Atelier_Connexion
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    avion.cpp \
    camera.cpp \
    etudiant.cpp \
    exportexcelobject.cpp \
    gestion_de_vole.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    qrcode.cpp \
    stat.cpp \
    voleeee.cpp \
    voyageur.cpp

HEADERS += \
    avion.h \
    camera.h \
    etudiant.h \
    exportexcelobject.h \
    gestion_de_vole.h \
        mainwindow.h \
    connection.h \
    qrcode.h \
    stat.h \
    voleeee.h \
    voyageur.h

FORMS += \
        camera.ui \
        mainwindow.ui \
        stat_combo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    chart.qrc \
    map.qrc
