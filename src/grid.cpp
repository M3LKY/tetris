#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numero_Filas = 14;
    numero_Columnas = 9;
    tamano_celda = 70;
    initializeGrid(); // adding to the constructor so it is call when class grid is instance
    color = Obtener_colores();
}

void Grid::initializeGrid()
{
    for (int i = 0; i < numero_Filas; i++)
    {
        for (int j = 0; j < numero_Columnas; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::printGrid()
{
    for (int i = 0; i < numero_Filas; i++)
    {
        for (int j = 0; j < numero_Columnas; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void Grid::drawGrid(){
    for(int i = 0; i < numero_Filas; i++){
        for(int j = 0; j < numero_Columnas; j++){
            int valor_celda = grid[i][j];
            DrawRectangle(j * tamano_celda + 11, i * tamano_celda + 11, tamano_celda - 5, tamano_celda - 5, color[valor_celda]);// this creates a grid background(lots of squares)
        }
    }
}

bool Grid::bloque_fuera_marco(int fila, int columna){
    if(fila >= 0 && fila < numero_Filas && columna >= 0 && columna < numero_Columnas){
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numero_Filas - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numero_Columnas; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int column = 0; column < numero_Columnas; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numero_Columnas; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
