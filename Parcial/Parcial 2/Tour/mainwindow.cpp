#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "registerwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString email = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    QFile file("usuarios.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo de usuarios.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList datos = line.split(",");
        if (datos.size() >= 2 && datos[0] == email && datos[1] == password) {
            QMessageBox::information(this, "Login", "Inicio de sesión exitoso.");
            return;
        }
    }

    QMessageBox::warning(this, "Login", "Correo o contraseña incorrectos.");
}

void MainWindow::on_registerButton_clicked()
{
    RegisterWindow *reg = new RegisterWindow(this);
    reg->exec();
}

