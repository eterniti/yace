#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T21:06:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yace
TEMPLATE = app


SOURCES += main.cpp\
        cpkdialog.cpp \
    debug.cpp \
    ../eternity_common/BaseFile.cpp \
    ../eternity_common/Criware/CpkFile.cpp \
    ../eternity_common/Criware/CrilaylaFixedBitStream.cpp \
    ../eternity_common/FileStream.cpp \
    ../eternity_common/FixedBitStream.cpp \
    ../eternity_common/FixedMemoryStream.cpp \
    ../eternity_common/IniFile.cpp \
    ../eternity_common/MemoryStream.cpp \
    ../eternity_common/Stream.cpp \
    ../eternity_common/Criware/UtfFile.cpp \
    ../eternity_common/Utils.cpp \
    ../eternity_common/tinyxml/tinystr.cpp \
    ../eternity_common/tinyxml/tinyxml.cpp \
    ../eternity_common/tinyxml/tinyxmlerror.cpp \
    ../eternity_common/tinyxml/tinyxmlparser.cpp \
    ../eternity_common/BitStream.cpp \
    progressdialog.cpp

HEADERS  += cpkdialog.h \
    ../eternity_common/Criware/AwbFile.h \
    ../eternity_common/BaseFile.h \
    ../eternity_common/common.h \
    ../eternity_common/Criware/CpkFile.h \
    ../eternity_common/Criware/CrilaylaFixedBitStream.h \
    ../eternity_common/debug.h \
    ../eternity_common/FileStream.h \
    ../eternity_common/FixedBitStream.h \
    ../eternity_common/FixedMemoryStream.h \
    ../eternity_common/IniFile.h \
    ../eternity_common/MemoryStream.h \
    ../eternity_common/Stream.h \
    ../eternity_common/Criware/UtfFile.h \
    ../eternity_common/Utils.h \
    ../eternity_common/tinyxml/tinystr.h \
    ../eternity_common/tinyxml/tinyxml.h \
    ../eternity_common/vs/dirent.h \
    ../eternity_common/BitStream.h \
    progressdialog.h

FORMS    += cpkdialog.ui \
    progressdialog.ui

INCLUDEPATH += ../eternity_common ../eternity_common/Criware

QMAKE_CXXFLAGS += -DTIXML_USE_STL -DNO_CRYPTO -DNO_ZLIB
LIBS += -L"C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib\x64" -lversion
