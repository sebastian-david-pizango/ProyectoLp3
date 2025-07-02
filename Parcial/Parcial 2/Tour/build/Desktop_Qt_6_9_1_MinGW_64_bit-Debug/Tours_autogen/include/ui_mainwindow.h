/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelUser;
    QLabel *labelPassword;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelUser = new QLabel(centralwidget);
        labelUser->setObjectName("labelUser");
        labelUser->setGeometry(QRect(230, 340, 49, 16));
        labelUser->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        labelPassword = new QLabel(centralwidget);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(230, 370, 49, 16));
        usernameLineEdit = new QLineEdit(centralwidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(310, 340, 113, 24));
        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(310, 370, 113, 24));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(440, 340, 80, 24));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(440, 370, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelUser->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
