#pragma once
#include<vector>
#include<raylib.h>

using namespace std;

class Grid{
private:
    int rowNum;
    int colNum;
    int cellSize;
    vector<Color>colors;
    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowDown(int row,int rowNum);


public:
    int grid[20][10];
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool isCellOutside(int row,int col);
    bool isCellEmpty(int row,int col);
    int clearFullRows();
};