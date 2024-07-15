QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    accumulator.cpp \
    bankuser.cpp \
    creatwindow.cpp \
    creditaccount.cpp \
    date.cpp \
    main.cpp \
    bank.cpp \
    opwindow.cpp \
    savingsaccount.cpp \
    swindow.cpp \
    userwindow.cpp

HEADERS += \
    account.h \
    accumulator.h \
    bank.h \
    bankuser.h \
    creatwindow.h \
    creditaccount.h \
    date.h \
    opwindow.h \
    savingsaccount.h \
    swindow.h \
    userwindow.h

FORMS += \
    bank.ui \
    creatwindow.ui \
    opwindow.ui \
    swindow.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
