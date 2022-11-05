QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceuil.cpp \
    aide.cpp \
    ajout_med.cpp \
    ajout_pat.cpp \
    ajout_traite.cpp \
    etat.cpp \
    listeconsulter.cpp \
    listepatienttraiter.cpp \
    main.cpp \
    login.cpp \
    modif_med.cpp \
    modif_pat.cpp \
    modif_traite.cpp \
    recherchemed.cpp \
    recherchepat.cpp \
    recherchetraite.cpp \
    sup_med.cpp \
    sup_pat.cpp \
    sup_traite.cpp

HEADERS += \
    acceuil.h \
    aide.h \
    ajout_med.h \
    ajout_pat.h \
    ajout_traite.h \
    etat.h \
    listeconsulter.h \
    listepatienttraiter.h \
    login.h \
    modif_med.h \
    modif_pat.h \
    modif_traite.h \
    recherchemed.h \
    recherchepat.h \
    recherchetraite.h \
    sup_med.h \
    sup_pat.h \
    sup_traite.h

FORMS += \
    acceuil.ui \
    aide.ui \
    ajout_med.ui \
    ajout_pat.ui \
    ajout_traite.ui \
    etat.ui \
    listeconsulter.ui \
    listepatienttraiter.ui \
    login.ui \
    modif_med.ui \
    modif_pat.ui \
    modif_traite.ui \
    recherchemed.ui \
    recherchepat.ui \
    recherchetraite.ui \
    sup_med.ui \
    sup_pat.ui \
    sup_traite.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc
