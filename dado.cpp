#include "dado.h"
#include <cstdlib>
#include <ctime>


Dado::Dado()
{
}

int Dado::generar_aleatorio(){
    srand(time(nullptr));
    num = (rand()%6)+1; ///rand me da un numero entre 0 y 5, se le suma 1 para que sea entre 1 y 6
    return num;
}

int Dado::get_num_dado(){
    return num;
}
