#ifndef WINDIALOG_H
#define WINDIALOG_H

#include <QDialog>

namespace Ui {
    class WinDialog;
}

class WinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinDialog(QWidget *parent = 0);
    ~WinDialog();
    void setTexto(QString texto);
private:
    Ui::WinDialog *ui;



signals:
    void responder(const QString &);

protected:
        void closeEvent(QCloseEvent *e);

private slots:
    void on_pushButton_clicked();
};

#endif // WINDIALOG_H
