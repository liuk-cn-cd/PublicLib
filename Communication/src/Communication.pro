#-------------------------------------------------
#
# Project created by QtCreator 2019-07-29T06:13:34
#
#-------------------------------------------------

QT       -= core gui

TARGET = Communication
TEMPLATE = lib
DESTDIR = $$PWD/../../bin
INCLUDEPATH += $$PWD/../../include \
                $$PWD/../../include/Communication \
                $$PWD/../../include/Communication/TCP \
                $$PWD/../../include/Communication/UDP \
                $$PWD/../../include/SystemTool
LIBS += -L$$PWD/../../bin\
        -lSystemTool
DEFINES += COMMUNICATION_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SocketNode.cpp \
    TCP/TcpClient.cpp \
    TCP/TcpClientInfo.cpp \
    TCP/TcpServer.cpp \
    UDP/UdpMulticast.cpp \
    UDP/UdpSocket.cpp \
    UDP/UdpUnicast.cpp \
    UdpSocketPrivate.cpp

HEADERS += \
    ../../include/Communication/CommuDefine.h \
    ../../include/Communication/SocketNode.h \
    ../../include/Communication/TCP/TcpClient.h \
    ../../include/Communication/TCP/TcpClientInfo.h \
    ../../include/Communication/TCP/TcpServer.h \
    ../../include/Communication/UDP/IUdpUser.h \
    ../../include/Communication/UDP/UdpMulticast.h \
    ../../include/Communication/UDP/UdpSocket.h \
    ../../include/Communication/UDP/UdpUnicast.h \
    ../../include/Communication/communication_global.h \
    UdpSocketPrivate.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
