#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map <int, unordered_map<int, int>> graph;


int main() 
{
    int V, E, from, to, weight;
    cin>>V>>E;
    for (int i = 0; i<E; i++)
    {
        cin>>from>>to>>weight;
        graph[from][to] = weight;
        graph[to][from] = weight;
    }
    
    int pathLength = 0;
    int K;
    cin>>K;
    cin>>from;
    for (int i = 1; i<K; i++)
    {
        cin>>to;
      
        if (graph.find(from)!=graph.end() && graph[from].find(to)!=graph[from].end())
        {
           pathLength+=graph[from][to]; 
        }
        else
        {
            cout<<-1<<endl;
            return 0;
        }
        from = to;
    }
    cout<<pathLength<<endl;
    return 0;
}
