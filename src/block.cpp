#include "block.h"
#include "raylib.h"
#include <vector>
#include "position.h"
Block::Block()
{
    tamano_celda = 70;
    rotacion_figura = 0;
    dezplazamiento_fila = 0;
    dezplazamiento_columna = 0;
    color = Obtener_colores();
}

void Block::Draw(int desplazamiento_x, int desplazamiento_y)
{
    std::vector<Position> contenedor_bloque = obtener_posicion_celda();
    for (Position p : contenedor_bloque)
    {
        DrawRectangle(p.column * tamano_celda + desplazamiento_x, p.row * tamano_celda + desplazamiento_y, tamano_celda - 5, tamano_celda - 5, color[id]);
    }
}

void Block::Move(int fila, int columna)
{
    dezplazamiento_fila += fila;
    dezplazamiento_columna += columna;
}

std::vector<Position> Block::obtener_posicion_celda()
{
    std::vector<Position> cajas_bloque = celda[rotacion_figura];
    std::vector<Position> moviendo_caja;
    for (Position elemento : cajas_bloque)
    {
        Position nueva_posicion = Position(elemento.row + dezplazamiento_fila, elemento.column + dezplazamiento_columna);
        moviendo_caja.push_back(nueva_posicion);
    }
    return moviendo_caja;
}

void Block::rotar_bloque(){
    rotacion_figura++;
    if(rotacion_figura == (int)celda.size()){
        rotacion_figura = 0;
    }
}

void Block::no_rotar(){
    rotacion_figura--;
    if(rotacion_figura == -1){
        rotacion_figura = celda.size() - 1;
    }
}