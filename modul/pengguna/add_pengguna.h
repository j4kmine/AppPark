#ifndef ADD_PENGGUNA_H
#define ADD_PENGGUNA_H

#include <QWidget>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QString>
#include <QCryptographicHash>

namespace Ui {
class add_pengguna;
}

class add_pengguna : public QWidget
{
    Q_OBJECT

public:
    explicit add_pengguna(QWidget *parent = 0);
     void setId(QString nip,QString nama_pengguna,QString status_pengguna,int tingkat_akses );
    ~add_pengguna();

private slots:
    void on_pushButton_clicked();


    void on_edit_clicked();

private:
    Ui::add_pengguna *ui;
    QString nip, nama_pengguna, kata_kunci, status_pengguna,tingkat_akses,tanggal_buat,tanggal_ubah;
    QSqlQuery query;

};

#endif // ADD_PENGGUNA_H
