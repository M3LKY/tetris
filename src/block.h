#pragma once
#include "position.h"
#include <vector>
#include <map>
#include "colors.h"

class Block{
public:
    Block();
    void Draw(int desplazamiento_x, int desplazamiento_y);
    void Move(int fila, int columna);
    std::vector<Position> obtener_posicion_celda();
    int id;
    std::map<int, std::vector<Position>> celda;
    void rotar_bloque();
    void no_rotar();

private:
    int dezplazamiento_fila;
    int dezplazamiento_columna;
    int tamano_celda;
    int rotacion_figura;
    std::vector<Color> color;
};