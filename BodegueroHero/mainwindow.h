#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dbConnection.h>
#include "QSignalMapper"
#include "QGridLayout"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void cargarPerfil();
    QString CurrentUser;

private:
    Ui::MainWindow *ui;

private slots:

    void on_btnBackFromP4_clicked();
    void on_btBack_clicked();
    void on_btJugar_clicked();
    void on_btCrear_clicked();
    void on_btSeleccionar_clicked();
    void on_pushButton_clicked();
    void recibir(const QString &);
signals:
void escribir(const QString &);
};

#endif // MAINWINDOW_H
