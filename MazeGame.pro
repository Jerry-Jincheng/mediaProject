#-------------------------------------------------
#
# Project created by QtCreator 2018-11-24T14:57:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MazeGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    healthpack.cpp \
    environment.cpp \
    penemyview.cpp \
    xenemyview.cpp \
    protagonistview.cpp \
    environmentview.cpp \
    healthpackview.cpp \
    controller.cpp \
    consumable.cpp \
    enemyview.cpp

HEADERS += \
        mainwindow.h \
    healthpack.h \
    environment.h \
    consumable.h \
    penemyview.h \
    xenemyview.h \
    protagonistview.h \
    environmentview.h \
    healthpackview.h \
    controller.h \
    enemyview.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/world_v2/release/ -lworld
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/world_v2/debug/ -lworld
else:unix: LIBS += -L$$PWD/world_v2/ -lworld

INCLUDEPATH += $$PWD/world_v2
DEPENDPATH += $$PWD/world_v2

RESOURCES += \
    src.qrc
