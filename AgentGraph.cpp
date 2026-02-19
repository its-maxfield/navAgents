#include "AgentGraph.h"
#include <iostream>

AgentGraph::AgentGraph(int width, int height)
{
    //Constructor, will build the graph when called.
    BuildGraph();
}

void AgentGraph::BuildGraph()
{
    std::cout << "Building graph..." << std::endl;  
}