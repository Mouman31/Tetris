#include<bits/stdc++.h>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"
#include "game.h"
#include "colors.h"
#include <iostream>

using namespace std;

double lastUpdateTime=0;
bool eventTriggered(double interval){
    double currentTime=GetTime();
    if(currentTime-lastUpdateTime>=interval){
        lastUpdateTime=currentTime;
        return true;
    }
    return false;
} 

int main()
{

   InitWindow(500,620,"TETRIS");
   SetTargetFPS(60);

   Font font=LoadFontEx("Font/monogram.ttf",64,0,0);

   Game game=Game(); 
   
   while(WindowShouldClose()==false){
    UpdateMusicStream(game.music);
    game.handleInput();
    if(eventTriggered(0.5)){
        game.moveBlockDown();
    }
    BeginDrawing();
    ClearBackground(darkBlue);
    DrawTextEx(font,"Score",{352,15}, 38, 2, WHITE);
    DrawTextEx(font,"Next",{365,175}, 38, 2, WHITE);
    if(game.gameOver){
         DrawTextEx(font,"Game Over",{318,450}, 38, 2, WHITE);
    }

    DrawRectangleRounded({320,55,170,60},0.3,6,lightBlue);

    char scoreText[10];
    sprintf(scoreText,"%d",game.score);
    Vector2 textSize= MeasureTextEx(font,scoreText,38,2);
    DrawTextEx(font,scoreText,{320+(170-textSize.x)/2,65}, 38, 2, WHITE);
    DrawRectangleRounded({320,215,170,180},0.3,6,lightBlue);
    game.Draw();
    EndDrawing();
   }


   CloseWindow();
   return 0;
}