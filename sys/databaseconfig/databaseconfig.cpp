#include "databaseconfig.h"
#include "ui_databaseconfig.h"
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QSettings>
#include <QShortcut>

DatabaseConfig::DatabaseConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseConfig)
{
    ui->setupUi(this);
    //Shortcut
    new QShortcut( QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()) );
    //Add Database
    db = QSqlDatabase::addDatabase("QPSQL");

    //Add Dir
    QDir path;
    appPath = path.absolutePath();

    //Baca COnfig
    ReadConfig();
}

DatabaseConfig::~DatabaseConfig()
{
    delete ui;
}

void DatabaseConfig::ReadConfig(){

    //File Db Setting
    QSettings dbSetting("Chip-Project","PARKING");

    //Baca Config dan Masukkan ke value Line Edit
    ui->lHost->setText( dbSetting.value("host").toString() );
    ui->lUser->setText( dbSetting.value("user").toString() );
    ui->lPass->setText( dbSetting.value("pass").toString() );
    ui->lDatabase->setText( dbSetting.value("dbname").toString() );
    ui->spinBox->setValue( dbSetting.value("port").toInt() );//Port

}

void DatabaseConfig::on_pushButton_2_clicked()
{
    //Tombol Batal
    this->close();
}

void DatabaseConfig::on_pTest_clicked()
{
    //Simpan Konfigurasi
    simpanSetting();
    //Test
    if(this->isDbConnect()){
        QMessageBox::information(this,"Tersambung...","Koneksi Database Berhasil di buat !!");
    }else{
        QMessageBox::critical(this,"Gagal...","Koneksi Database Gagal di buat !!");
    }
}

QSqlDatabase DatabaseConfig::getDb(){
    //File Db Setting
    QSettings dbSetting("Chip-Project","PARKING");

    //Baca Config dan masukkan ke configurasi
    db.setHostName( dbSetting.value("host","localhost").toString() );
    db.setPort( dbSetting.value("port",5432).toInt() );
    db.setUserName( dbSetting.value("user","chip").toString() );
    db.setPassword( dbSetting.value("pass","chip").toString() );
    db.setDatabaseName( dbSetting.value("dbname","parkir").toString() );
    return db;
}

bool DatabaseConfig::isDbConnect(){
    QSqlDatabase testdb = this->getDb();
    bool ret;
    if(testdb.open()){

        QSqlQuery testquery;
        if(testquery.exec("SELECT COUNT(*) FROM master_pengguna")){
            ret = true;
        }else{
            ret = false;
        }

    }else{
        ret = false;
    }
    //testdb.close();
    return ret;
}

QString DatabaseConfig::getError(){
    return db.lastError().text();
}

void DatabaseConfig::on_pSimpan_clicked()
{
    simpanSetting();
    QMessageBox::information(this,"Simpan","Berhasil Disimpan !!");
}

void DatabaseConfig::simpanSetting(){
    //File Db Setting
    QSettings dbSetting("Chip-Project","PARKING");
    //Input setting value
    dbSetting.setValue("host",ui->lHost->text());
    dbSetting.setValue("user",ui->lUser->text());
    dbSetting.setValue("pass",ui->lPass->text());
    dbSetting.setValue("port",ui->spinBox->value());
    dbSetting.setValue("dbname",ui->lDatabase->text());
}
