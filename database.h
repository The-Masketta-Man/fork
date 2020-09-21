#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QVector>
#include <QString>
#include <stdlib.h>
struct Team{
    int id;
    QString name;
};
struct Bookmaker{
    int id;
    QString name;
};
class Database
{
public:
    Database(QString type, QString host, int port, QString user, QString pass, QString database);
    QStringList getTables();
    QStringList getFields(QString table);

    QVector<Team> getTeamF();
    QVector<Team> getTeamT();
    QVector<Bookmaker> getBookmaker();
private:

    QSqlDatabase db;
};
#endif // DATABASE_H
