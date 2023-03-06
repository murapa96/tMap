/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Lib/tMap.h"
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 21*32;
    int screenHeight = 21*32;
    tMap mapa = tMap();    
    InitWindow(screenWidth, screenHeight, "tMap Test");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(IsKeyDown(KEY_UP))
			mapa.irNorte();
		if(IsKeyDown(KEY_RIGHT))
			mapa.irEste();
		if(IsKeyDown(KEY_LEFT))
			mapa.irOeste();
		if(IsKeyDown(KEY_DOWN))
			mapa.irSur();
        BeginDrawing();
			for (int i = 0; i <=21;i++){
				for (int j = 0 ; j <=21; j++){
					if(mapa.pLocation->tileMap[i][j] == 0)
						DrawRectangle(1*(i*32),1*(j*32),32,32,BLACK);
					if(mapa.pLocation->tileMap[i][j] == 1)
						DrawRectangle(1*(i*32),1*(j*32),32,32,GREEN);
					if(mapa.pLocation->tileMap[i][j] == 2)
						DrawRectangle(1*(i*32),1*(j*32),32,32,RED);
					if(mapa.pLocation->tileMap[i][j] == 3)
						DrawRectangle(1*(i*32),1*(j*32),32,32,PURPLE);
					if(mapa.pLocation->tileMap[i][j] == 4)
						DrawRectangle(1*(i*32),1*(j*32),32,32,BLUE);
			}
		}
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
