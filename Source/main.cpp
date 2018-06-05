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
    int screenWidth = 22*32;
    int screenHeight = 22*32;
    tMap mapa = tMap();    
    InitWindow(screenWidth, screenHeight, "tMap Test");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(IsKeyDown(KEY_UP)){
			mapa.ir(0);
			ClearBackground(BLACK);
			
		}
		if(IsKeyDown(KEY_RIGHT)){
			mapa.ir(2);
			ClearBackground(BLACK);
			
		}
		if(IsKeyDown(KEY_LEFT)){
			mapa.ir(3);
			ClearBackground(BLACK);
			
		}	
		if(IsKeyDown(KEY_DOWN)){
			mapa.ir(1);
			ClearBackground(BLACK);
			
		}
        BeginDrawing();
			for (int i = 0; i <=21;i++){
				for (int j = 0 ; j <=21; j++){
					if(mapa.playerLocation.tileMap[i][j] == 0)
						DrawRectangle(1*(j*32),1*(i*32),32,32,BLACK);
					if(mapa.playerLocation.tileMap[i][j] == 1)
						DrawRectangle(1*(j*32),1*(i*32),32,32,GREEN);
					if(mapa.playerLocation.tileMap[i][j] == 2)
						DrawRectangle(1*(j*32),1*(i*32),32,32,RED);
					if(mapa.playerLocation.tileMap[i][j] == 3)
						DrawRectangle(1*(j*32),1*(i*32),32,32,PURPLE);
					if(mapa.playerLocation.tileMap[i][j] == 4)
						DrawRectangle(1*(j*32),1*(i*32),32,32,BLUE);
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
