#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>


int screen[100][100];

void Game_logic() 
{
    for (int i = 0;i < 100;i++) 
    {
        for(int y=0;y<100;y++)
        {
            int cell_nighbers=0;

            if (screen[i + 1][y] == 1) { cell_nighbers += 1; }
            if (screen[i - 1][y] == 1) { cell_nighbers += 1; }
            if (screen[i][y + 1] == 1) { cell_nighbers += 1; }
            if (screen[i][y - 1] == 1) { cell_nighbers += 1; }
            if (screen[i + 1][y + 1] == 1) { cell_nighbers += 1; }
            if (screen[i - 1][y - 1] == 1) { cell_nighbers += 1; }
            if (screen[i - 1][y + 1] == 1) { cell_nighbers += 1; }
            if (screen[i + 1][y - 1] == 1) { cell_nighbers += 1; }

            if (cell_nighbers < 2) { screen[i][y] = 0; }
            if (cell_nighbers >= 2) { screen[i][y] = 1; }
            if (cell_nighbers > 3) { screen[i][y] = 0; }
            if (screen[i][y] == 0) { if (cell_nighbers == 3) { screen[i][y] = 1; } }





        }
    }
    
}

void Draww() 
{
    for (int i = 0;i < 100;i++)
    {
        for (int y = 0;y < 100;y++)
        {
            if (screen[i][y] == 1) 
            {
                DrawRectangle(i * 10, y * 10, 10, 10, WHITE);
            }
        }
    }
}


int main(void)
{

    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Game of Life");

    SetTargetFPS(7);               

    screen[50][50] = 1;
    screen[50][51] = 1;
    screen[50][52] = 1;

 

    // Main game loop
    while (!WindowShouldClose())    
    {
 



        //Draw
        BeginDrawing();
        ClearBackground(BLACK);
        Game_logic();
        Draww();
        EndDrawing();
        
    }

    CloseWindow();        
    return 0;
}