#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>

using namespace std;
const int MAX_SIZE_OF_ARR = 1000000;

unordered_map <int, vector<int>> myGraph;

    void bfs(int v, int* distance, unordered_map <int, vector<int>>& myGraph)
    {
        distance[v] = 0;
        queue <int> traversalOrder;
        traversalOrder.push(v);

        while (!traversalOrder.empty())
        {
            int currentV = traversalOrder.front();
            traversalOrder.pop();

            for (auto neighbour : myGraph[currentV])
            {
                if (distance[neighbour] == INT_MAX)
                {
                    distance[neighbour] = distance[currentV] + 1;
                    traversalOrder.push(neighbour);                  
                }               
            }
        }       
    }

int main()
{
    int V, E;
    cin >> V >> E;

    int newV = V;
    
    for (int i = 0; i < E; i++)
    {
        int v, w, length;
        cin >> v >> w >> length;

        if (length == 1)
        {
            myGraph[v].push_back(w);
            myGraph[w].push_back(v);
        }
        else
        {
            newV++;             
            myGraph[v].push_back(newV);
            myGraph[newV].push_back(v);
            myGraph[newV].push_back(w);
            myGraph[w].push_back(newV);
        }
    }

    int*  distance = new int [100000000];
    for (long long i = 0; i < 100000000; i++)
    {
        distance[i] = INT_MAX;
    }

   int startIndex, endIndex;
    cin >> startIndex >> endIndex;
    bfs(startIndex, distance, myGraph);
    
    if (distance[endIndex]!=INT_MAX)
    {
        cout<<distance[endIndex]<<endl;
    }
     delete [] distance;
}
