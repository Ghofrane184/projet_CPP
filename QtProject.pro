QT       += core gui


QT       += core gui charts
QT += sql
QT += printsupport
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    client.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp.cpp

HEADERS += \
    client.h \
    connection.h \
    mainwindow.h \
    smtp.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons/icons.qrc

DISTFILES += \
    icons/265458502_337318288223536_8259043550372779265_n - Copie (2).png \
    icons/265458502_337318288223536_8259043550372779265_n - Copie - Copie.png \
    icons/265458502_337318288223536_8259043550372779265_n - Copie - Copie.png \
    icons/276151405_557655078742571_5649066659165148470_n - Copie (2).png \
    icons/276151405_557655078742571_5649066659165148470_n - Copie - Copie.png \
    icons/276151405_557655078742571_5649066659165148470_n - Copie - Copie.png \
    icons/276151405_557655078742571_5649066659165148470_n - Copie.png \
    icons/310524418_456620376567891_642121377332873748_n - Copie - Copie.png \
    icons/310524418_456620376567891_642121377332873748_n - Copie.png \
    icons/311104868_663708175327587_5478593492150431971_n - Copie (2).png \
    icons/311104868_663708175327587_5478593492150431971_n - Copie - Copie - Copie.png \
    icons/311104868_663708175327587_5478593492150431971_n - Copie - Copie.png \
    icons/311104868_663708175327587_5478593492150431971_n - Copie.png \
    icons/311188138_1295843987843557_4304256899111124032_n - Copie (2).png \
    icons/311188138_1295843987843557_4304256899111124032_n - Copie - Copie - Copie.png \
    icons/311188138_1295843987843557_4304256899111124032_n - Copie - Copie.png \
    icons/311188138_1295843987843557_4304256899111124032_n - Copie.png \
    icons/312358535_4067145573509693_4013136575027005301_n - Copie.png \
    icons/312429297_445290024180468_1769385482268134196_n - Copie.png \
    icons/312463110_1811430065693998_8757293533650662283_n - Copie.png \
    icons/312472353_837619854094775_1062030169993636992_n - Copie.png \
    icons/312497913_2096893403845881_6063762091723374321_n - Copie - Copie.png \
    icons/312497913_2096893403845881_6063762091723374321_n - Copie.png \
    icons/312510383_573432251248689_7847590218838387651_n - Copie - Copie.png \
    icons/312539433_1349318232138746_7552805372088943474_n - Copie - Copie.png \
    icons/312544411_410312394595842_8065130271283007591_n - Copie.png \
    icons/312547414_684136896193775_7290192132447597307_n - Copie - Copie.png \
    icons/312551831_410074381158418_5360117734813686178_n - Copie.png \
    icons/312559051_809138917002087_8865658151791835692_n - Copie.png \
    icons/312572299_637385034606265_470310568338821020_n - Copie.png \
    icons/312573638_1238832036682755_7210378239637461400_n - Copie.png \
    icons/312612218_3536954703228538_4660223888396469412_n - Copie.png
