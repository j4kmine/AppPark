#include "pengguna.h"
#include "ui_pengguna.h"

pengguna::pengguna(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pengguna)
{
    ui->setupUi(this);
    //atur model tabel pengguna

    modelpengguna = new QStandardItemModel(0,5,this);

    ui->tblPengguna->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblPengguna->setSortingEnabled(true);
    ui->tblPengguna->resizeColumnsToContents();
    ui->tblPengguna->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblPengguna->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblPengguna->horizontalHeader()->setStretchLastSection(true);
    ui->tblPengguna->setModel(modelpengguna);
    this->setTabelPengguna();
    this->refreshData();
}
void pengguna::setTabelPengguna(){
    modelpengguna->setHorizontalHeaderItem(0, new QStandardItem(QString("Nip")));
    modelpengguna->setHorizontalHeaderItem(1, new QStandardItem(QString("Nama")));

    modelpengguna->setHorizontalHeaderItem(2, new QStandardItem(QString("kata_kunci")));
    modelpengguna->setHorizontalHeaderItem(3, new QStandardItem(QString("Status")));
    modelpengguna->setHorizontalHeaderItem(4, new QStandardItem(QString("tingkat_akses")));

    ui->tblPengguna->setColumnWidth(0, 200);//Nip
    ui->tblPengguna->setColumnWidth(1, 300);//Nama
    ui->tblPengguna->setColumnWidth(2, 300);//Status
    ui->tblPengguna->setColumnWidth(3, 300);//Status
    ui->tblPengguna->setColumnWidth(4, 300);//Status
    ui->tblPengguna->setColumnHidden(2, true);
    ui->tblPengguna->setColumnHidden(4, true);
}

void pengguna::refreshData(QString key){
    QSqlQuery query;
    QVariant status;
      QString sql = "SELECT * FROM master_pengguna WHERE nip LIKE \'%"+key+"%\' OR nama_pengguna LIKE \'%"+key+"%\'";
    int count=0;
    modelpengguna->clear();
    this->setTabelPengguna();
    if(query.exec(sql)){
        while(query.next()){
            modelpengguna->setItem(count,0,new QStandardItem(QString(query.value("nip").toString())));
            modelpengguna->setItem(count,1,new QStandardItem(QString(query.value("nama_pengguna").toString())));
            modelpengguna->setItem(count,2,new QStandardItem(QString(query.value("kata_kunci").toString())));
            status = query.value("status_pengguna");
             if(status == 1){
                  modelpengguna->setData(modelpengguna->index(count, 3), "Aktif");
             }else{
                  modelpengguna->setData(modelpengguna->index(count, 3), "Tidak Aktif");
             }

            modelpengguna->setItem(count,4,new QStandardItem(QString(query.value("tingkat_akses").toString())));


            count++;
        }
    }
}

pengguna::~pengguna()
{
    delete ui;
}

void pengguna::on_btnCari_clicked()
{
    this->refreshData(ui->cariPengguna->text());
}




void pengguna::on_pushButton_clicked()
{
  Add_pengguna = new add_pengguna(this);
  add_pengguna *Add_pengguna= new add_pengguna();
  Add_pengguna->show();

}


void pengguna::on_tblPengguna_clicked(const QModelIndex &index)
{

   int row = index.row();
   QString nip = index.sibling(row, 0).data().toString();
   QString nama = index.sibling(row, 1).data().toString();
   QString status = index.sibling(row, 3).data().toString();
   int tingkat_akses = index.sibling(row, 4).data().toInt();
   Add_pengguna = new add_pengguna(this);
   add_pengguna *Add_pengguna= new add_pengguna();
   Add_pengguna->setId(nip,nama,status,tingkat_akses);
   Add_pengguna->show();


}
