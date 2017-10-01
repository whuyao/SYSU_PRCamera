#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T17:47:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 3): QT += widgets

TARGET = SYSU_PRCamera
TEMPLATE = app

DEFINES += USE_GIST STANDALONE_GIST


SOURCES += main.cpp\
    compute_gist.cpp \
    gist.cpp \
    gistthread.cpp \
    loadsvmdlg.cpp \
    standalone_image.cpp \
    SVM_MultiClassifier.cpp \
    svm.cpp \
    sysu_prcamera.cpp \
    trainsvmdlg.cpp \
    alglib/alglibinternal.cpp \
    alglib/alglibmisc.cpp \
    alglib/ap.cpp \
    alglib/dataanalysis.cpp \
    alglib/diffequations.cpp \
    alglib/fasttransforms.cpp \
    alglib/integration.cpp \
    alglib/interpolation.cpp \
    alglib/linalg.cpp \
    alglib/optimization.cpp \
    alglib/solvers.cpp \
    alglib/specialfunctions.cpp \
    alglib/statistics.cpp

HEADERS  += \
    compute_gist.h \
    gist.h \
    gistthread.h \
    loadsvmdlg.h \
    standalone_image.h \
    SVM_MultiClassifier.h \
    svm.h \
    sysu_prcamera.h \
    trainsvmdlg.h \
    alglib/alglibinternal.h \
    alglib/alglibmisc.h \
    alglib/ap.h \
    alglib/dataanalysis.h \
    alglib/diffequations.h \
    alglib/fasttransforms.h \
    alglib/integration.h \
    alglib/interpolation.h \
    alglib/linalg.h \
    alglib/optimization.h \
    alglib/solvers.h \
    alglib/specialfunctions.h \
    alglib/statistics.h \
    alglib/stdafx.h

FORMS    += \
    loadsvmdlg.ui \
    sysu_prcamera.ui \
    trainsvmdlg.ui

LIBS += -lpthread

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/lib/ -lopencv_core.2.4.12

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/lib/ -lopencv_highgui.2.4.12

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/lib/ -lopencv_video.2.4.12

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/lib/ -lopencv_imgproc.2.4.12

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/lib/ -lfftw3.3

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/include

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/lib/ -lfftw3f.3

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/include

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/lib/ -lfftw3l.3

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/fftw/3.3.4_1/include

RESOURCES += \
    sysu_prcamera.qrc

DISTFILES += \
    SYSU_PRCamera.pro.user \
    486745797464477783.png \
    sysu1.ico \
    Sysu985.rc \
    ../../../../../../usr/local/Cellar/opencv/2.4.12_2/lib/libopencv_legacy.2.4.12.dylib

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/lib/ -lopencv_contrib.2.4.12

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/lib/ -lopencv_photo.2.4.12

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/opencv/2.4.12_2/include
