#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept>

using namespace std;

class stack
{
private:
    vector<pair<int, int>> elements; // {node, current cost}

public:
    void push(pair<int, int> element)
    {
        elements.push_back(element);
    }
    void pop()
    {
        if (!elements.empty())
        {
            elements.pop_back();
        }
    }
    bool isEmpty()
    {
        return elements.empty();
    }
    pair<int, int> top()
    {
        if (!elements.empty())
        {
            return elements.back();
        }
        throw runtime_error("Stack is empty.");
    }
};

void depth_first_search(int src, int des, vector<vector<int>> &graph, vector<string> &node)
{
    int numNodes = graph.size();

    vector<bool> visited(numNodes, false);

    int minCost = INT_MAX;

    stack s;

    s.push({src, 0});

    while(!s.isEmpty())
    {
        pair <int, int> current = s.top();
        s.pop();
        int node = current.first;
        int cost = current.second;

        if(node == des)
        {
            minCost = min(minCost, cost);
            continue;
        }

        visited[node] = true;

        for(int i=0; i<numNodes; i++)
        {
            if(graph[node][i] != 1e9 && !visited[i])
            {
                s.push({ i, cost + graph[node][i] });
            }
        }
    }

    if(minCost != INT_MAX)
    {
        cout << "COST BETWEEN PATH " << node[src] << " TO " << node[des] << " IS: " << minCost << endl;
    }
    else
    {
        cout << "NO PATH FOUND" << endl;
    }
}


int main()
{
    vector<string> nodes = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    const int INF = 1e9;
    vector<vector<int>> graph =
    {
        {0, INF, INF, 13, INF, INF, INF, INF, INF, INF},
        {INF, 0, INF, INF, 14, 6, INF, INF, INF, INF},
        {INF, INF, 0, 9, INF, INF, INF, INF, INF, 10},
        {13, INF, INF, 0, INF, INF, INF, INF, 9, INF},
        {INF, 14, INF, INF, 0, INF, 8, INF, INF, INF},
        {INF, 6, 7, INF, INF, 0, 12, INF, INF, INF},
        {INF, INF, INF, INF, 8, INF, 0, 15, INF, INF},
        {INF, INF, INF, INF, INF, INF, 15, 0, INF, INF},
        {INF, INF, INF, INF, INF, 11, INF, INF, 0, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, 23, 0}
    };

    int source = 5;
    int destination = 6;

    depth_first_search(source, destination, graph, nodes);

    return 0;
}
