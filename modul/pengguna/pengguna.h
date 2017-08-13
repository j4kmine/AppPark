#ifndef PENGGUNA_H
#define PENGGUNA_H

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
#include <modul/pengguna/add_pengguna.h>
namespace Ui {
class pengguna;
}

class pengguna : public QDialog
{
    Q_OBJECT

public:
    explicit pengguna(QWidget *parent = 0);

    ~pengguna();
private slots:


    void setTabelPengguna();

    void refreshData(QString key = "");

    void on_btnCari_clicked();


    void on_pushButton_clicked();



    void on_tblPengguna_clicked(const QModelIndex &index);

private:
    Ui::pengguna *ui;

    QString nip, nama_pengguna, kata_kunci, status_pengguna,tingkat_akses,tanggal_buat,tanggal_ubah;
    QSqlQuery query;
    QStandardItemModel *modelpengguna;
    add_pengguna *Add_pengguna;

};

#endif // PENGGUNA_H
