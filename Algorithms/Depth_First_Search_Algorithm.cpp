#include <iostream>
#include <vector>

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

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;         
        cout << vertex << " ";           

        for (int i : adjList[vertex]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false); 

        cout << "DFS traversal starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
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

    g.DFS(0);

    return 0;
}
