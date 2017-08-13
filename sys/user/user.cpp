#include "user.h"
#include <sys/databaseconfig/databaseconfig.h>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QDebug>
#include <QMessageBox>
User::User()
{
}

bool User::chekLogin(QString user, QString password){

    QSqlQuery queryLogin, idUser,idUsers;
    bool ret=false;
    QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(password.toLatin1());
        QString hasPwd = hash.result().toHex();

    if(queryLogin.exec("SELECT * FROM master_pengguna WHERE nama_pengguna=\'"+user+"\' AND kata_kunci=\'"+hasPwd+"\' ")){

        int count=0;
        while(queryLogin.next()){
            userId = queryLogin.value("nip").toString();
            count++;
        }

        if(count==1){

//            if(idUser.exec("SELECT nip FROM master_pengguna WHERE nama_pengguna=\""+user+"\" AND kata_kunci=\""+hasPwd+"\"")){

//                while (idUser.next()) {
//                    userId = idUser.value("nip").toString();

//                }
//            }

            ret = true;
        }else{
            ret = false;
        }

    }else{
        qDebug()<< "User SQL Query : "<<queryLogin.lastError();
    }
    return ret;
}

QString User::getId(){
    return userId;
}

User::~User(){
}
