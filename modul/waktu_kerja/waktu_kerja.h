#ifndef WAKTU_KERJA_H
#define WAKTU_KERJA_H

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
#include<modul/waktu_kerja/add_waktu_kerja.h>
namespace Ui {
class waktu_kerja;
}

class waktu_kerja : public QWidget
{
    Q_OBJECT

public:
    explicit waktu_kerja(QWidget *parent = 0);
    ~waktu_kerja();

private slots:
    void setTabelWaktu_kerja();
    void refreshData(QString key = "");
    void on_btnCari_clicked();

    void on_pushButton_clicked();

    void on_tblWaktu_kerja_clicked(const QModelIndex &index);

private:
    Ui::waktu_kerja *ui;
    QString id_waktu_kerja, nama_waktu_kerja, awal_waktu_kerja,akhir_waktu_kerja, tanggal_buat,tanggal_nonaktif;
    int jangka_waktu;
    QSqlQuery query;
    QStandardItemModel *modelwaktu_kerja;
    add_waktu_kerja *Add_waktu_kerja;
};

#endif // WAKTU_KERJA_H
