#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlDatabase>
#include <QtGui/QApplication>
#include <QMessageBox>
#include <QDesktopServices>
#include <QDir>
#include <QVariant>

struct jugador
{
int id;
QString nombre;
};

struct nivel
{
int id;
int nivel;
int puntaje;
};

// dbConection;
static bool createConection()
{
    QString dataDir= QDesktopServices::storageLocation(QDesktopServices::DataLocation);
    QDir dir(dataDir);

    QString dbName= dir.filePath("Aplication.sqlite");

  QSqlDatabase dbConection= QSqlDatabase::addDatabase("QSQLITE");
    dbConection.setDatabaseName(dbName);

    if (!dbConection.open()) {
       QMessageBox::critical(0, qApp->tr("Error al abrir la Agenda"),
       qApp->tr("Ha sido imposible abrir los contactos de la Agenda"),
       QMessageBox::Ok);
       return false;
     }
    //CrearTablas();
    return true;
}
static bool CrearTablas(){
  //  createConection();
    //Crea la tabla Jugador
     QSqlQuery query;
     bool a1,a2,a3;
  a1=   query.exec("create table if not exists Jugador "
                      "(id integer primary key  autoincrement, "
                      "Nombre varchar(50)unique null )");
        query.finish();

     QSqlQuery query2;

     a2=query2.exec("create table if not exists Niveles "
                "(id integer,nivel integer,puntaje integer) ");

     a3=query2.exec( "CREATE UNIQUE INDEX [IDX_NIVELES_ID] ON [Niveles]("
                "[id]  DESC,"
                "[nivel]  DESC"
                ")");


//dbConection.close();
     return true;

}
static bool CrearPerfil(QString nombre)
{
    createConection();
    QString data = "insert into jugador (id,nombre)values(null,""'"+nombre+"'"")";
    QSqlQuery R;
   bool ret= R.exec(data);
    //dbConection.close();
    return ret;
}



static QList<QString> SelectAllJugadoresL()
{
   createConection();
    QList <QString> lista;
    QSqlQuery R("      select  nombre  from("
            "select id,nombre  from jugador"
            " ) ORDER BY ID desc limit 6");

            while(R.next())
            {

               QString nombre = R.value(0).toString();
                    lista.push_back(nombre);
            }

            return lista;
}
/*
static QList<nivel> SelectAllNiveles()
{
   createConection();
    QList <nivel> lista;
    QSqlQuery R("select id,nivel,puntaje from niveles");

            while(R.next())
            {
                nivel jj;

                jj.id=R.value(0).toInt();
                jj.nivel=R.value(1).toInt();
                jj.puntaje=R.value(2).toInt();

                    lista.push_back(jj);
            }
//dbConection.close();
            return lista;
}
static QString NombreJugador(int id)
{
    createConection();
      QString Q;
      Q="select nombre from jugador where id=";
      Q.append(id+48);

bool a;
        QSqlQuery R(Q);
      a=R.exec();
      R.next();
      QString name = R.value(0).toString();

      dbConection.close();
      return name;
  }
static bool CrearPerfil(QString nombre)
{
    createConection();
    QString data = "insert into jugador (id,nombre)values(null,""'"+nombre+"'"")";
    QSqlQuery R;
   bool ret= R.exec(data);
    dbConection.close();
    return ret;
}


*/
static QSqlQueryModel* SelectAllJugadores()
{
    QSqlQueryModel *R= new QSqlQueryModel();
    R->setQuery("select id,nombre from jugador");
    return R;

}





#endif // DBCONNECTION_H
