#include "block.h"

using namespace std;

Block::Block(){
    cellSize=30;
    rotationState=0;
    colors=getColor();
    rowOffset=0;
    colOffset=0;
}

void Block::Draw(int offsetX,int offsetY){
    vector<Position> tiles=getCellPositions();
    for(Position item: tiles){
        DrawRectangle(item.col*cellSize+offsetX,item.row*cellSize+offsetY,cellSize-1,cellSize-1,colors[ID]);
    }

}

void Block:: Move(int rows,int columns){
    rowOffset+=rows;
    colOffset+=columns;

}

vector<Position> Block:: getCellPositions(){
    vector<Position>tiles=cells[rotationState];
    vector<Position> movedTiles;
    for(Position item: tiles){
        Position newPos=Position(item.row+rowOffset,item.col+colOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate(){
    rotationState++;
    if(rotationState==(int)cells.size()){
         rotationState=0;
    }
}

void Block::undoRotate(){
    rotationState--;
    if(rotationState==-1){
        rotationState=cells.size()-1;
    }
}
