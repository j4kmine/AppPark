#include "add_jenis_kendaraan.h"
#include "ui_add_jenis_kendaraan.h"

add_jenis_kendaraan::add_jenis_kendaraan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_jenis_kendaraan)
{
    ui->setupUi(this);
}

add_jenis_kendaraan::~add_jenis_kendaraan()
{
    delete ui;
}
void add_jenis_kendaraan::setId(QString id_jenis_kendaaraan, QString jenis_kendaraan, QString tombol_pintas ){
    ui->id_jenis_kendaraan->setText(id_jenis_kendaaraan);
    ui->jenis_kendaraan->setText(jenis_kendaraan);
    ui->pintas->setText(tombol_pintas);
    ui->pushButton->setEnabled(false);
    ui->edit->setEnabled(true);
    ui->label_6->setText("Form Edit Jenis kendaraan");
    ui->id_jenis_kendaraan->setEnabled(false);

}
void add_jenis_kendaraan::on_pushButton_clicked()
{
    QString id_jenis_kendaaraan, jenis_kendaraan, tombol_pintas;
    id_jenis_kendaaraan = ui->id_jenis_kendaraan->text();
    jenis_kendaraan = ui->jenis_kendaraan->text();
    tombol_pintas = ui->pintas->text();
    QSettings userSession("Chip-Project","PARKING-User");
    QString idPetugas = userSession.value("USERID").toString();
    if(id_jenis_kendaaraan == "" ){
            QMessageBox::critical(this,"Error","Silahkan Mengisi Id Jenis Kendaraan");
    }else if(jenis_kendaraan == ""){

           QMessageBox::critical(this,"Error","Silahkan Mengisi Jenis Kendaraan");

    }else if(tombol_pintas == ""){

           QMessageBox::critical(this,"Error","Silahkan Mengisi pintasan");

    }else{


        QSqlQuery query;
        if(query.exec("INSERT INTO public.master_jenis_kendaraan("
                      "id_jenis_kendaaraan, jenis_kendaraan, tombol_pintas, nip, tanggal_buat,"
                      "tanggal_ubah) VALUES ( '"+id_jenis_kendaaraan+"',  '"+jenis_kendaraan+"', '"+tombol_pintas+"', '"+idPetugas+"',now(),now())")){
            QMessageBox::information(this,"Berhasil","Penambahan Jenis Kendaraan Berhasil");
            ui->id_jenis_kendaraan->clear();
            ui->jenis_kendaraan->clear();
            ui->pintas->clear();

        }else{
            QMessageBox::critical(this,"Gagal","Penambahan Gagal \n\nAlasan : "+query.lastError().text());
        }
    }

}

void add_jenis_kendaraan::on_edit_clicked()
{
    QString id_jenis_kendaaraan, jenis_kendaraan, tombol_pintas;
    id_jenis_kendaaraan = ui->id_jenis_kendaraan->text();
    jenis_kendaraan = ui->jenis_kendaraan->text();
    tombol_pintas = ui->pintas->text();
    QSettings userSession("Chip-Project","PARKING-User");
    QString idPetugas = userSession.value("USERID").toString();
    QSqlQuery query;
    if(query.exec("UPDATE public.master_jenis_kendaraan "
                  "SET jenis_kendaraan ='"+jenis_kendaraan+"', tombol_pintas = '"+tombol_pintas+"', nip = '"+idPetugas+"',tanggal_ubah = now()  "
                  "WHERE id_jenis_kendaaraan ='"+id_jenis_kendaaraan+"'")){
        QMessageBox::information(this,"Berhasil","Penambahan Jenis Kendaraan Berhasil");
       \

    }else{
        QMessageBox::critical(this,"Gagal","Penambahan Gagal \n\nAlasan : "+query.lastError().text());
    }
}
