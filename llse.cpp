#include "llse.h"

namespace ce{

bool LLSE::estaVazia()const
{
    return (quantidadeDeElementos == 0);
}
int LLSE::getQuantidadeDeElementos() const
{
    return quantidadeDeElementos;
}

LLSE::LLSE():
    quantidadeDeElementos(0),
    inicio(0)
{
}

void LLSE::inserirInicio(int elemento)
{
    try {
        No *aux = new No(elemento);
        quantidadeDeElementos++;
        aux->setProximo(inicio);
        inicio = aux;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nó não foi criado!");
    }
}

int LLSE::retirarInicio()
{
    if(estaVazia()) throw QString("A lista está vazia!");
    No* aux = inicio;
    inicio = aux->getProximo();
    int valor = aux->getDado();
    delete aux;
    quantidadeDeElementos--;
    return valor;
}

int LLSE::acessarInicio()const
{
    if(estaVazia()) throw QString("A lista esta vazia!");
    return inicio->getDado();

}

void LLSE::inserirFim(int elemento)
{
    try {
        No *novo = new No(elemento);
        if(estaVazia()){
            inicio = novo;
        }
        else{
            No *aux = inicio;
           while(aux->getProximo() != NULL)
            {
                aux = aux->getProximo();
            }
            aux->setProximo(novo);
        }
        quantidadeDeElementos++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nó não foi criado!");
    }
}
int LLSE::retirarFim()
{
    if(estaVazia()) throw QString("A lissta está vazia!");
    if(quantidadeDeElementos==1)
    {
        int valor = inicio->getDado();
        delete inicio;
        inicio=nullptr;
        return valor;
    }
    No *aux = inicio;
    while(aux->getProximo()->getProximo() != nullptr)
    {
        aux=aux->getProximo();
    }
    int valor = aux->getProximo()->getDado();
    delete aux->getProximo();
    aux->setProximo(nullptr);
    quantidadeDeElementos--;
    return valor;

}

int LLSE::acessarFim()const
{
    if(estaVazia()) throw QString("A lista esta vazia!");
    No *aux = inicio;
    for(int pos=0;pos<quantidadeDeElementos-1; pos++)
    {
        aux = aux->getProximo();
    }
    return aux->getDado();
}

void LLSE::inserirPosicao(int elemento, int posicao)
{
    try {
        if(posicao < 0 || posicao > quantidadeDeElementos) throw QString("A posição desejada não existe");
        if(posicao == 0) return inserirInicio(elemento);
        if(posicao == quantidadeDeElementos) return inserirFim(elemento);

        No *aux = new No(elemento);
        No *anterior = inicio;

        for(int pos = 0; pos < posicao - 1; pos++)
        {
            anterior = anterior->getProximo();
        }

        aux->setProximo(anterior->getProximo());
        anterior->setProximo(aux);
        quantidadeDeElementos++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nó não foi criado!");
    }

}

int LLSE::retirarPosicao(int posicao)
{
    if(estaVazia()) throw QString("A lista está vazia!");
    if(posicao < 0 || posicao >= quantidadeDeElementos) throw QString("A posição desejada não existe");
    if(posicao == 0) return retirarInicio();
    if(posicao == quantidadeDeElementos - 1) return retirarFim();

    No *aux = inicio;
    No *anterior = nullptr;

    for(int pos = 0; pos < posicao; pos++)
    {
        anterior = aux;
        aux = aux->getProximo();
    }
    anterior->setProximo(aux->getProximo());
    int valor = aux->getDado();
    delete aux;
    quantidadeDeElementos--;

    return valor;
}
int LLSE::acessarPosicao(int posicao)const
{
    if(estaVazia()) throw QString("A lista está vazia!");
    if(posicao < 0 || posicao >= quantidadeDeElementos) throw QString("A posição desejada não existe");
    if(posicao == 0) return acessarInicio();
    if(posicao == quantidadeDeElementos - 1) return acessarFim();
    No *aux = inicio;
    for(int pos = 0; pos < posicao; pos++)
    {
        aux = aux->getProximo();
    }
    return aux->getDado();
}

QString LLSE::obterDadosLLSE()const
{
    No* aux = inicio;
    QString saida;
    if (estaVazia())
    {
        return saida;
    }
    saida += "|";
    for (int pos = 0; pos < quantidadeDeElementos; pos++)
    {
        saida += QString::number(aux->getDado());
        if (pos < quantidadeDeElementos - 1)
        {
            saida += "|->|";
        }
        aux = aux->getProximo();
    }
    saida += "|";
    return saida;
}

}
