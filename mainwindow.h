#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <llse.h>
#include <no.h>
#include <QMainWindow>
#include <QPixmap>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonIncluir_clicked();

    void on_pushButtonAcessar_clicked();

    void on_pushButtonRetirar_clicked();

    void on_pushButtonAcessarFim_clicked();

    void on_pushButtonIncluirFim_clicked();

    void on_pushButtonRetirarFim_clicked();

    void on_pushButtonAcessarPos_clicked();

    void on_pushButtonIncluirPos_clicked();

    void on_pushButtonRetirarPos_clicked();

private:
    Ui::MainWindow *ui;
    ce::LLSE llse;
    QMessageBox msgBoxIncluir;
    QMessageBox msgBoxAcessar;
};
#endif // MAINWINDOW_H
