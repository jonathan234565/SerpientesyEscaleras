#include "serpientesescaleras.h"
#include "ui_serpientesescaleras.h"
#include <cstdlib>
#include <ctime>
#include <QPair>

SerpientesEscaleras::SerpientesEscaleras(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerpientesEscaleras)
    , scene(new QGraphicsScene(this))
    , scene_dado(new QGraphicsScene(this))
    , tablero(10,QVector<Casilla>(10))

{
    ui->setupUi(this);
    //QWidget* graphicsViewPtr = ui->graphicsView_dado;
    //Dado1 dado2;

    ui->graphicsView->setScene(scene); // Le meto scene al widget correspondiente
    ui->graphicsView_dado->setScene(scene_dado); //Le meto scene_dado al widget correspondiente

    turno = 1;

    // Obtener dimensiones del wiget del dado
    altura_dado = ui->graphicsView_dado->height();
    ancho_dado = ui->graphicsView_dado->width();

    // Obtener dimensiones del tablero
    const int altura_widget = ui->graphicsView->height();

    // Calcular tamaño de las casillas
    ancho_casilla = altura_widget/11;
    altura_casilla = altura_widget/11;

    crear_tablero(scene,altura_casilla,ancho_casilla);
    QPen pen(Qt::black, 1);
    ptr_casilla_dado = scene_dado->addRect(1,1,ancho_dado,altura_dado, pen);
    tirar_dado();


    //Ahora asigno las casillas de serpientes y escaleras
    crear_serpientes_y_escaleras();

    //Inicializo ambos jugadores en la misma casilla

    QPair<int,int> posicion_inicio = qMakePair(0,0);

    jugador_1.set_nueva_posicion(posicion_inicio);
    jugador_2.set_nueva_posicion(posicion_inicio);


}

void SerpientesEscaleras::crear_tablero(QGraphicsScene* &scene, const int &altura_casilla,const int &ancho_casilla){
    // Crear un pincel para dibujar las casillas
    QPen pen(Qt::black, 1);

    // Cargar imagen como patrón
    QPixmap cuadro_verde("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\cuadrado_verde.png");
    cuadro_verde = cuadro_verde.scaled(ancho_casilla, altura_casilla, Qt::KeepAspectRatio);

    QPixmap cuadro_rojo ("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\cuadrado_rojo.jpg");
    cuadro_rojo = cuadro_rojo.scaled(ancho_casilla, altura_casilla, Qt::KeepAspectRatio);

    QBrush brush_cuadro_verde(cuadro_verde);
    QBrush brush_cuadro_rojo(cuadro_rojo);

    // Agregar 10x10 casillas a la escena y asignar valor de ubicacion y numero a casillas
    int num_casilla = 0;
    for (int fila = 0; fila<10; fila++){
        for(int columna = 0; columna<10;columna++){
            tablero[fila][columna].set_fila(fila);
            tablero[fila][columna].set_columna(columna);
            tablero[fila][columna].set_num_casilla(num_casilla);
            tablero[fila][columna].set_tipo("casilla");
            num_casilla++;
            QGraphicsRectItem* ptr_casilla_grafica = scene->addRect(columna * ancho_casilla, (10-fila) * altura_casilla, ancho_casilla, altura_casilla, pen);
            ptr_casilla_grafica->setBrush(Qt::white);


            if (columna%2 == 0){
                if (fila%2 == 0)
                    ptr_casilla_grafica->setBrush(brush_cuadro_verde);
                else
                    ptr_casilla_grafica->setBrush(brush_cuadro_rojo);
            }else{
                if (fila%2 != 0)
                    ptr_casilla_grafica->setBrush(brush_cuadro_verde);
                else
                    ptr_casilla_grafica->setBrush(brush_cuadro_rojo);
            }

            // Asociar la casilla con su correspondiente objeto Casilla en la matriz tablero
            tablero[fila][columna].set_ptr_casilla_grafica(ptr_casilla_grafica);

        }
    }
}

int SerpientesEscaleras::tirar_dado(){
    // Crear un pincel para dibujar las casillas
    QPen pen(Qt::black, 1);

    int num = dado.generar_aleatorio();

    // Cargar imagen como patrón
    QPixmap cara_1("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\1.png");
    cara_1 = cara_1.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    //QGraphicsPixmapItem* lado_1 = new QGraphicsPixmapItem(cara_1);
    QBrush brush_imagen_cara1(cara_1);


    QPixmap cara_2("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\2.png");
    cara_2 = cara_2.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    //QGraphicsPixmapItem* lado_2 = new QGraphicsPixmapItem(cara_2);
    QBrush brush_imagen_cara2(cara_2);

    QPixmap cara_3("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\3.png");
    cara_3 = cara_3.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    //QGraphicsPixmapItem* lado_3 = new QGraphicsPixmapItem(cara_3);
    QBrush brush_imagen_cara3(cara_3);

    QPixmap cara_4("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\4.png");
    cara_4 = cara_4.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    //QGraphicsPixmapItem* lado_4 = new QGraphicsPixmapItem(cara_4);
    QBrush brush_imagen_cara4(cara_4);

    QPixmap cara_5("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\5.jpg");
    cara_5 = cara_5.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    //QGraphicsPixmapItem* lado_5 = new QGraphicsPixmapItem(cara_5);
    QBrush brush_imagen_cara5(cara_5);

    QPixmap cara_6("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\5.jpg");
    cara_6 = cara_6.scaled(ancho_dado,altura_dado, Qt::KeepAspectRatio);
    //QGraphicsPixmapItem* lado_6 = new QGraphicsPixmapItem(cara_6);
    QBrush brush_imagen_cara6(cara_6);

    if (num == 1){
        //scene_dado->addItem(lado_1);
        ptr_casilla_dado->setBrush(brush_imagen_cara1);
        return 1;

    }else if(num == 2){
        //scene_dado->addItem(lado_2);
        ptr_casilla_dado->setBrush(brush_imagen_cara2);
        return 2;

    }else if(num == 3){
        //scene_dado->addItem(lado_3);
        ptr_casilla_dado->setBrush(brush_imagen_cara3);
        return 3;

    }else if(num == 4){
        //scene_dado->addItem(lado_4);
        ptr_casilla_dado->setBrush(brush_imagen_cara4);
        return 4;

    }else if(num == 5){
        //scene_dado->addItem(lado_5);
        ptr_casilla_dado->setBrush(brush_imagen_cara5);
        return 5;

    }else if(num == 6){
        //scene_dado->addItem(lado_6);
        ptr_casilla_dado->setBrush(brush_imagen_cara6);
        return 6;
    }else
        return -1;

}

void SerpientesEscaleras::crear_serpientes_y_escaleras(){
    QPixmap imagen_serpiente("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\serpiente.png");
    imagen_serpiente = imagen_serpiente.scaled(ancho_casilla, altura_casilla, Qt::KeepAspectRatio);


    int n = 0;
    int fila_serpiente,columna_serpiente;

    while (n < 3) {
        srand(time(nullptr));
        fila_serpiente = rand() % 9;
        columna_serpiente = rand() % 7;

        if (tablero[fila_serpiente][columna_serpiente].get_tipo() == "casilla" &&
            tablero[fila_serpiente+1][columna_serpiente-1].get_tipo() == "casilla" &&
            tablero[fila_serpiente+1][columna_serpiente].get_tipo() == "casilla" &&
            tablero[fila_serpiente+1][columna_serpiente+1].get_tipo() == "casilla" &&
            tablero[fila_serpiente][columna_serpiente-1].get_tipo() == "casilla" &&
            tablero[fila_serpiente][columna_serpiente].get_tipo() == "casilla" &&
            tablero[fila_serpiente][columna_serpiente+1].get_tipo() == "casilla" &&
            tablero[fila_serpiente-1][columna_serpiente-1].get_tipo() == "casilla" &&
            tablero[fila_serpiente-1][columna_serpiente].get_tipo() == "casilla" &&
            tablero[fila_serpiente-1][columna_serpiente+1].get_tipo() == "casilla"){

            n++;

            tablero[fila_serpiente][columna_serpiente].set_tipo("serpiente");
            tablero[fila_serpiente][columna_serpiente].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);

            //Agrego las serpientes segun la posicion de la serpiente inicial
            if (fila_serpiente <5){
                if (columna_serpiente<5){
                    tablero[fila_serpiente+ 1][columna_serpiente+1].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);
                    tablero[fila_serpiente+2][columna_serpiente+2].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);
                }
            }
            if(fila_serpiente<5){
                if(columna_serpiente>5){
                    tablero[fila_serpiente - 1][columna_serpiente -1].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);
                    tablero[fila_serpiente - 2][columna_serpiente -2].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);
                }
            }
            if (5<=fila_serpiente && fila_serpiente<=7){
                if (columna_serpiente<5){
                    tablero[fila_serpiente + 1][columna_serpiente+1].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);
                    tablero[fila_serpiente+2][columna_serpiente+2].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);
                }
            }
            if (5<=fila_serpiente && fila_serpiente<=7){
                if (columna_serpiente<5){
                    tablero[fila_serpiente - 1][columna_serpiente - 1].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);
                    tablero[fila_serpiente - 2][columna_serpiente - 2].get_ptr_casilla_grafica()->setBrush(imagen_serpiente);
                }
            }

        //}else
        //    tablero[qAsConst(par).first][qAsConst(par).second].set_tipo("escalera");
        //ui->label->setText( typeid(par).name());
        }
    }
}

SerpientesEscaleras::~SerpientesEscaleras()
{
    delete ui;
}

QSet<QPair<int,int>> SerpientesEscaleras::generar_aleatorio(){
    ///Creo una lista números aleatorios para definir las casillas de las escaleras y serpientes
    QSet<QPair<int,int>> pares_aleatorios;
    srand(time(nullptr));
    int n = 0;

    while(pares_aleatorios.size()< 10){
        pares_aleatorios.insert(qMakePair(rand() % 7,rand() % 10));
        n++;
    }
    return pares_aleatorios;
    ///La ventaja de usar QSet es que no permite duplicados, por lo que si hay un duplicado
    /// no lo guarda, el bucle se ejecuta hasta tener 10 pares diferentes a todo lo ancho y
    /// hasta una altura de 7 filas, para que el final de ninguna escalera quede fuera del
    /// tablero
}

QPair<int,int> SerpientesEscaleras::nueva_posicion(QPair<int,int> _posicion_actual,int _dado){
    int nueva_columna = _posicion_actual.second + _dado;

    if (nueva_columna>9){
        _posicion_actual.first += 1; ///Subo una fila
        _posicion_actual.second = 9 - nueva_columna; ///Sumo los espacios que sobraron en la fila anterior
    }else{
     _posicion_actual.second += _dado;
    }
    return _posicion_actual;
}

void SerpientesEscaleras::on_pushButton_dado_clicked()
{
    ///Casilla casilla;
    if (turno == 1){
        ui->label_turno->setText("Turno del primer jugador");
        turno += 1;
        //tirar_dado();
        //jugador_1.set_nueva_posicion(nueva_posicion(jugador_1.get_posicion(),num_dado));
    }
}
        /*
}

        if (tablero[jugador_1.get_fila()][jugador_1.get_columna()].get_tipo() == "serpiente"){

        }else if(tablero[jugador_1.get_fila()][jugador_1.get_columna()].get_tipo() == "escalera"){}

    }else if(turno == 2){
        ui->label_turno->setText("Turno del segundo jugador");

        int num_dado = dado.tirar_dado();
        jugador_1.set_nueva_posicion(nueva_posicion(jugador_2.get_posicion(),num_dado));
        if (tablero[jugador_2.get_fila()][jugador_2.get_columna()].get_tipo() == "serpiente"){

        }else if(tablero[jugador_2.get_fila()][jugador_2.get_columna()].get_tipo() == "escalera"){}

    }*/
    //tablero[3][2].get_ptr_casilla_grafica()->setBrush(Qt::blue);

    // Calcular tamaño de las casillas
    // Obtener dimensiones del widget
    ///int altura_widget = ui->graphicsView->height();
    //int ancho_casilla = altura_widget/11;
  ///  const int altura_casilla = altura_widget/11;
    // Obtener el objeto gráfico de la casilla

    // Crear un objeto QGraphicsPixmapItem para la imagen del jugador
    //QPixmap _imagen_jugador("C:\\Users\\HP\\Downloads\\Analisis de algoritmos\\Proyectos\\Proyecto 1. Serpientes y escaleras\\SerpientesEscaleras\\imagenes\\jugador1.jpg");
    //QPixmap imagen_jugador = _imagen_jugador.scaled(ancho_casilla, altura_casilla, Qt::KeepAspectRatio);

    // Obtener el objeto gráfico del jugador
    //QGraphicsItem* jugadorItem = new QGraphicsPixmapItem(imagen_jugador);

    // Obtener el objeto gráfico de la casilla
    //QGraphicsItem* casillaItem = tablero[9][0].get_ptr_casilla_grafica();}

    // Establecer el índice Z de la casilla en 1 y el del jugador en 2
    //casillaItem->setZValue(1);
    //jugadorItem->setZValue(2);

    // Establecer la posición del objeto del jugador en la casilla

    /* jugadorItem->setPos(altura_casilla*9, 4*ancho_casilla);
    ui->l->setText(QString::number(tablero[9][0].get_ptr_casilla_grafica()->pos().x()));

    // Establecer el objeto gráfico de la casilla como el padre del objeto gráfico del jugador
    jugadorItem->setParentItem(casillaItem);

    // Agregar el objeto del jugador a la escena
    scene->addItem(jugadorItem);*/




