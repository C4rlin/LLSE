#ifndef LLSE_H
#define LLSE_H
#include<no.h>
#include <QString>
#include <QMessageBox>

namespace ce{

class LLSE
{
private:
    int quantidadeDeElementos;
    No* inicio;
public:
    LLSE();
    QString obterDadosLLSE()const;
    int getQuantidadeDeElementos() const;
    bool estaVazia()const;
    void inserirInicio(int elemento);
    int acessarInicio()const;
    int retirarInicio();
    void inserirFim(int elemento);
    int acessarFim()const;
    int retirarFim();
    void inserirPosicao(int elemento, int posicao);
    int acessarPosicao(int posicao)const;
    int retirarPosicao(int posicao);
};
}
#endif // LLSE_H
