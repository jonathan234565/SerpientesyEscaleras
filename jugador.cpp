#include "jugador.h"

Jugador::Jugador()
{

}
void Jugador::set_nombre(QString _nombre){
    nombre = _nombre;
}

void Jugador::set_nuevo_puntaje(int _puntaje){
    puntaje=_puntaje;
}

void Jugador::set_nueva_posicion(QPair<int,int> _nueva_posicion){
    posicion = _nueva_posicion;
}


QString Jugador::get_nombre() const{
    return nombre;
}

int Jugador::get_puntaje() const{
    return puntaje;
}

QPair<int,int> Jugador::get_posicion() const{
    return posicion;
}

int Jugador::get_fila() const{
    return posicion.first;
}

int Jugador::get_columna() const{
    return posicion.second;
}
