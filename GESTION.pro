QT       += core gui serialport
QT += printsupport
QT       += core gui charts
QT += network
QT       += widgets
QT      += multimedia
QT       += core gui network printsupport \



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = DateManager
TARGET = QSystemTrayIcon



CONFIG += c++11
QT+=sql

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
    arduino.cpp \
    arduino1.cpp \
    arduino2.cpp \
    authentification.cpp \
    client.cpp \
    conx.cpp \
    event.cpp \
    gestion_salle.cpp \
    gestionreservation.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp \
    mainwindow3.cpp \
    mainwindow4.cpp \
    personnels.cpp \
    popup.cpp \
    qcustomplot.cpp \
    reservation.cpp \
    salle.cpp \
    smtp.cpp

HEADERS += \
    arduino.h \
    arduino1.h \
    arduino2.h \
    authentification.h \
    client.h \
    conx.h \
    event.h \
    gestion_salle.h \
    gestionreservation.h \
    login.h \
    mainwindow.h \
    mainwindow2.h \
    mainwindow3.h \
    mainwindow4.h \
    personnels.h \
    popup.h \
    qcustomplot.h \
    reservation.h \
    salle.h \
    smtp.h

FORMS += \
    gestion_salle.ui \
    gestionreservation.ui \
    login.ui \
    mainwindow.ui \
    mainwindow2.ui \
    mainwindow3.ui \
    mainwindow4.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
