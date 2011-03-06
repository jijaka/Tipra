
! include( $$(TPR_SRC)/common.pri ) {
    error( Couldn't find the common.pri file! )
}

TARGET = TPR_Bank
TEMPLATE = lib
DEFINES += TPR_BANK_LIBRARY
SOURCES += TPR_Bank_Dao.cpp
HEADERS += TPR_Bank_global.h \
    TPR_Bank_Dao.h
