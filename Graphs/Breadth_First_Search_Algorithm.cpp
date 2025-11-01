#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int numVertices;                   
    vector<vector<int>> adjList;        

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);    
        adjList[dest].push_back(src);    
    }

    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false); 
        queue<int> q;                             

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS traversal starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for (int i : adjList[currentVertex]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g(5); 

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.BFS(0);  

    return 0;
}
