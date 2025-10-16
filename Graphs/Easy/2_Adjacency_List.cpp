#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Node for linked list
struct Node
{
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

// Graph structure
struct Graph
{
    int vertex;
    Node **adjList;
    Graph(int vertex)
    {
        this->vertex = vertex;
        adjList = new Node *[vertex];
        for (int i = 0; i < vertex; i++)
            adjList[i] = nullptr;
    }
};

// Add edge (undirected)
void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = new Node(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = new Node(src); // undirected
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Your code here
void Solve()
{
    int vertices = 5;
    Graph *graph = new Graph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Printing Graph Adjacency List
    for (int i = 0; i < graph->vertex; i++)
    {
        cout << i << " -> ";
        Node *temp = graph->adjList[i];
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Driver code
int main()
{
    fastio();
    Solve();
    return 0;
}