#include "raylib.h"
#include "AgentGraph.h"

#include <string>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 650;

    const float gridPointSize = 2.0f;

    AgentGraph myGraph(screenWidth, screenHeight);

    InitWindow(screenWidth, screenHeight, "NavAgents");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for(int i = 0; i < myGraph.graphSize; i++)
            {
                std::vector<int> loc = myGraph.GetNodeLocation(i);
                std::vector<int> connections = myGraph.GetNodeConnections(i);
                for(auto j : connections)
                {
                    std::vector<int> connLoc = myGraph.GetNodeLocation(j);
                    DrawLine(loc[0], loc[1], connLoc[0], connLoc[1], GRAY);
                }
                DrawCircle(loc[0], loc[1], gridPointSize, RED);
                DrawText(std::to_string(myGraph.GetNodeCost(i)).c_str(), loc[0], loc[1], 10, BLACK);
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