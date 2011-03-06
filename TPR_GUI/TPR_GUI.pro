
! include( $$(TPR_SRC)/common.pri ) {
    error( Couldn't find the common.pri file! )
}
TARGET = TPR_GUI
TEMPLATE = app
SOURCES += TPR_GUI_App.cpp \
    TPR_GUI_ReportPanel.cpp \
    TPR_GUI_PreferencesTab.cpp
HEADERS += TPR_GUI_App.h \
    TPR_GUI_ReportPanel.h \
    TPR_GUI_PreferencesTab.h \
    TPR_GUI_common.h
	
Debug:LIBS += -L$$(TPR_SRC)/tmp/Debug -lTPR_Bank
Release:LIBS += -L$$(TPR_SRC)/tmp/Release -lTPR_Bank
