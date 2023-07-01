#ifndef SERPIENTESESCALERAS_H
#define SERPIENTESESCALERAS_H
#include "casilla.h"
#include "dado.h"
#include "dado1.h"
#include "jugador.h"
#include<QSet>
#include <QGraphicsRectItem>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SerpientesEscaleras; }
QT_END_NAMESPACE

class Dado1;

class SerpientesEscaleras : public QMainWindow
{
    Q_OBJECT

public:
    SerpientesEscaleras(QWidget *parent = nullptr);
    ~SerpientesEscaleras();

    void crear_tablero(QGraphicsScene* &scene, const int &altura_casilla,const int &ancho_casilla);
    void crear_serpientes_y_escaleras();
    QSet<QPair<int,int>> generar_aleatorio();
    int tirar_dado();


private slots:
    void on_pushButton_dado_clicked();
    QPair<int,int> nueva_posicion(QPair<int,int> _posicion_actual, int _dado);

private:
    Ui::SerpientesEscaleras *ui;
    friend class Dado1;

    int turno;
    int altura_dado;
    int ancho_dado;
    int ancho_casilla,altura_casilla;
    Jugador jugador_1;
    Jugador jugador_2;

    QGraphicsScene* scene;
    QGraphicsScene* scene_dado;
    QGraphicsRectItem* ptr_casilla_dado;
    QVector<QVector<Casilla>> tablero;
    QPair<int,int> nuevaPosicion;
    Dado dado;

    //Dado1 dado;
    //SerpientesEscaleras juego;

};
#endif // SERPIENTESESCALERAS_H
