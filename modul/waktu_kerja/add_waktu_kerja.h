#ifndef ADD_WAKTU_KERJA_H
#define ADD_WAKTU_KERJA_H

#include <QDialog>
#include <QWidget>
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
#include<QTime>
#include<QDateTime>
namespace Ui {
class add_waktu_kerja;
}

class add_waktu_kerja : public QDialog
{
    Q_OBJECT

public:
    void setId(QString id_waktu_kerja, QString nama_waktu_kerja, QTime awal_waktu_kerja,QTime akhir_waktu_kerja,QDateTime tgl_aktiv);
    explicit add_waktu_kerja(QWidget *parent = 0);
    ~add_waktu_kerja();

private slots:
    void on_pushButton_clicked();

    void on_edit_clicked();

private:
    Ui::add_waktu_kerja *ui;
};

#endif // ADD_WAKTU_KERJA_H
