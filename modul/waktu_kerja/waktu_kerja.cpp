#include "waktu_kerja.h"
#include "ui_waktu_kerja.h"

waktu_kerja::waktu_kerja(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::waktu_kerja)
{
    ui->setupUi(this);
    modelwaktu_kerja = new QStandardItemModel(0,6,this);

    ui->tblWaktu_kerja->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblWaktu_kerja->setSortingEnabled(true);
    ui->tblWaktu_kerja->resizeColumnsToContents();
    ui->tblWaktu_kerja->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblWaktu_kerja->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblWaktu_kerja->horizontalHeader()->setStretchLastSection(true);
    ui->tblWaktu_kerja->setModel(modelwaktu_kerja);
    this->setTabelWaktu_kerja();
    this->refreshData();
}

waktu_kerja::~waktu_kerja()
{
    delete ui;
}
void waktu_kerja::setTabelWaktu_kerja(){

    modelwaktu_kerja->setHorizontalHeaderItem(0, new QStandardItem(QString("Id Waktu Kerja")));
    modelwaktu_kerja->setHorizontalHeaderItem(1, new QStandardItem(QString("Nama Waktu Kerja")));
    modelwaktu_kerja->setHorizontalHeaderItem(2, new QStandardItem(QString("Awal Waktu Kerja")));
    modelwaktu_kerja->setHorizontalHeaderItem(3, new QStandardItem(QString("Akhir Waktu Kerja")));
    modelwaktu_kerja->setHorizontalHeaderItem(4, new QStandardItem(QString("Tgl Aktiv")));
    ui->tblWaktu_kerja->setColumnWidth(0, 300);
    ui->tblWaktu_kerja->setColumnWidth(1, 300);
    ui->tblWaktu_kerja->setColumnWidth(2, 300);
    ui->tblWaktu_kerja->setColumnWidth(3, 300);
    ui->tblWaktu_kerja->setColumnHidden(0, true);
    ui->tblWaktu_kerja->setColumnHidden(4, true);




}

void waktu_kerja::refreshData(QString key){
    QSqlQuery query;
    QString sql = "SELECT * FROM master_waktu_kerja WHERE tanggal_nonaktif IS NULL AND  nama_waktu_kerja LIKE \'%"+key+"%\'";
    int count=0;
    modelwaktu_kerja->clear();
    this->setTabelWaktu_kerja();
    if(query.exec(sql)){
        while(query.next()){
            modelwaktu_kerja->setItem(count,0,new QStandardItem(QString(query.value("id_waktu_kerja").toString())));
            modelwaktu_kerja->setItem(count,1,new QStandardItem(QString(query.value("nama_waktu_kerja").toString())));
            modelwaktu_kerja->setItem(count,2,new QStandardItem(QString(query.value("awal_waktu_kerja").toString())));
            modelwaktu_kerja->setItem(count,3,new QStandardItem(QString(query.value("akhir_waktu_kerja").toString())));
            modelwaktu_kerja->setItem(count,4,new QStandardItem(QString(query.value("tanggal_buat").toString())));
            count++;
        }
    }

}

void waktu_kerja::on_btnCari_clicked()
{
  this->refreshData(ui->cariwaktu_kerja->text());
}

void waktu_kerja::on_pushButton_clicked()
{
    Add_waktu_kerja= new add_waktu_kerja(this);
    add_waktu_kerja *Add_waktu_kerja= new add_waktu_kerja();
    Add_waktu_kerja->show();
}

void waktu_kerja::on_tblWaktu_kerja_clicked(const QModelIndex &index)
{
    int row = index.row();
    QString id_waktu_kerja = index.sibling(row, 0).data().toString();
    QString nama_waktu_kerja = index.sibling(row, 1).data().toString();
    QTime awal_waktu_kerja = index.sibling(row, 3).data().toTime();
    QTime akhir_waktu_kerja = index.sibling(row, 3).data().toTime();
    QDateTime tgl_aktiv = index.sibling(row, 4).data().toDateTime();
    Add_waktu_kerja = new add_waktu_kerja(this);
    add_waktu_kerja *Add_waktu_kerja= new add_waktu_kerja();
    Add_waktu_kerja->setId(id_waktu_kerja,nama_waktu_kerja,awal_waktu_kerja,akhir_waktu_kerja,tgl_aktiv);
    Add_waktu_kerja->show();
}
