#pragma once
#include "raylib.h"
#include <vector>
class Grid
{
public:
    Grid();                // constructor
    void initializeGrid(); // initialize the grid
    void printGrid();      // print the grid
    void drawGrid();       // draw the grid
    int grid[14][9];// here you target every cell of the grid, and you can change its color from the main
    bool bloque_fuera_marco(int fila, int columna);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();

private:
bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numero_Filas;
    int numero_Columnas;
    int tamano_celda;
    std::vector<Color> color;
};