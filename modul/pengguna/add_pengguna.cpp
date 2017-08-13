#include "add_pengguna.h"
#include "ui_add_pengguna.h"
add_pengguna::add_pengguna(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_pengguna)
{
    ui->setupUi(this);

}

add_pengguna::~add_pengguna()
{
    delete ui;
}

void add_pengguna::on_pushButton_clicked()
{
      QString nip, nama_pengguna, kata_kunci, status_pengguna,tingkat_akses,tanggal_buat,tanggal_ubah;
      nip = ui->nip->text();
      nama_pengguna = ui->nama_pengguna->text();
      kata_kunci = ui->kata_kunci->text();
      if(nip == "" ){
              QMessageBox::critical(this,"Error","Silahkan Mengisi NIP");
      }else if(nama_pengguna == ""){

             QMessageBox::critical(this,"Error","Silahkan Mengisi Nama Pengguna");

      }else if(kata_kunci == ""){

             QMessageBox::critical(this,"Error","Silahkan Mengisi Kata Kunci");

      }else{
          if(ui->active->isChecked()){
              status_pengguna = "1";
          }else{
              status_pengguna ="0";
          }
          int tingkat_aksess = ui->tingkat_akses->currentIndex();
          tingkat_akses = QString::number(tingkat_aksess);
          QCryptographicHash hash(QCryptographicHash::Md5);
          hash.addData(kata_kunci.toLatin1());
          QString haskata_kunci = hash.result().toHex();

          QSqlQuery query;
          if(query.exec("INSERT INTO public.master_pengguna("
                        "nip, nama_pengguna, kata_kunci, status_pengguna, tingkat_akses,"
                        "tanggal_buat, tanggal_ubah) VALUES ( '"+nip+"',  '"+nama_pengguna+"', '"+haskata_kunci+"', '"+status_pengguna+"', "+tingkat_akses+",now(),now())")){
              QMessageBox::information(this,"Berhasil","Penambahan User Berhasil");
              ui->nip->clear();
              ui->nama_pengguna->clear();
              ui->kata_kunci->clear();

          }else{
              QMessageBox::critical(this,"Gagal","Penambahan Gagal \n\nAlasan : "+query.lastError().text());
          }
      }


}
void add_pengguna::setId(QString nip,QString nama_pengguna,QString status_pengguna,int tingkat_akses ){
    ui->nip->setText(nip);
    ui->nama_pengguna->setText(nama_pengguna);
    ui->kata_kunci->setText(kata_kunci);
    if(status_pengguna == "Aktif"){
        ui->active->setChecked(true);
    }else{
        ui->nonaktif->setChecked(true);
    }
    if(tingkat_akses != -1 || tingkat_akses < 2){
         ui->tingkat_akses->setCurrentIndex(tingkat_akses);
    }
    ui->label_6->setText("Form Edit Pengguna");
    ui->pushButton->setDisabled(true);
    ui->edit->setDisabled(false);
    ui->nip->setDisabled(true);
}

void add_pengguna::on_edit_clicked()
{
    QString nip, nama_pengguna, kata_kunci, status_pengguna,tingkat_akses,tanggal_buat,tanggal_ubah;
    nip = ui->nip->text();
    nama_pengguna = ui->nama_pengguna->text();
    kata_kunci = ui->kata_kunci->text();
    if(nip == "" ){
            QMessageBox::critical(this,"Error","Silahkan Mengisi NIP");
    }else if(nama_pengguna == ""){

           QMessageBox::critical(this,"Error","Silahkan Mengisi Nama Pengguna");

    }else{
        if(ui->active->isChecked()){
            status_pengguna = "1";
        }else{
            status_pengguna ="0";
        }
        int tingkat_aksess = ui->tingkat_akses->currentIndex();
        tingkat_akses = QString::number(tingkat_aksess);
        if(kata_kunci != ""){
            QCryptographicHash hash(QCryptographicHash::Md5);
            hash.addData(kata_kunci.toLatin1());
            QString haskata_kunci = hash.result().toHex();
            QSqlQuery query;
            if(query.exec("UPDATE public.master_pengguna "
                          "SET nama_pengguna ='"+nama_pengguna+"', kata_kunci = '"+haskata_kunci+"', status_pengguna = '"+status_pengguna+"',tingkat_akses = '"+tingkat_akses+"',tanggal_ubah = now()  "
                          "WHERE nip ='"+nip+"'")){
                QMessageBox::information(this,"Berhasil","Perubahan User Berhasil");
                ui->nip->clear();
                ui->nama_pengguna->clear();
                ui->kata_kunci->clear();

            }else{
                QMessageBox::critical(this,"Gagal","Perubahan Gagal \n\nAlasan : "+query.lastError().text());
            }
        }else{
            QSqlQuery query;
            if(query.exec("UPDATE public.master_pengguna "
                          "SET nama_pengguna ='"+nama_pengguna+"',status_pengguna = '"+status_pengguna+"',tingkat_akses = '"+tingkat_akses+"',tanggal_ubah = now()  "
                          "WHERE nip ='"+nip+"'")){
                QMessageBox::information(this,"Berhasil","Perubahan User Berhasil");
                ui->nip->clear();
                ui->nama_pengguna->clear();
                ui->kata_kunci->clear();

            }else{
                QMessageBox::critical(this,"Gagal","Perubahan Gagal \n\nAlasan : "+query.lastError().text());
            }
        }



    }
}
