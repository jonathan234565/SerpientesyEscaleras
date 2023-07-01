#ifndef CASILLA_H
#define CASILLA_H
#include <QString>
#include<QGraphicsRectItem>

class Casilla
{
public:
    Casilla();

    void set_num_casilla(int _num);
    void set_fila(int _fila);
    void set_columna(int _columna);
    void set_tipo(QString _tipo);
    void set_ptr_casilla_grafica(QGraphicsRectItem* item);
    void crear_tablero_grafico();

    int get_num_casilla() const;
    int get_fila() const;
    int get_columna() const;
    QString get_tipo() const;
    QGraphicsRectItem* get_ptr_casilla_grafica();

private:
    int valor_casilla;
    int fila;
    int columna;
    QString tipo;
    QGraphicsRectItem* ptr_casilla_grafica;
    ///enum Tipo {Normal,Serpiente,Escalera};
};

#endif // CASILLA_H
