#ifndef UTAMA_H
#define UTAMA_H

#include <QMainWindow>
#include <sys/databaseconfig/databaseconfig.h>
#include <modul/pengguna/pengguna.h>
#include <modul/jenis_kendaraan/jenis_kendaraan.h>
#include <modul/waktu_kerja/waktu_kerja.h>
#include <sys/fileconfig/fileconfig.h>
#include <sys/user/user.h>
#include <sys/loginwindow/loginwindow.h>
#include <QStandardItemModel>
#include <QApplication>
#include <sys/about/about.h>

#include <QCloseEvent>
#include <QSettings>

#include <sys/export/Export.h>
#include <QScrollBar>

namespace Ui {
class Utama;
}

class Utama : public QMainWindow
{
    Q_OBJECT

public:
    explicit Utama(QWidget *parent = 0);
    ~Utama();
protected:
    void closeEvent(QCloseEvent *event);
public slots:
    void unLock();


private slots:
    void on_actionKeluar_triggered();

    void on_actionKonfigurasi_DB_triggered();


    void on_actionPengguna_triggered();

    void on_actionJenis_Kendaraan_triggered();

    void on_actionWaktu_Kerja_triggered();

private:
    Ui::Utama *ui;
    bool connected;
    int halamanPinjam;
    QString userId;
    DatabaseConfig *configWindow;
    FileConfig *config;
    User *userLogin;
    pengguna *Pengguna;
    jenis_kendaraan *Jenis_kendaraan;
    waktu_kerja *Waktu_kerja;
    LoginWindow *loginWindow;

    QStandardItemModel *model;
    QStandardItemModel *modelKatalog;



    About *tentang;

    Export *exportWindow;



};

#endif // UTAMA_H
