QT       += core gui
#QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
RC_ICONS = log.ico

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appinfo.cpp \
    form.cpp \
    main.cpp \
   # mainWindow.cpp \
    w0.cpp \
    w1.cpp \
    w2.cpp \
    w3.cpp \
    w4.cpp \
    w5_1.cpp \
    w6.cpp \
    w7.cpp

HEADERS += \
    appinfo.h \
    form.h \
    funcs.h \
    header.h \
   # mainWindow.h \
    w0.h \
    w1.h \
    w2.h \
    w3.h \
    w4.h \
    w5_1.h \
    w6.h \
    w7.h

FORMS += \
    appinfo.ui \
    form.ui \
    #mainWindow.ui \
    w0.ui \
    w1.ui \
    w2.ui \
    w3.ui \
    w4.ui \
    w5_1.ui \
    w6.ui \
    w7.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    allicons.qrc
