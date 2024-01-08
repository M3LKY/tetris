#pragma once
#include "grid.h"
#include "blocks.cpp"
#include "vector"
class Game
{
public:
    Game();
    ~Game();
    Grid grid;
    void Draw();
    std::vector<Block> obtener_bloques();
    Block obtener_bloque_ramdom();
    void manejo_movimiento_teclado();
    bool limites_bloques();
    void rotar_bloque();

    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;

private:
    void MoveBlockLeft();
    void MoveBlockRight();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    std::vector<Block> blocks;
    Block bloque_actual;
    Sound clearSound;
    Sound rotateSound;
    Block bloque_siguiente;
};