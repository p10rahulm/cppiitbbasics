#include<iostream>
#include "header.h"
#include <list>
using namespace std;

SafeMap::SafeMap(int V)
{
    this->V = V;
    adj = new list<int> [V];
}

void SafeMap::addSafeRoute(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.
}

// Function to check if S is safely reachable from D
int SafeMap::isReachable(int s, int d)
{


     // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // it will be used to get all adjacent vertices of a vertex accesible thru
    // a safe route
    list<int>::iterator i;

   //Write your code below this line

    int *layer = new int[V];
    for (int i = 0; i < V; i++)
        layer[i] = 0;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then return true
            layer[*i] = layer[s] +1;
            if (*i == d)
            {
                if (layer[*i] != 0)
				{
					return layer[*i];
				}
            }
            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return -1;
}
