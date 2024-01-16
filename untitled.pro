QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chambre.cpp \
    client.cpp \
    employe.cpp \
    gestionchambre.cpp \
    gestionemploye.cpp \
    main.cpp \
    mainwindow.cpp \
    pageaccueille.cpp \
    personne.cpp \
    reservation.cpp \
    reserver.cpp

HEADERS += \
    chambre.h \
    client.h \
    employe.h \
    gestionchambre.h \
    gestionemploye.h \
    mainwindow.h \
    pageaccueille.h \
    personne.h \
    reservation.h \
    reserver.h

FORMS += \
    gestionchambre.ui \
    gestionemploye.ui \
    mainwindow.ui \
    pageaccueille.ui \
    reservation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
