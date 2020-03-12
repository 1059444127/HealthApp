TEMPLATE = app
CONFIG += console
#CONFIG += no_lflags_merge
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += HAVE_POPEN
DEFINES += HAVE_PCLOSE
DEFINES  -= UNICODE


SOURCES += \
        storescp.cc

INCLUDEPATH +=../../include/mysql/win32
INCLUDEPATH +=../../include/dcm/win32/dcmUnits

INCLUDEPATH +=../../include/dcm/win32/config/include
INCLUDEPATH +=../../include/dcm/win32/ofstd/include
INCLUDEPATH +=../../include/dcm/win32/oflog/include
INCLUDEPATH +=../../include/dcm/win32/dcmnet/include
INCLUDEPATH +=../../include/dcm/win32/dcmdata/include
INCLUDEPATH +=../../include/dcm/win32/dcmqrdb/include
INCLUDEPATH +=../../include/dcm/win32/dcmtls/include

LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/libdcmnet.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/libdcmdata.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/liboflog.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/libofstd.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/libdcmtls.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/libdcmnet.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/libdcmdata.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/liboflog.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/libofstd.a
LIBS +=/home/zyq/windows_share/HealthApp/lib/dcm/win32/libdcmUnits.a
#LIBS +=../../lib/dcm/win32/libdcmdata.a
#LIBS +=../../lib/dcm/win32/liboflog.a
#LIBS +=../../lib/dcm/win32/libofstd.a
#LIBS +=../../lib/dcm/win32/libdcmtls.a
#LIBS +=../../lib/dcm/win32/libdcmnet.a
#LIBS +=../../lib/dcm/win32/libdcmdata.a
#LIBS +=../../lib/dcm/win32/liboflog.a
#LIBS +=../../lib/dcm/win32/libofstd.a
#LIBS +=../../lib/dcm/win32/libdcmUnits.a

LIBS +=-lpthread
LIBS +=-licuuc
LIBS +=-licudata
LIBS +=-lnsl
LIBS +=-lz
