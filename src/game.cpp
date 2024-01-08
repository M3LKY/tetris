#include "game.h"
#include "random"

Game::Game()
{
    grid = Grid();
    blocks = obtener_bloques();
    bloque_actual = obtener_bloque_ramdom();
    bloque_siguiente = obtener_bloque_ramdom();
    gameOver = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");
}

Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

Block Game::obtener_bloque_ramdom()
{
    if (blocks.empty())
    {
        blocks = obtener_bloques();
    }
    int bloque_random = rand() % blocks.size();
    Block block_r = blocks[bloque_random];
    blocks.erase(blocks.begin() + bloque_random);
    return block_r;
}

std::vector<Block> Game::obtener_bloques()
{
    return {LBlock(), JBlock(), SBlock(), ZBlock(), IBlock(), OBlock(), TBlock()};
}

void Game::Draw()
{
    grid.drawGrid();
    bloque_actual.Draw(11, 11);
    switch (bloque_siguiente.id)
    {
    case 3:
        bloque_siguiente.Draw(500, 270);
        break;
    case 4:
        bloque_siguiente.Draw(500, 260);
        break;
    default:
        bloque_siguiente.Draw(500, 250);
        break;
    }
}

void Game::manejo_movimiento_teclado()
{
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        rotar_bloque();
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (!gameOver)
    {
        bloque_actual.Move(0, -1);
        if (limites_bloques() || BlockFits() == false)
        {
            bloque_actual.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if (!gameOver)
    {
        bloque_actual.Move(0, 1);
        if (limites_bloques() || BlockFits() == false)
        {
            bloque_actual.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if (!gameOver)
    {
        bloque_actual.Move(1, 0);
        if (limites_bloques() || BlockFits() == false)
        {
            bloque_actual.Move(-1, 0);
            LockBlock();
        }
    }
}

bool Game::limites_bloques()
{
    std::vector<Position> contenedor_bloques = bloque_actual.obtener_posicion_celda();
    for (Position elemento : contenedor_bloques)
    {
        if (grid.bloque_fuera_marco(elemento.row, elemento.column))
        {
            return true;
        }
    }
    return false;
}

void Game::rotar_bloque()
{
    if (!gameOver)
    {
        bloque_actual.rotar_bloque();
        if (limites_bloques() || BlockFits() == false)
        {
            bloque_actual.no_rotar();
        }
        else
        {
            PlaySound(rotateSound);
        }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = bloque_actual.obtener_posicion_celda();
    for (Position item : tiles)
    {
        grid.grid[item.row][item.column] = bloque_actual.id;
    }
    bloque_actual = bloque_siguiente;
    if (BlockFits() == false)
    {
        gameOver = true;
    }
    bloque_siguiente = obtener_bloque_ramdom();
    int rowsCleared = grid.ClearFullRows();
    if (rowsCleared > 0)
    {
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = bloque_actual.obtener_posicion_celda();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.initializeGrid();
    blocks = obtener_bloques();
    bloque_actual = obtener_bloque_ramdom();
    bloque_siguiente = obtener_bloque_ramdom();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;
}
