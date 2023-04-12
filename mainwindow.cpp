#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    msgBoxIncluir.setWindowTitle("ERRO");
    msgBoxIncluir.setText("Insira apenas inteiros!");
    msgBoxIncluir.setIcon(QMessageBox::Warning);
    msgBoxIncluir.setStyleSheet("QMessageBox{background-color: rgb(30, 37, 40);}" "QLabel{color: white;}");

    ui->pushButtonIncluir->setIcon(QIcon(":/icons/Icons/incluir1.png"));
    ui->pushButtonIncluirFim->setIcon(QIcon(":/icons/Icons/incluir1.png"));
    ui->pushButtonAcessar->setIcon(QIcon(":/icons/Icons/acessar1.png"));
    ui->pushButtonAcessarFim->setIcon(QIcon(":/icons/Icons/acessar1.png"));
    ui->pushButtonRetirar->setIcon(QIcon(":/icons/Icons/retirar1.png"));
    ui->pushButtonRetirarFim->setIcon(QIcon(":/icons/Icons/retirar1.png"));
    ui->pushButtonAcessarPos->setIcon(QIcon(":/icons/Icons/acessar1.png"));
    ui->pushButtonRetirarPos->setIcon(QIcon(":/icons/Icons/retirar1.png"));
    ui->pushButtonIncluirPos->setIcon(QIcon(":/icons/Icons/incluir1.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonIncluir_clicked()
{
    QString teste = ui->lineEditValor->text();
    bool ok;
    int valor = teste.toInt(&ok);
    if(ok)
    {
        llse.inserirInicio(valor);
        ui->lineEditValor->clear();
        ui->textEditSaida->setText(llse.obterDadosLLSE());
        ui->lineEditQE->setText(QString::number(llse.getQuantidadeDeElementos()));
    }
    else
    {
        msgBoxIncluir.exec();
        ui->lineEditValor->clear();
    }
    int QE = llse.getQuantidadeDeElementos();
    ui->spinBox->setMaximum(QE);
}

void MainWindow::on_pushButtonAcessar_clicked()
{
    try
    {
        if(llse.estaVazia()) throw QString("A lista está vazia!");
        QString saida = QString::number(llse.acessarInicio());
        ui->lineEditValor->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }

}

void MainWindow::on_pushButtonRetirar_clicked()
{
    try
    {
        if(llse.estaVazia()) throw QString("A lista já esta vazia!");
        QString saida = QString::number(llse.retirarInicio());
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(llse.obterDadosLLSE());
        ui->lineEditQE->setText(QString::number(llse.getQuantidadeDeElementos()));
        int QE = llse.getQuantidadeDeElementos();
        ui->spinBox->setMaximum(QE);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAcessarFim_clicked()
{
    try
    {
        if(llse.estaVazia()) throw QString("A lista está vazia!");
        QString saida = QString::number(llse.acessarFim());
        ui->lineEditValor->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonIncluirFim_clicked()
{
    QString teste = ui->lineEditValor->text();
    bool ok;
    int valor = teste.toInt(&ok);
    if(ok)
    {
        llse.inserirFim(valor);
        ui->lineEditValor->clear();
        ui->textEditSaida->setText(llse.obterDadosLLSE());
        ui->lineEditQE->setText(QString::number(llse.getQuantidadeDeElementos()));
    }
    else
    {
        msgBoxIncluir.exec();
        ui->lineEditValor->clear();
    }
    int QE = llse.getQuantidadeDeElementos();
    ui->spinBox->setMaximum(QE);
}


void MainWindow::on_pushButtonRetirarFim_clicked()
{
    try {
        if(llse.estaVazia()) throw QString("A lista já esta vazia!");
        QString saida = QString::number(llse.retirarFim());
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(llse.obterDadosLLSE());
        ui->lineEditQE->setText(QString::number(llse.getQuantidadeDeElementos()));
        int QE = llse.getQuantidadeDeElementos();
        ui->spinBox->setMaximum(QE);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonAcessarPos_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        if(llse.estaVazia()) throw QString("A lista esta vazia!");
        QString saida = QString::number(llse.acessarPosicao(posicao));
        ui->lineEditValor->setText(saida);

    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonIncluirPos_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
            llse.inserirPosicao(valor, posicao);
            ui->lineEditValor->clear();
            ui->textEditSaida->setText(llse.obterDadosLLSE());
            ui->lineEditQE->setText(QString::number(llse.getQuantidadeDeElementos()));
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }
        int QE = llse.getQuantidadeDeElementos();
        ui->spinBox->setMaximum(QE);

    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonRetirarPos_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        if(llse.estaVazia()) throw QString("A lista já esta vazia!");
        QString saida = QString::number(llse.retirarPosicao(posicao));

        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(llse.obterDadosLLSE());
        ui->lineEditQE->setText(QString::number(llse.getQuantidadeDeElementos()));

        int QE = llse.getQuantidadeDeElementos();
        ui->spinBox->setMaximum(QE);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}

