#-------------------------------------------------
#
# Project created by QtCreator 2013-11-10T08:11:40
#
#-------------------------------------------------

QT       += core gui sql
CONFIG   += static staticlib

QMAKE_LFLAGS += -Wl,-rpath,\\$\$ORIGIN/lib/:\\$\$ORIGIN/../lib/

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PARKING
TEMPLATE = app


SOURCES += main.cpp\
        sys/utama/utama.cpp \
    sys/databaseconfig/databaseconfig.cpp \
    sys/fileconfig/fileconfig.cpp \
    sys/user/user.cpp \
    sys/loginwindow/loginwindow.cpp \
    modul/pengguna/pengguna.cpp \
    modul/pengguna/add_pengguna.cpp \
    modul/jenis_kendaraan/jenis_kendaraan.cpp \
    modul/jenis_kendaraan/add_jenis_kendaraan.cpp \
    modul/waktu_kerja/waktu_kerja.cpp \
    modul/waktu_kerja/add_waktu_kerja.cpp




    sys/about/about.cpp \

    sys/export/Export.cpp \


HEADERS  += sys/utama/utama.h \
    sys/databaseconfig/databaseconfig.h \
    sys/fileconfig/fileconfig.h \
    sys/user/user.h \
    sys/loginwindow/loginwindow.h \
    modul/pengguna/pengguna.h \
    modul/pengguna/add_pengguna.h \
    modul/jenis_kendaraan/jenis_kendaraan.h \
    modul/jenis_kendaraan/add_jenis_kendaraan.h \
    modul/waktu_kerja/waktu_kerja.h \
    modul/waktu_kerja/add_waktu_kerja.h





    sys/about/about.h \

    sys/export/Export.h \


FORMS    += sys/utama/utama.ui \
    sys/databaseconfig/databaseconfig.ui \
    sys/loginwindow/loginwindow.ui \
    sys/about/about.ui \
    modul/pengguna/pengguna.ui \
    modul/pengguna/add_pengguna.ui \
    modul/jenis_kendaraan/jenis_kendaraan.ui \
    modul/jenis_kendaraan/add_jenis_kendaraan.ui \
    modul/waktu_kerja/waktu_kerja.ui \
    modul/waktu_kerja/add_waktu_kerja.ui



    sys/export/Export.ui \

RESOURCES += \
    glypticon.qrc

