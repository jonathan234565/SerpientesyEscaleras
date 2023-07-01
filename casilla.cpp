#include "casilla.h"

Casilla::Casilla()
{
}

void Casilla::set_num_casilla(int _valor){
    valor_casilla = _valor;
}

void Casilla::set_fila(int _fila){
    fila = _fila;
}

void Casilla::set_columna(int _columna){
    columna = _columna;
}

void Casilla::set_tipo(QString _tipo){
    tipo = _tipo;
}

void Casilla::set_ptr_casilla_grafica(QGraphicsRectItem* _item){
    ptr_casilla_grafica = _item;
}

QGraphicsRectItem* Casilla::get_ptr_casilla_grafica(){
    return ptr_casilla_grafica;
}

int Casilla::get_num_casilla() const{
    return valor_casilla;
}

int Casilla::get_fila() const{
    return fila;
}

int Casilla::get_columna() const{
    return columna;
}

QString Casilla::get_tipo() const{
    return tipo;
}
