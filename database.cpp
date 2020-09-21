#include "database.h"

Database::Database(QString type, QString host, int port, QString user, QString pass, QString database) {
    db = QSqlDatabase::addDatabase(type);
    db.setHostName(host);
    db.setPort(port);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(pass);
    db.open();
};

QStringList Database::getTables()//импорт названий таблиц
{
    return db.tables();
}

QStringList Database::getFields(QString table)//импорт названий колонок
{
    QSqlRecord record = db.record(table);
    QStringList list;
    int count = record.count();
    for (int i = 0; i < count; i++) {
        list.push_back(record.fieldName(i));
    }
    return list;
}
QVector<Team> Database::getTeamF(){
    QSqlQuery query(db);
    query.exec("SELECT MAX(TEAM_ID) FROM TEAM_F");
    int max = query.value(0).toInt();
    QVector<Team> v;
    for(int i = 0;i < max;i++){
        QSqlQuery q(db);
        QString s = QString::number(i);
        q.exec("SELECT * FROM TEAM_T WHERE ID_TEAM_F="+s+";");
        i = s.toInt();
        v[i].id = q.value(0).toInt();
        v[i].name = q.value(1).toString();
    }
    return v;
}
QVector<Team> Database::getTeamT(){
    QSqlQuery query(db);
    query.exec("SELECT MAX(TEAM_ID) FROM TEAM_T");
    int max = query.value(0).toInt();
    QVector<Team> v;
    for(int i = 0;i < max;i++){
        QSqlQuery q(db);
        QString s = QString::number(i);
        q.exec("SELECT * FROM TEAM_T WHERE ID_TEAM_T="+s+";");
        i = s.toInt();
        v[i].id = q.value(0).toInt();
        v[i].name = q.value(1).toString();
    }
    return v;
}
QVector<Bookmaker> Database::getBookmaker(){
    QSqlQuery query(db);
    query.exec("SELECT MAX(ID_BOOKMAKER) FROM BOOKMAKER");
    int max = query.value(0).toInt();
    QVector<Bookmaker> v;
    for(int i = 0;i < max;i++){
        QSqlQuery q(db);
        QString s = QString::number(i);
        q.exec("SELECT * FROM BOOKMAKER WHERE ID_BOOKMAKER="+s+";");
        i = s.toInt();
        v[i].id = q.value(0).toInt();
        v[i].name = q.value(1).toString();
    }
    return v;
}
