TEMPLATE = app

QT += qml quick \
    serialbus
CONFIG += c++11

SOURCES += main.cpp \
    candataobject.cpp \
    e46canbusframe.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    candataobject.h \
    e46canbusframe.h

DISTFILES +=
