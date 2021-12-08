QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contact.cpp \
    database.cpp \
    email.cpp \
    gestioncontact.cpp \
    gestioninteraction.cpp \
    gestiontodo.cpp \
    interaction.cpp \
    main.cpp \
    mainwindow.cpp \
    todo.cpp

HEADERS += \
    contact.h \
    database.h \
    email.h \
    gestioncontact.h \
    gestioninteraction.h \
    gestiontodo.h \
    interaction.h \
    mainwindow.h \
    todo.h

INCLUDEPATH += "/home/bah/Bureau/L3/CDAA/Projet/Projet/Files"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
