#ifndef DADO_H
#define DADO_H


class Dado
{
public:
    Dado();

    int generar_aleatorio();
    int tirar_dado();
    int get_num_dado();

private:
    int num;
};

#endif // DADO_H
