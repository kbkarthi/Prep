#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int>* adj;
    bool* Visited;
    void DFSUtil(int);
    public:
        Graph(int V)
        {
            this->V = V;
            this->adj = new list<int>[V];
            this->Visited = new bool[V];
            for (int i = 0; i < V; i++)
            {
                this->Visited[i] = false;
            }
        }
        void AddEdge(int, int);
        void DFS();
};

void Graph::AddEdge(int V1, int V2)
{
    this->adj[V1].push_back(V2);
}

void Graph::DFS()
{
    for (int i = 0; i < V; i++)
    {
        if (!this->Visited[i])
            DFSUtil(i);
    }
}

void Graph::DFSUtil(int current)
{
    this->Visited[current] = true;
    cout << current << endl;
    
    list<int>::iterator i;
    for (i = this->adj[current].begin(); i != this->adj[current].end(); i++)
    {
        if (!this->Visited[*i])
            DFSUtil(*i);
    }
}

int main()
{
   cout << "Hello World" << endl; 
   Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);
   g.DFS();
   
   return 0;
}

