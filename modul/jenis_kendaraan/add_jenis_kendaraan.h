#ifndef ADD_JENIS_KENDARAAN_H
#define ADD_JENIS_KENDARAAN_H


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

namespace Ui {
class add_jenis_kendaraan;
}

class add_jenis_kendaraan : public QDialog
{
    Q_OBJECT

public:
    explicit add_jenis_kendaraan(QWidget *parent = 0);
    void setId(QString id_jenis_kendaaraan, QString jenis_kendaraan, QString tombol_pintas);
    ~add_jenis_kendaraan();

private slots:
    void on_pushButton_clicked();

    void on_edit_clicked();

private:
    Ui::add_jenis_kendaraan *ui;
};

#endif // ADD_JENIS_KENDARAAN_H
