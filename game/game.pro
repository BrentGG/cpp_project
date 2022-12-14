QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvas.cpp \
    canvasdrawing.cpp \
    character.cpp \
    enemy.cpp \
    game.cpp \
    gamecontroller.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    playerdrawing.cpp \
    vampire.cpp \
    vampiredrawing.cpp \
    zombie.cpp \
    zombiedrawing.cpp

HEADERS += \
    canvas.h \
    canvasdrawing.h \
    character.h \
    coords.h \
    enemy.h \
    game.h \
    gamecontroller.h \
    mainwindow.h \
    player.h \
    playerdrawing.h \
    vampire.h \
    vampiredrawing.h \
    zombie.h \
    zombiedrawing.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
