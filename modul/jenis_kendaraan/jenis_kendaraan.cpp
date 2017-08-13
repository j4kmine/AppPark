#include "jenis_kendaraan.h"
#include "ui_jenis_kendaraan.h"

jenis_kendaraan::jenis_kendaraan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::jenis_kendaraan)
{
    ui->setupUi(this);
    modeljenis_kendaraan = new QStandardItemModel(0,5,this);

    ui->tblJenis_kendaraan->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblJenis_kendaraan->setSortingEnabled(true);
    ui->tblJenis_kendaraan->resizeColumnsToContents();
    ui->tblJenis_kendaraan->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblJenis_kendaraan->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblJenis_kendaraan->horizontalHeader()->setStretchLastSection(true);
    ui->tblJenis_kendaraan->setModel(modeljenis_kendaraan);
    this->setTabelJenis_kendaraan();
    this->refreshData();
}
void jenis_kendaraan::setTabelJenis_kendaraan(){
    modeljenis_kendaraan->setHorizontalHeaderItem(0, new QStandardItem(QString("Id Jenis Kendaraan")));
    modeljenis_kendaraan->setHorizontalHeaderItem(1, new QStandardItem(QString("Jenis Kendaraan")));

    modeljenis_kendaraan->setHorizontalHeaderItem(2, new QStandardItem(QString("Tombol Pintas")));
    modeljenis_kendaraan->setHorizontalHeaderItem(3, new QStandardItem(QString("Nip")));

    ui->tblJenis_kendaraan->setColumnWidth(0, 300);//Id Jenis Kendaraan
    ui->tblJenis_kendaraan->setColumnWidth(1, 300);//Jenis Kendaraan
    ui->tblJenis_kendaraan->setColumnWidth(2, 300);//Tombol Pintas
    ui->tblJenis_kendaraan->setColumnWidth(3, 300);//Nip
    ui->tblJenis_kendaraan->setColumnHidden(0, true);
    ui->tblJenis_kendaraan->setColumnHidden(3, true);

}
void jenis_kendaraan::refreshData(QString key){
    QSqlQuery query;
    QVariant status;
      QString sql = "SELECT * FROM master_jenis_kendaraan WHERE id_jenis_kendaaraan LIKE \'%"+key+"%\' OR jenis_kendaraan LIKE \'%"+key+"%\' OR tombol_pintas LIKE \'%"+key+"%\'";
    int count=0;
    modeljenis_kendaraan->clear();
    this->setTabelJenis_kendaraan();
    if(query.exec(sql)){
        while(query.next()){
            modeljenis_kendaraan->setItem(count,0,new QStandardItem(QString(query.value("id_jenis_kendaaraan").toString())));
            modeljenis_kendaraan->setItem(count,1,new QStandardItem(QString(query.value("jenis_kendaraan").toString())));
            modeljenis_kendaraan->setItem(count,2,new QStandardItem(QString(query.value("tombol_pintas").toString())));
            modeljenis_kendaraan->setItem(count,3,new QStandardItem(QString(query.value("nip").toString())));
            count++;
        }
    }
}
jenis_kendaraan::~jenis_kendaraan()
{
    delete ui;
}

void jenis_kendaraan::on_btnCari_clicked()
{
     this->refreshData(ui->cariJenis_kendaraan->text());
}





void jenis_kendaraan::on_pushButton_clicked()
{
    Add_jenis_kendaraan = new add_jenis_kendaraan(this);
    add_jenis_kendaraan *Add_jenis_kendaraan= new add_jenis_kendaraan();
    Add_jenis_kendaraan->show();
}

void jenis_kendaraan::on_tblJenis_kendaraan_clicked(const QModelIndex &index)
{
    int row = index.row();
    QString id_jenis_kendaaraan = index.sibling(row, 0).data().toString();
    QString jenis_kendaraan = index.sibling(row, 1).data().toString();
    QString tombol_pintas = index.sibling(row, 3).data().toString();
    QString nip = index.sibling(row, 3).data().toString();

    Add_jenis_kendaraan = new add_jenis_kendaraan(this);
    add_jenis_kendaraan *Add_jenis_kendaraan= new add_jenis_kendaraan();
    Add_jenis_kendaraan->setId(id_jenis_kendaaraan,jenis_kendaraan,tombol_pintas);
    Add_jenis_kendaraan->show();
}
