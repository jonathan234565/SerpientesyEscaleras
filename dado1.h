/*#ifndef DADO1_H
#define DADO1_H
#include <QGraphicsScene>
#include "ui_serpientesescaleras.h"
#include "serpientesescaleras.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Dado1; }
QT_END_NAMESPACE

class Dado1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dado1(QWidget *parent = nullptr);
    ~Dado1();

private:
    Ui::MainWindow *ui;
    QGraphicsView* ptr_graphicsView_dado;
    QGraphicsScene* scene_dado;

    int num, altura_dado, ancho_dado;
    QGraphicsPixmapItem* lado_1,*lado_2,*lado_3,*lado_4,*lado_5,*lado_6;



public:
    Dado1(QWidget *parent = nullptr);
    int generar_aleatorio();
    int tirar_dado();

#endif // DADO1_H

*/
