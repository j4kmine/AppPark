#include "utama.h"
#include "ui_utama.h"
#include <sys/databaseconfig/databaseconfig.h>
#include <sys/user/user.h>
#include <modul/pengguna/pengguna.h>

#include <QDebug>
#include <QMessageBox>
#include <QShortcut>
#include <QLocale>

Utama::Utama(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Utama)
{
    ui->setupUi(this);
    this->showMaximized();
    this->setWindowTitle("Application | "+ QLocale(QLocale::Indonesian,QLocale::Indonesia).toString(QDate().currentDate(),"dd MMMM yyyy") );


    //Shortcut
    // new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));

    //CONNECT

    //connect(ui->tblKatalog,SIGNAL(entered(QModelIndex)),this,SLOT(katEnableButton()));

    //Inisialisasi Window DB
    Pengguna = new pengguna(this);
    Jenis_kendaraan = new jenis_kendaraan(this);
    Waktu_kerja = new waktu_kerja(this);
    configWindow = new DatabaseConfig(this);
    configWindow->setFixedSize(configWindow->size());

    //Chek Db Connected
    if(!configWindow->isDbConnect()){

        configWindow->show();
        this->centralWidget()->setDisabled(true);

        ui->menuMaster->menuAction()->setVisible(false);

        QMessageBox::critical(configWindow,"Error : Koneksi Database","Gagal Menghubungi pusat data. Mohon Periksa Kembail !\n\n"+configWindow->getError());

    }else{
        //Menghubungkan Database
        configWindow->getDb().open();



        //Chek Login
        loginWindow = new LoginWindow(this);
        if(userId.isEmpty() || userId.isNull()){
            //Matikan Menu Utama
         ui->menuMaster->menuAction()->setVisible(false);

            //Munculkan Login Form
            loginWindow->show();



        }
    }



}

void Utama::on_actionKeluar_triggered()
{
    this->close();
    configWindow->getDb().close();
}

void Utama::on_actionKonfigurasi_DB_triggered()
{
    configWindow->show();
}

void Utama::unLock(){
    this->centralWidget()->setEnabled(true);
    ui->menuMaster->menuAction()->setVisible(true);
}



//End
Utama::~Utama()
{
    delete ui;

    configWindow->getDb().close();
}






void Utama::closeEvent(QCloseEvent *event){
    QMessageBox::StandardButton dialog;
    dialog = QMessageBox::warning(this, "Keluar aplikasi ?",
                                  "Anda Yakin Keluar aplikasi ?",
                                  QMessageBox::Ok | QMessageBox::Cancel);
    if( dialog == QMessageBox::Ok) {
        QSettings userSession("Chip-Project","PARKING-User");
        userSession.remove("USERID");
        close();
    } else {
        event->ignore();
    }
}






void Utama::on_actionPengguna_triggered()
{
    pengguna *Pengguna= new pengguna();
    Pengguna->show();
}

void Utama::on_actionJenis_Kendaraan_triggered()
{
    jenis_kendaraan *Jenis_kendaraan = new jenis_kendaraan();
    Jenis_kendaraan->show();
}

void Utama::on_actionWaktu_Kerja_triggered()
{
    waktu_kerja *Waktu_kerja = new waktu_kerja();
    Waktu_kerja->show();
}
