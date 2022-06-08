QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomb.cpp \
    boss.cpp \
    boss_bomb.cpp \
    bullet.cpp \
    enemy.cpp \
    form.cpp \
    gameover.cpp \
    heroplane.cpp \
    main.cpp \
    mainscene.cpp \
    map.cpp \
    score.cpp

HEADERS += \
    bomb.h \
    boss.h \
    boss_bomb.h \
    bullet.h \
    config.h \
    enemy.h \
    form.h \
    gameover.h \
    heroplane.h \
    mainscene.h \
    map.h \
    score.h

FORMS += \
    form.ui \
    mainscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    res.qrc
