#ifndef AGENTGRAPH_H_INCLUDE
#define AGENTGRAPH_H_INCLUDE

#include <vector>
#include <unordered_map>
#include <utility>

//Base graph class, will build a different graph each time using up to X connections and Y nodes
class AgentGraph
{
    public:
        //Funcs
        AgentGraph(int width, int height);
        std::vector<int> FindPath(int startNode, int endNode); //Public find calls private search.
        std::vector<int> GetNodeLocation(int nodeID);
        int GetNodeCost(int nodeID);
        //Vars
        int graphSize;
    private:
        //Funcs
        int BuildGraph(int width, int height); //Build the base graph.
        void AddNode(int nodeID, const std::vector<int>& connections, int x, int y, int cost);
        std::vector<int> PathSearch(int currNode, int endNode);
        //Vars
        const int spacing = 30;
        std::unordered_map<int, float> nodeCost;
        std::unordered_map<int, std::vector<int>> nodeLocation;
        std::vector<std::vector<int>> graphConnections;
};

#endif