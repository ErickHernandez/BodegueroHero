/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 3. Feb 01:59:35 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *screenManager;
    QWidget *page;
    QPushButton *cmdStart;
    QWidget *page_2;
    QPushButton *btSeleccionar;
    QPushButton *btCrear;
    QPushButton *btJugar;
    QPushButton *btBack;
    QWidget *page_21;
    QFrame *frame_3;
    QGroupBox *groupBox;
    QPushButton *player1;
    QPushButton *player2;
    QPushButton *player3;
    QPushButton *player4;
    QPushButton *player5;
    QGroupBox *groupBox_2;
    QTextEdit *NewPlayer;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *page_3;
    QFrame *frame_4;
    QGroupBox *groupBox_4;
    QTextEdit *CrearNuevoPerfil_txt;
    QLabel *label_2;
    QPushButton *CrearNuevoPerfil_btn;
    QWidget *page_4;
    QFrame *frame_2;
    QLabel *lblDificultadTexto;
    QPushButton *btnTutorial;
    QPushButton *btnAvanzado;
    QPushButton *btnBackFromP4;
    QWidget *page_5;
    QWidget *page_6;
    QWidget *page_7;
    QWidget *page_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(998, 585);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Tenaza_Cerrada.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        screenManager = new QStackedWidget(centralWidget);
        screenManager->setObjectName(QString::fromUtf8("screenManager"));
        screenManager->setGeometry(QRect(0, 0, 1001, 551));
        screenManager->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        cmdStart = new QPushButton(page);
        cmdStart->setObjectName(QString::fromUtf8("cmdStart"));
        cmdStart->setGeometry(QRect(0, -10, 1001, 551));
        screenManager->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/background.png);"));
        btSeleccionar = new QPushButton(page_2);
        btSeleccionar->setObjectName(QString::fromUtf8("btSeleccionar"));
        btSeleccionar->setGeometry(QRect(375, 77, 250, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("Showcard Gothic"));
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        btSeleccionar->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Caja1.png"), QSize(), QIcon::Normal, QIcon::Off);
        btSeleccionar->setIcon(icon1);
        btSeleccionar->setIconSize(QSize(16, 16));
        btCrear = new QPushButton(page_2);
        btCrear->setObjectName(QString::fromUtf8("btCrear"));
        btCrear->setGeometry(QRect(375, 234, 250, 80));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Showcard Gothic"));
        font1.setBold(true);
        font1.setWeight(75);
        btCrear->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Centro de Mando.png"), QSize(), QIcon::Normal, QIcon::Off);
        btCrear->setIcon(icon2);
        btJugar = new QPushButton(page_2);
        btJugar->setObjectName(QString::fromUtf8("btJugar"));
        btJugar->setGeometry(QRect(375, 391, 250, 80));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Showcard Gothic"));
        btJugar->setFont(font2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Tenaza_Cerrada.png"), QSize(), QIcon::Selected, QIcon::On);
        btJugar->setIcon(icon3);
        btJugar->setAutoRepeat(false);
        btBack = new QPushButton(page_2);
        btBack->setObjectName(QString::fromUtf8("btBack"));
        btBack->setGeometry(QRect(70, 40, 91, 81));
        QFont font3;
        font3.setPointSize(20);
        btBack->setFont(font3);
        btBack->setStyleSheet(QString::fromUtf8(""));
        screenManager->addWidget(page_2);
        page_21 = new QWidget();
        page_21->setObjectName(QString::fromUtf8("page_21"));
        frame_3 = new QFrame(page_21);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 0, 991, 551));
        frame_3->setStyleSheet(QString::fromUtf8("background-image: url(:/images/background.png);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(220, 40, 511, 241));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        groupBox->setPalette(palette);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Terminal"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        groupBox->setFont(font4);
        player1 = new QPushButton(groupBox);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setGeometry(QRect(50, 60, 101, 41));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        player1->setPalette(palette1);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Terminal"));
        font5.setPointSize(12);
        player1->setFont(font5);
        player2 = new QPushButton(groupBox);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setGeometry(QRect(50, 140, 101, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        player2->setPalette(palette2);
        player2->setFont(font5);
        player3 = new QPushButton(groupBox);
        player3->setObjectName(QString::fromUtf8("player3"));
        player3->setGeometry(QRect(210, 100, 101, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        player3->setPalette(palette3);
        player3->setFont(font5);
        player4 = new QPushButton(groupBox);
        player4->setObjectName(QString::fromUtf8("player4"));
        player4->setGeometry(QRect(370, 60, 101, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        player4->setPalette(palette4);
        player4->setFont(font5);
        player5 = new QPushButton(groupBox);
        player5->setObjectName(QString::fromUtf8("player5"));
        player5->setGeometry(QRect(370, 140, 101, 41));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        player5->setPalette(palette5);
        player5->setFont(font5);
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 320, 511, 201));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        groupBox_2->setPalette(palette6);
        groupBox_2->setFont(font4);
        NewPlayer = new QTextEdit(groupBox_2);
        NewPlayer->setObjectName(QString::fromUtf8("NewPlayer"));
        NewPlayer->setGeometry(QRect(210, 70, 181, 51));
        QFont font6;
        font6.setPointSize(12);
        NewPlayer->setFont(font6);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 141, 41));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush3(QColor(255, 255, 220, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        label->setPalette(palette7);
        QFont font7;
        font7.setFamily(QString::fromUtf8("Terminal"));
        font7.setPointSize(18);
        label->setFont(font7);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Raised);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 140, 101, 41));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton->setPalette(palette8);
        pushButton->setFont(font5);
        screenManager->addWidget(page_21);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        frame_4 = new QFrame(page_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(-10, -10, 1011, 551));
        frame_4->setStyleSheet(QString::fromUtf8("background-image: url(:/images/background.png);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        groupBox_4 = new QGroupBox(frame_4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(260, 130, 511, 321));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        groupBox_4->setPalette(palette9);
        groupBox_4->setFont(font4);
        CrearNuevoPerfil_txt = new QTextEdit(groupBox_4);
        CrearNuevoPerfil_txt->setObjectName(QString::fromUtf8("CrearNuevoPerfil_txt"));
        CrearNuevoPerfil_txt->setGeometry(QRect(210, 120, 181, 51));
        CrearNuevoPerfil_txt->setFont(font6);
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 120, 141, 41));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        label_2->setPalette(palette10);
        label_2->setFont(font7);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        CrearNuevoPerfil_btn = new QPushButton(groupBox_4);
        CrearNuevoPerfil_btn->setObjectName(QString::fromUtf8("CrearNuevoPerfil_btn"));
        CrearNuevoPerfil_btn->setGeometry(QRect(210, 230, 101, 41));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        CrearNuevoPerfil_btn->setPalette(palette11);
        CrearNuevoPerfil_btn->setFont(font5);
        screenManager->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        frame_2 = new QFrame(page_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(-70, -10, 1000, 550));
        frame_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/background.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lblDificultadTexto = new QLabel(frame_2);
        lblDificultadTexto->setObjectName(QString::fromUtf8("lblDificultadTexto"));
        lblDificultadTexto->setGeometry(QRect(220, 40, 557, 69));
        lblDificultadTexto->setStyleSheet(QString::fromUtf8("background-image: url(:/images/dificultadesTexto.png);"));
        btnTutorial = new QPushButton(frame_2);
        btnTutorial->setObjectName(QString::fromUtf8("btnTutorial"));
        btnTutorial->setGeometry(QRect(40, 180, 400, 300));
        btnTutorial->setStyleSheet(QString::fromUtf8("background-image: url(:/images/tutorial.png);"));
        btnTutorial->setFlat(true);
        btnAvanzado = new QPushButton(frame_2);
        btnAvanzado->setObjectName(QString::fromUtf8("btnAvanzado"));
        btnAvanzado->setGeometry(QRect(560, 180, 400, 300));
        btnAvanzado->setStyleSheet(QString::fromUtf8("background-image: url(:/images/avanzado.png);"));
        btnAvanzado->setFlat(true);
        btnBackFromP4 = new QPushButton(frame_2);
        btnBackFromP4->setObjectName(QString::fromUtf8("btnBackFromP4"));
        btnBackFromP4->setGeometry(QRect(20, 20, 64, 64));
        btnBackFromP4->setStyleSheet(QString::fromUtf8("background-image: url(:/images/1_navigation_back.png);"));
        btnBackFromP4->setFlat(true);
        screenManager->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        screenManager->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        screenManager->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        screenManager->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        screenManager->addWidget(page_8);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 998, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setBaseSize(QSize(0, 0));
        mainToolBar->setAcceptDrops(false);
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        screenManager->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BodegueroHero", 0, QApplication::UnicodeUTF8));
        cmdStart->setText(QString());
        btSeleccionar->setText(QApplication::translate("MainWindow", "Seleccionar Perfil", 0, QApplication::UnicodeUTF8));
        btCrear->setText(QApplication::translate("MainWindow", "Crear Perfil", 0, QApplication::UnicodeUTF8));
        btJugar->setText(QApplication::translate("MainWindow", "Jugar", 0, QApplication::UnicodeUTF8));
        btBack->setText(QApplication::translate("MainWindow", "<-", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Selecciona tu Perfil", 0, QApplication::UnicodeUTF8));
        player1->setText(QString());
        player2->setText(QString());
        player3->setText(QString());
        player4->setText(QString());
        player5->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Crea un Nuevo Perfil", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Nombre", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Crear", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Crea un Nuevo Perfil", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Nombre", 0, QApplication::UnicodeUTF8));
        CrearNuevoPerfil_btn->setText(QApplication::translate("MainWindow", "Crear", 0, QApplication::UnicodeUTF8));
        lblDificultadTexto->setText(QString());
        btnTutorial->setText(QString());
        btnAvanzado->setText(QString());
        btnBackFromP4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
