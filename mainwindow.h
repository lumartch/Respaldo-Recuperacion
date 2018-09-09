#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_origenPB_clicked();

    void on_destinoPB_clicked();

    void on_respaldoBB_accepted();

    void on_respaldoBB_rejected();

    void on_recuperarBB_accepted();

    void on_origenPB_2_clicked();

    void on_recuperarBB_rejected();

private:
    Ui::MainWindow *ui;
    QString origenBackup;
    QString destinoBackup;
    QString origenRecovery;
};

#endif // MAINWINDOW_H
