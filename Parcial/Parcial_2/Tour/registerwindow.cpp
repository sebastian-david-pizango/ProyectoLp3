#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>  // Para imprimir en consola

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    // Conecta el botón registrar por si Qt Creator no lo hace solo
    connect(ui->registerConfirmButton, &QPushButton::clicked,
            this, &RegisterWindow::on_registerConfirmButton_clicked);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerConfirmButton_clicked()
{
    qDebug() << "Se presionó registrar";  // Verifica si entra aquí

    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Correo y contraseña son obligatorios.");
        return;
    }

    // --- OPCIONALES ---
    QString nombre = ui->nombreLineEdit->text();
    QString username = ui->usuarioLineEdit->text();
    QString fechaNacimiento = ui->fechaNacimientoEdit->text();
    QString genero = ui->generoComboBox->currentText();

    // --- CREACIÓN DE ARCHIVO ---
    QFile file("usuarios.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo crear el archivo de usuarios.");
        return;
    }

    QTextStream out(&file);
    out << email << "," << password << "," << nombre << "," << username << "," << fechaNacimiento << "," << genero << "\n";
    file.close();

    QMessageBox::information(this, "Registro", "Usuario registrado correctamente.");

    // Imprime que se registró
    qDebug() << "Usuario guardado: " << email << "," << password;

    accept();  // Cierra la ventana
}

