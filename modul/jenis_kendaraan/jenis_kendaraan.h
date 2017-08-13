#ifndef JENIS_KENDARAAN_H
#define JENIS_KENDARAAN_H

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
#include <QSettings>
#include <modul/jenis_kendaraan/add_jenis_kendaraan.h>
namespace Ui {
class jenis_kendaraan;
}

class jenis_kendaraan : public QWidget
{
    Q_OBJECT

public:
    explicit jenis_kendaraan(QWidget *parent = 0);
    ~jenis_kendaraan();

private slots:
    void setTabelJenis_kendaraan();

    void refreshData(QString key = "");
    void on_btnCari_clicked();

    void on_pushButton_clicked();



    void on_tblJenis_kendaraan_clicked(const QModelIndex &index);

private:
    Ui::jenis_kendaraan *ui;
    QString id_jenis_kendaaraan, jenis_kendaraans, tombol_pintas, nip,tanggal_buat,tanggal_ubah;
    QSqlQuery query;
    QStandardItemModel *modeljenis_kendaraan;
    add_jenis_kendaraan *Add_jenis_kendaraan;
};

#endif // JENIS_KENDARAAN_H
