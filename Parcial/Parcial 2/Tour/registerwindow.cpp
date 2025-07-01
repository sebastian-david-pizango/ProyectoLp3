#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerButton_clicked()
{
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString dob = ui->dobDateEdit->date().toString("yyyy-MM-dd");
    QString gender = ui->genderComboBox->currentText();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "El correo y la contraseña son obligatorios.");
        return;
    }

    QFile checkFile("usuarios.txt");
    if (checkFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&checkFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList datos = line.split(",");
            if (!datos.isEmpty() && datos[0] == email) {
                QMessageBox::warning(this, "Error", "Este correo ya está registrado.");
                return;
            }
        }
        checkFile.close();
    }

    QFile file("usuarios.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        return;
    }

    QTextStream out(&file);
    out << email << "," << password << "," << name << "," << username << "," << dob << "," << gender << "\n";
    file.close();

    QMessageBox::information(this, "Registro", "Usuario registrado con éxito.");
    this->close();
}

