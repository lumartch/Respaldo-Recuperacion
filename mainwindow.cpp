#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->origenLE->setDisabled(true);
    ui->origenLE_2->setDisabled(true);
    ui->destinoLE->setDisabled(true);
    ui->notaLabel->setText("Nota:\nTodo archivo recuperado\n"
                           "sera guardado en el directorio\n"
                           "'/home/lumartch/Documentos/recovery'.\n"
                           "Todos los archivos previos de este\n"
                           "directorio seran eliminados.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_origenPB_clicked()
{
    origenBackup = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    ui->origenLE->setText(origenBackup);
}

void MainWindow::on_destinoPB_clicked()
{
    destinoBackup = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/run/media/lumartch/",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    ui->destinoLE->setText(destinoBackup);
}

void MainWindow::on_respaldoBB_accepted()
{
    if(ui->origenLE->text().size() != 0 and ui->destinoLE->text().size() != 0){
        //Crear directorio destino
        QString mkdir = "mkdir " + destinoBackup + "/backup";
        QByteArray toChar = mkdir.toLatin1();
        const char *c_str1 = toChar.data();
        system(c_str1);
        //Copiar archivos
        QString copiado = "cp -a " + origenBackup + "/. " + destinoBackup + "/backup/";
        toChar = copiado.toLatin1();
        const char *c_str2 = toChar.data();
        system(c_str2);
        //Muestra de mensaje
        QMessageBox msgBox;
        msgBox.setText("¡Información respaldada exitosamente!\n" + QString(c_str1));
        msgBox.exec();
        ui->destinoLE->setText("");
        ui->origenLE->setText("");
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Debe existir un origen y destino para el respaldo.");
        msgBox.exec();
    }
}

void MainWindow::on_respaldoBB_rejected()
{
    ui->destinoLE->setText("");
    ui->origenLE->setText("");
}

void MainWindow::on_recuperarBB_accepted()
{
    if(ui->origenLE_2->text().size() != 0){
        system("rm -rf /home/lumartch/Documentos/recovery");
        system("mkdir /home/lumartch/Documentos/recovery");
        QString copiado = "cp -a " + origenRecovery + "/. /home/lumartch/Documentos/recovery/";
        QByteArray toChar = copiado.toLatin1();
        const char *c_str2 = toChar.data();
        system(c_str2);
        QMessageBox msgBox;
        msgBox.setText("¡Información recuperada exitosamente!\n");
        msgBox.exec();
        ui->origenLE_2->setText("");
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Debe existir un origen para recuperar información.");
        msgBox.exec();
    }
}

void MainWindow::on_origenPB_2_clicked()
{
    origenRecovery = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    ui->origenLE_2->setText(origenRecovery);
}

void MainWindow::on_recuperarBB_rejected()
{
    ui->origenLE_2->setText("");
}
