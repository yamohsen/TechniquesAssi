#Target is the name of the exe
TARGET=PlyToObject

#Where to put .o files $$PWD means in proj dir
OBJECTS_DIR=$$PWD/obj

#Now set some QMAKE settings
#Don't build against qt libs
CONFIG-=qt

#Use C++ 11
CONFIG+=c++11
#DEFINES+=NDEBUG

#Add Source Files
SOURCES +=$$PWD/src/main.cpp \
          $$PWD/src/ImageWrite.cpp \
          $$PWD/src/PLYFile.cpp

#Add header files
HEADERS +=$$PWD/include/ImageWrite.h \
          $$PWD/include/PLYFile.h

INCLUDEPATH+=$$PWD/include
