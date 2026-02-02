#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(1280, 800, "Hello Raylib");

	SearchAndSetResourceDir("resources");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		DrawText("First window success!", 200,200,20,BLACK);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
