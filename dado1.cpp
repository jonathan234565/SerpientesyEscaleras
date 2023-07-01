/*#include "dado1.h"

Dado1::Dado1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ptr_graphicsView_dado(new QGraphicsView(parent))
    , scene_dado(new QGraphicsScene(ptr_graphicsView_dado))
    , num(0)
{
    ui->setupUi(this);

    ptr_graphicsView_dado->setScene(scene_dado);

    // Obtener dimensiones del wiget del dado
    altura_dado = ui->graphicsView_dado->height();
    ancho_dado = ui->graphicsView_dado->width();

    // Cargar imagen como patrón
    QPixmap cara_1("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\1.png");
    cara_1 = cara_1.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    lado_1 = new QGraphicsPixmapItem(cara_1);


    QPixmap cara_2("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\2.png");
    cara_2 = cara_2.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    lado_2 = new QGraphicsPixmapItem(cara_2);

    QPixmap cara_3("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\3.png");
    cara_3 = cara_3.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    lado_3 = new QGraphicsPixmapItem(cara_3);

    QPixmap cara_4("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\4.png");
    cara_4 = cara_4.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    lado_4 = new QGraphicsPixmapItem(cara_4);

    QPixmap cara_5("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\5.jpg");
    cara_5 = cara_5.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    lado_5 = new QGraphicsPixmapItem(cara_5);

    QPixmap cara_6("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\5.jpg");
    cara_6 = cara_6.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    lado_6 = new QGraphicsPixmapItem(cara_6);




}
int Dado1::generar_aleatorio(){
    srand(time(nullptr));
    num = (rand()%6)+1; ///rand me da un numero entre 0 y 5, se le suma 1 para que sea entre 1 y 6
    return num;
}

int Dado1::tirar_dado(){
    // Crear un pincel para dibujar las casillas
    QPen pen(Qt::black, 1);

    int num = generar_aleatorio();

    if (num == 1){
        scene_dado->addItem(lado_1);
        return 1;

    }else if(num == 2){
        scene_dado->addItem(lado_2);
        return 2;

    }else if(num == 3){
        scene_dado->addItem(lado_3);
        return 3;

    }else if(num == 4){
        scene_dado->addItem(lado_4);
        return 4;

    }else if(num == 5){
        scene_dado->addItem(lado_5);
        return 5;

    }else if(num == 6){
        scene_dado->addItem(lado_6);
        return 6;
    }else
        return -1;

}

*/
