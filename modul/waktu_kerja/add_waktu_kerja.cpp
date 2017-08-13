#include "add_waktu_kerja.h"
#include "ui_add_waktu_kerja.h"
#include<QTime>
add_waktu_kerja::add_waktu_kerja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_waktu_kerja)
{
    ui->setupUi(this);
}
void add_waktu_kerja::setId(QString id_waktu_kerja, QString nama_waktu_kerja, QTime awal_waktu_kerja,QTime akhir_waktu_kerja , QDateTime tgl_aktiv){
    ui->id_waktu_kerja->setText(id_waktu_kerja);
    ui->nama_waktu_kerja->setText(nama_waktu_kerja);
    ui->awal_before->setTime(awal_waktu_kerja);
    ui->awal_waktu_kerja->setTime(awal_waktu_kerja);
    ui->akhir_before->setTime(akhir_waktu_kerja);
    ui->akhir_waktu_kerja->setTime(akhir_waktu_kerja);
    ui->tgl_aktiiv->setDateTime(tgl_aktiv);
    ui->pushButton->setEnabled(false);
    ui->edit->setEnabled(true);
    ui->label_6->setText("Form Edit Waktu Kerja");
    ui->id_waktu_kerja->setEnabled(false);

}
add_waktu_kerja::~add_waktu_kerja()
{
    delete ui;
}

void add_waktu_kerja::on_pushButton_clicked()
{
      QString id_waktu_kerja, nama_waktu_kerja,awal_waktu_kerja_str,akhir_waktu_kerja_str,tgl_aktiv_str;
      QTime awal_waktu_kerja , akhir_waktu_kerja;
      QDateTime tgl_aktiv;
      id_waktu_kerja = ui->id_waktu_kerja->text();
      nama_waktu_kerja = ui->nama_waktu_kerja->text();
      awal_waktu_kerja = ui->awal_waktu_kerja->time();
      akhir_waktu_kerja = ui->akhir_waktu_kerja->time();
      tgl_aktiv = ui->tgl_aktiiv->dateTime();

     if(id_waktu_kerja == ""){
          QMessageBox::critical(this,"Error","Silahkan Isi Id Akhir Kerja");

      }else if(nama_waktu_kerja == ""){
          QMessageBox::critical(this,"Error","Silahkan Isi Nama Waktu Kerja Kerja");

      }else{
          awal_waktu_kerja_str = awal_waktu_kerja.toString("hh:mm");
          akhir_waktu_kerja_str = akhir_waktu_kerja.toString("hh:mm");
          tgl_aktiv_str = tgl_aktiv.toString("yyyy/MM/dd hh:mm:ss");
          QSqlQuery query;
          if(query.exec("INSERT INTO public.master_waktu_kerja("
                        "id_waktu_kerja, nama_waktu_kerja, awal_waktu_kerja, akhir_waktu_kerja,"
                        "tanggal_buat)"
                        " VALUES ( '"+id_waktu_kerja+"',  '"+nama_waktu_kerja+"', '"+awal_waktu_kerja_str+"', '"+akhir_waktu_kerja_str+"', '"+tgl_aktiv_str+"')")){
              QMessageBox::information(this,"Berhasil","Penambahan Waktu Kerja Berhasil");
              ui->id_waktu_kerja->clear();
              ui->nama_waktu_kerja->clear();
              ui->awal_waktu_kerja->clear();
              ui->akhir_waktu_kerja->clear();
          }else{
              QMessageBox::critical(this,"Gagal","Penambahan Gagal \n\nAlasan : "+query.lastError().text());
          }
      }
}

void add_waktu_kerja::on_edit_clicked()
{
     QTime awal_waktu_kerja , akhir_waktu_kerja ,awal_before , akhir_before;
     awal_waktu_kerja = ui->awal_waktu_kerja->time();
     akhir_waktu_kerja = ui->akhir_waktu_kerja->time();
     awal_before = ui->awal_before->time();
     akhir_before = ui->akhir_before->time();
     QString id_waktu_kerja = ui->id_waktu_kerja->text();
     QString nama_waktu_kerja = ui->nama_waktu_kerja->text();
     QDateTime tgl_aktiv = ui->tgl_aktiiv->dateTime();
     QString  tgl_aktiv_str = tgl_aktiv.toString("yyyy/MM/dd hh:mm:ss");
     QString awal_waktu_kerja_str = awal_waktu_kerja.toString("hh:mm");
     QString akhir_waktu_kerja_str = akhir_waktu_kerja.toString("hh:mm");
     if(awal_waktu_kerja == awal_before && akhir_waktu_kerja == akhir_before){
         QSqlQuery query;
         if(query.exec("UPDATE public.master_waktu_kerja "
                       "SET nama_waktu_kerja ='"+nama_waktu_kerja+"', tanggal_buat = '"+tgl_aktiv_str+"' "
                       "WHERE id_waktu_kerja ='"+id_waktu_kerja+"'")){
             QMessageBox::information(this,"Berhasil","Perubahan Waktu Kerja");


         }else{
             QMessageBox::critical(this,"Gagal","Penambahan Gagal \n\nAlasan : "+query.lastError().text());
         }
     }else{
         QSqlQuery query;
         QSqlQuery querys;
         if(query.exec("UPDATE public.master_waktu_kerja "
                       "SET tanggal_nonaktif = now() "
                       "WHERE id_waktu_kerja ='"+id_waktu_kerja+"'")){

             if(querys.exec("INSERT INTO public.master_waktu_kerja("
                           "id_waktu_kerja, nama_waktu_kerja, awal_waktu_kerja, akhir_waktu_kerja,"
                           "tanggal_buat)"
                           " VALUES ( '33',  '"+nama_waktu_kerja+"', '"+awal_waktu_kerja_str+"', '"+akhir_waktu_kerja_str+"', '"+tgl_aktiv_str+"')")){


              }else{
                QMessageBox::critical(this,"Gagal","Penambahan Gagal \n\nAlasan : "+query.lastError().text());
             }
              QMessageBox::information(this,"Berhasil","Perubahan Waktu Kerja");

         }else{
             QMessageBox::critical(this,"Gagal","Penambahan Gagal \n\nAlasan : "+query.lastError().text());
         }
     }
}
