#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dbConnection.h>
#include "QSignalMapper"
#include "QGridLayout"
#include <QMainWindow>
//MM: AGREGADO INCLUDE
#include "graphicsscenepreview.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int UsuariosDisponibles;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void cargarPerfil();
    QString CurrentUser;
    QString CurrentLevel;

private:
    Ui::MainWindow *ui;

private slots:
    void on_btnAvanzado_clicked();
    void on_btnTutorial_clicked();
    void on_btn_ir_CrearPerfil_clicked();
    void on_label_26_linkActivated(QString link);
    void on_btn_CrearPerfil_clicked();
    void on_actionBack_triggered();
    void on_actionHome_triggered();
    void on_cmdStart_clicked();
    void on_btJugar_clicked();
    void on_btCrear_clicked();
    void on_btSeleccionar_clicked();
    void on_pushButton_clicked();
    void recibir(const QString &);
signals:
void escribir(const QString &);
};

#endif // MAINWINDOW_H
