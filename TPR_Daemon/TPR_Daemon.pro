! include( $$(TPR_SRC)/common.pri ) {
    error( Couldn't find the common.pri file! )
}

CONFIG += console
QT -= gui core sql
TARGET = TPR_Daemon
TEMPLATE = app
SOURCES += TPR_Daemon_JobInfo.cpp \
		   TPR_Daemon_Watcher.cpp \
           main.cpp
HEADERS += TPR_Daemon_ThreadInfo.h \
		TPR_Daemon_JobInfo.h \
		TPR_Daemon_Watcher.h

Debug:LIBS += -L$$(TPR_SRC)/tmp/Debug -lTPR_Bank
Release:LIBS += -L$$(TPR_SRC)/tmp/Release -lTPR_Bank
