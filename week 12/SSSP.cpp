#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;


//Finding min distance
int minDistance(int dist[], bool visited[]) 
{
    int minDist = 100000, minIndex;
    for (int v = 0; v < 6; ++v) 
    {
        if (!visited[v] && dist[v] <= minDist) 
        {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

//Printing the shortest day
void printShortestDistances(int dist[]) 
{
    std::cout << "City\tSource to destination shortest distance\n";
    for (int i = 0; i < 6; ++i) 
    {
        cout << i << "\t \t" << dist[i] << "\n";
    }
}

//Using Dijkstra for shortest distance
void dijkstra(int graph[6][6], int source) 
{
    int dist[6];     // To store the shortest distances
    bool visited[6]; // To track visited cities
    
    // Initialize distances and visited array
    for (int i = 0; i < 6; ++i) 
    {
        dist[i] =100000;
        visited[i] = false;
    }
    
    //For source city distance is 0
    dist[source] = 0;
    
    //Finding shortest path for  cities
    for (int count = 0; count < 6 - 1; ++count) 
    {
        int u = minDistance(dist, visited);
        visited[u] = true;
        
        // Update distances of adjacent cities
        for (int v = 0; v < 6; ++v) 
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    //To print shortest dist
    printShortestDistances(dist);
}

int main()
{
    int graph[6][6] = 
    {
        { 0, 10,  0,  0, 15,  5},
        {10,  0, 10, 30,  0,  0},
        { 0, 10,  0, 12,  5,  0},
        { 0, 30, 12,  0,  0, 20},
        {15,  0,  5,  0,  0,  0},
        { 5,  0,  0, 20,  0,  0}
    };
    
    for (int i = 0; i < 6; i++)
    {
        int source = i;
        dijkstra(graph, source);
    }
    
    return 0;
}
