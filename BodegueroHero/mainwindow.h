#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;

private slots:
    void on_cmdStart_clicked();
    void on_btnBackFromP4_clicked();
    void on_btBack_clicked();
    void on_btJugar_clicked();
    void on_btCrear_clicked();
    void on_btSeleccionar_clicked();
};

#endif // MAINWINDOW_H
