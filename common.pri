#Includes common configuration for all subdirectory .pro files.
#INCLUDEPATH += . ..
#WARNINGS += -Wall

# The following keeps the generated files at least somewhat separate 
# from the source files.
OBJECTS_DIR = $$(TPR_SRC)/tmp/.obj
MOC_DIR = $$(TPR_SRC)/tmp/.moc
Debug:DESTDIR = $$(TPR_SRC)/tmp/Debug
Release:DESTDIR = $$(TPR_SRC)/tmp/Release

#Install
target.path = $$(TPR_SRC)/tipra-0.2
INSTALLS += target