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
    void setText(QString texto);
    ~WinDialog();

private:
    Ui::WinDialog *ui;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_WinDialog_accepted();
};

#endif // WINDIALOG_H
