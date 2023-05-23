#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//defining no. of vetices
int V = 6;

//Setting the adjacent matrix as a 2D array
vector <vector<int>> G = {
  {0,3,0,0,0,1},
  {3,0,2,1,10,0},
  {0,2,0,3,0,5},
  {0,1,3,0,5,0},
  {0,10,0,5,0,4},
  {1,0,5,0,4,0}};

int main() {
    int no_edge = 0;  
    int choose[V];

    memset(choose, false, sizeof(choose));

    no_edge = 0;
    choose[0] = true;
    //for rows and columns number
    int x,y;  
    cout << "edge_1,edge_2,weight"<< endl;

    while (no_edge < V - 1)
    {
        int min = 1000000;
        x = 0;
        y = 0;

        for (int row = 0; row < V; row++) 
        {
            if (choose[row]) 
            {
                for (int column = 0; column < V; column++) 
                {
                    if (!choose[column] && G[row][column]) 
                    {  
                        if (min > G[row][column]) 
                        {
                            min = G[row][column];
                            x = row;
                            y = column;
                        }
                    }
                }
            }
        }
        cout << x << ",     " << y << ",     " << G[x][y];
        cout << endl;
        choose[y] = true;
        no_edge++;
    }

  return 0;
}
