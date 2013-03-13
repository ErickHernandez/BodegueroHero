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

struct score
{
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

    if (!dbConection.open())
    {
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
                "(id integer,Nombre varchar(50),nivel integer,puntaje integer) ");

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

static QList<score> getScores(QString nombre, int level)
{
    QList<score> listadePuntos;

    if(level==0)
    {
        QSqlQuery R("select nivel,puntaje from niveles where  nombre=""'"+nombre+"' and nivel<6");
        while(R.next()){
            score pt;

            pt.nivel=R.value(0).toInt();
            pt.puntaje=R.value(1).toInt();

            listadePuntos.push_back(pt);
        }
    }
    else
    {
        QSqlQuery R("select nivel,puntaje from niveles where nombre='"+nombre+"' and nivel>5");
        while(R.next()){
            score pt;

            pt.nivel=R.value(0).toInt();
            pt.puntaje=R.value(1).toInt();

            listadePuntos.push_back(pt);


        }

    }

    return listadePuntos;
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
*/

static int idJugador(QString nombre)
{
      QString Q;
      Q="select id from jugador where nombre=""'"+nombre+"'""";
//      Q.append(nombre);

        bool a;
        QSqlQuery R(Q);
      a=R.exec();
      R.next();
      int id = R.value(0).toInt();


      return id;
  }



static QString NombreJugador(int id)
{
      QString Q;
      Q="select nombre from jugador where id=";
      Q.append(id+48);

        bool a;
        QSqlQuery R(Q);
      a=R.exec();
      R.next();
      QString name = R.value(0).toString();


      return name;
  }

    static QSqlQueryModel* SelectTop5(int id)
{
    QSqlQueryModel *R= new QSqlQueryModel();
    QString que="select nombre,puntaje from niveles where nivel="+QString::number(id);
    que.append( " ORDER BY puntaje asc limit 5");
    R->setQuery(que);
    return R;

}


    static bool actualizar_puntos(QString nombre,int puntos,int nivel)
    {
            QString Q;
            Q="Select nombre,puntaje from niveles where nombre=""'"+nombre+"' and nivel="+QString::number(nivel)+"" ;

            QSqlQuery R(Q);
            bool a = R.exec();
            R.next();
            QString name =R.value(0).toString();
            int ptsH = R.value(1).toInt();
            int id = idJugador(nombre);
            QString id2,pnts,nivl;
            pnts.setNum(puntos);
            nivl.setNum(nivel);
            id2.setNum(id);

            if(name.isEmpty() )
            {
                Q="insert into niveles(id,nombre,nivel,puntaje)values("+ id2 +",'"+ nombre +"',"+ nivl +","+ pnts +")";
                QSqlQuery R2(Q);
                bool a= R2.exec();
                return a;
            }else
            {
                if(ptsH>puntos){
                    Q="update niveles set nombre='"+nombre+"',nivel="+nivl+",puntaje="+pnts+" where id="+id2;
                    QSqlQuery R2(Q);
                    bool a= R2.exec();
                    return a;
                }
            }

    }

    static bool yaexiste(QString name)
    {

        QString Q="Select * from Jugador where nombre=""'"+name+"'";

        QSqlQuery R(Q);
        bool a = R.exec();
        R.next();
        if(!R.value(0).isNull())
        {
            return false;
        }
       return true;
    }



#endif // DBCONNECTION_H
