#ifndef NO_H
#define NO_H

namespace ce{
class No
{
private:
    int dado;
    No* proximo;
public:
    No();
    No(int dado);
    int getDado() const;
    void setDado(int newDado);
    No *getProximo() const;
    void setProximo(No *newProximo);
};
}
#endif // NO_H
