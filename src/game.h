#pragma once
#include "grid.h"
#include "block.h"

using namespace std;

class Game{
public:
       Game();
       ~Game();
       Block getRandomBlock();
       vector<Block> getAllBlocks();
       void Draw();
       void handleInput();
       void moveBlockLeft();
       void moveBlockRight();
       void moveBlockDown();
       bool gameOver;
       Grid grid;
       int score;
       Music music;

private:
       bool isBlockOutside();
       void rotateBlock();
       void lockBlock();
       bool blockFits();
       void resetGame();
       void updateScore(int linesCleared,int moveDownPoints);
       vector<Block>blocks;
       Block currentBlock;
       Block nextBlock;
       Sound rotateSound;
       Sound clearSound;
};