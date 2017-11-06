#include<iostream>
#include <list>
using namespace std;
int routine[1000][1000],k_array[1000];
int routine_index=0;
int k;
int l=0;
int time=0;
int calk(int k)
{
    int m=k;
    return k;
}
// A directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);

public:
    Graph(int V);   // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        k=0;
        for (k = 0; k<path_index; k++)
            cout << path[k]<< " ";
            cout<<endl;

    }
 else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
            {
                printAllPathsUtil(*i, d, visited, path, path_index);
            }
    }

   time=0;


    routine_index++;
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}



// Driver program
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    int s,d;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(3, 0);
    g.addEdge(1, 2);
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    cout <<   "                                                                BUS ROUTINE SERVICES" << '\n' << endl;
    cout << "                                             Currently there are 4 bus stops in your city." << endl;

    char k ='Y';
    while(1){
    cout << "Enter your location: ";
    cin >> s;
    cout << "Enter the destination: ";
    cin >> d;
    if(s>3 || s<0)
        cout<<endl<<"source location not found"<<endl<<endl;
    else if(d>3 || d<0)
        cout<<endl<<"destination not found"<<endl<<endl;
    else if(s==d)
        cout <<endl<<  "Enter different destination."<<endl<<endl;
    else{
        break;
    }
}
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d);


    return 0;
}

