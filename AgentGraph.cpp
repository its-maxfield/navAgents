#include "AgentGraph.h"
#include <iostream>
#include <random>

AgentGraph::AgentGraph(int width, int height)
{
    //Constructor, will build the graph when called.
    graphSize = BuildGraph(width, height);
}

int AgentGraph::BuildGraph(int width, int height)
{
    std::cout << "Building graph..." << std::endl;

    const int cols = ((width  - 1) / spacing) + 1;
    const int rows = ((height - 1) / spacing) + 1;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 40);

    int nodes = 0;

    for (int y = 0; y < height; y += spacing)
    {
        for (int x = 0; x < width; x += spacing)
        {
            const int gridR = y / spacing;
            const int gridC = x / spacing;
            const int nodeID = gridR * cols + gridC;

            std::vector<int> connections;
            connections.reserve(4);

            int selection = distr(gen);
            if (gridC > 0 && selection < 14)        
                connections.push_back(gridR * cols + (gridC - 1));
            if (gridC + 1 < cols) 
                connections.push_back(gridR * cols + (gridC + 1));
            if (gridR > 0 && selection < 28)        
                connections.push_back((gridR - 1) * cols + gridC);
            if (gridR + 1 < rows && selection > 33) 
                connections.push_back((gridR + 1) * cols + gridC);

            AddNode(nodeID, connections, x, y, distr(gen)); 
            nodes++;
        }
    }

    std::cout << "Graph built with " << nodes << " nodes." << std::endl;
    return nodes;
}

int AgentGraph::GetNodeCost(int nodeID)
{
    return nodeCost.at(nodeID);
}

std::vector<int> AgentGraph::GetNodeConnections(int nodeID)
{
    return graphConnections[nodeID];
}

std::vector<int> AgentGraph::GetNodeLocation(int nodeID)
{
    return nodeLocation.at(nodeID);
}

void AgentGraph::AddNode(int nodeID, const std::vector<int>& connections, int x, int y, int cost)
{
    graphConnections.push_back(connections);
    nodeCost[nodeID] = cost;
    nodeLocation[nodeID] = {x, y}; //Store location based on ID.
}
