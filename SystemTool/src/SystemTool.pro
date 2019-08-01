#-------------------------------------------------
#
# Project created by QtCreator 2019-07-29T07:04:50
#
#-------------------------------------------------

QT       -= core gui

TARGET = SystemTool
TEMPLATE = lib

DEFINES += SYSTEMTOOL_LIBRARY
DESTDIR = $$PWD/../../bin

INCLUDEPATH += $$PWD/../../include \
                $$PWD/../../include/SystemTool
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
    CommandExecutor.cpp \
    CommandQueue.cpp \
    DataObject.cpp \
    MsgKey.cpp \
    ReadWriteMutex.cpp \
    SyncBase.cpp \
    Task.cpp \
    Thread.cpp \
    ThreadEvent.cpp \
    ThreadLock.cpp \
    ThreadMutex.cpp \
    ThreadSemaphore.cpp

HEADERS += \
    ../../include/SystemTool/BlockingQueue.h \
    ../../include/SystemTool/CommandExecutor.h \
    ../../include/SystemTool/CommandQueue.h \
    ../../include/SystemTool/DataObject.h \
    ../../include/SystemTool/MsgKey.h \
    ../../include/SystemTool/ReadWriteMutex.h \
    ../../include/SystemTool/SyncBase.h \
    ../../include/SystemTool/Task.h \
    ../../include/SystemTool/TaskLib_Global.h \
    ../../include/SystemTool/Thread.h \
    ../../include/SystemTool/ThreadBase.h \
    ../../include/SystemTool/ThreadEvent.h \
    ../../include/SystemTool/ThreadLock.h \
    ../../include/SystemTool/ThreadMutex.h \
    ../../include/SystemTool/ThreadSemaphore.h \
    ThreadPrivate.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
