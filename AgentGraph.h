#ifndef AGENTGRAPH_H_INCLUDE
#define AGENTGRAPH_H_INCLUDE

#include <vector>
#include <unordered_map>
#include <utility>

//Base graph class, will build a different graph each time using up to X connections and Y nodes
class AgentGraph
{
    public:
        AgentGraph(int width, int height);
        void BuildGraph(); //Build the base graph.
        std::vector<int> FindPath(int startNode, int endNode); //Public find calls private search.
    private:
        std::unordered_map<int, int> nodeCost;
        std::vector<std::vector<int>> graphConnections;

        void AddConnection(int nodeA, int nodeB, int cost);
        void AddNode(int nodeID, const std::vector<int>& connections);
        std::vector<int> PathSearch(int currNode, int endNode);
};

#endif