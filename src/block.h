#pragma once
#include<map>
#include<vector>
#include "position.h"
#include "colors.h"

using namespace std;

class Block{
public:
    Block();
    void Draw(int offsetX,int offsetY);
    void Move(int rows, int columns);
    vector<Position> getCellPositions();
    void Rotate();
    void undoRotate();
    int ID;
    map<int,vector<Position>> cells;

private:
    int cellSize;
    int rotationState; 
    vector<Color>colors;
    int rowOffset;
    int colOffset;
};
