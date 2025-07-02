/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLineEdit *emailLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *nombreLineEdit;
    QLineEdit *usuarioLineEdit;
    QDateEdit *fechaNacimientoEdit;
    QComboBox *generoComboBox;
    QPushButton *registerConfirmButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(400, 300);
        emailLineEdit = new QLineEdit(RegisterWindow);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(30, 40, 113, 24));
        passwordLineEdit = new QLineEdit(RegisterWindow);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(30, 90, 113, 24));
        nombreLineEdit = new QLineEdit(RegisterWindow);
        nombreLineEdit->setObjectName("nombreLineEdit");
        nombreLineEdit->setGeometry(QRect(30, 150, 113, 24));
        usuarioLineEdit = new QLineEdit(RegisterWindow);
        usuarioLineEdit->setObjectName("usuarioLineEdit");
        usuarioLineEdit->setGeometry(QRect(30, 210, 113, 24));
        fechaNacimientoEdit = new QDateEdit(RegisterWindow);
        fechaNacimientoEdit->setObjectName("fechaNacimientoEdit");
        fechaNacimientoEdit->setGeometry(QRect(220, 40, 110, 25));
        generoComboBox = new QComboBox(RegisterWindow);
        generoComboBox->addItem(QString());
        generoComboBox->addItem(QString());
        generoComboBox->addItem(QString());
        generoComboBox->setObjectName("generoComboBox");
        generoComboBox->setGeometry(QRect(220, 100, 65, 24));
        registerConfirmButton = new QPushButton(RegisterWindow);
        registerConfirmButton->setObjectName("registerConfirmButton");
        registerConfirmButton->setGeometry(QRect(310, 270, 80, 24));
        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 49, 16));
        label_2 = new QLabel(RegisterWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 70, 61, 16));
        label_3 = new QLabel(RegisterWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 130, 61, 16));
        label_4 = new QLabel(RegisterWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 190, 61, 16));
        label_5 = new QLabel(RegisterWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(220, 20, 49, 16));
        label_6 = new QLabel(RegisterWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(220, 80, 49, 16));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        generoComboBox->setItemText(0, QCoreApplication::translate("RegisterWindow", "Man", nullptr));
        generoComboBox->setItemText(1, QCoreApplication::translate("RegisterWindow", "Women", nullptr));
        generoComboBox->setItemText(2, QCoreApplication::translate("RegisterWindow", "Other", nullptr));

        registerConfirmButton->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "Email:", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "Name:", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", "User:", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterWindow", "Birth:", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterWindow", "Gender:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
