#include <iostream>
#include <list>
#include <queue>
#include <thread>

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
        void BFS();
};

void Graph::AddEdge(int V1, int V2)
{
    this->adj[V1].push_back(V2);
}

void Graph::BFS()
{
    queue<int> myqueue;
    myqueue.push(0);
    this->Visited[0] = true;
    
    list<int>::iterator i;  
    while(!myqueue.empty())
    {
        int front = myqueue.front();
        myqueue.pop();
        cout << front << endl;

        for (i = this->adj[front].begin(); i != this->adj[front].end(); i++)
        {
            if (!Visited[*i])
            {
                this->Visited[*i] = true;
                myqueue.push(*i);
            }
        }
    }
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
   g.BFS();
   
   return 0;
}
