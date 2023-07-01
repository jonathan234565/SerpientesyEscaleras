#ifndef JUGADOR_H
#define JUGADOR_H
#include <QPair>
#include <QString>

class Jugador
{
public:
    Jugador();

    void set_nombre(QString _nombre);
    void set_nueva_posicion(QPair<int,int> _nueva_posicion);
    void set_nuevo_puntaje(int _puntaje);

    QString get_nombre()const;
    int get_puntaje() const;
    QPair<int,int> get_posicion() const;
    int get_fila() const;
    int get_columna() const;

private:
    QString nombre;
    QPair<int,int> posicion;
    int puntaje;
};

#endif // JUGADOR_H
