#include "block.h"
#include "position.h"

class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1;
        celda[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        celda[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        celda[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        celda[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        Move(0,3);
    }
};
class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;
        celda[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        celda[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        celda[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        celda[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
        Move(0,3);
    }
};
class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        celda[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        celda[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        celda[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        celda[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        Move(-1,3);
    }
};
class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        celda[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        celda[1] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        celda[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        celda[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        Move(0,4);  
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
        celda[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        celda[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        celda[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
        celda[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0,3);
    }
};
class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        celda[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        celda[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        celda[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        celda[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0,3);
    }
};
class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
        celda[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        celda[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        celda[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        celda[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        Move(0,3);
    }
};