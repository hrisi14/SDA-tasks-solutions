#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAX = 1000000;
unordered_map<int, vector<int>> tree;
long long successors[MAX]{0};

long long dfs(int currentV)
{
    for (auto neighbour: tree[currentV])
    {
        successors[currentV]+=dfs(neighbour);
    }
    return successors[currentV]+1;
}

void printSucc(int V)
{
   for (int i = 0; i<V; i++)
   {
       
         cout<<successors[i]<<" ";
       
   }
}

int main() 
{
    int N;
    cin>>N;
    
    vector<bool> visited(N, false);
    
    for (int i = 0; i<N-1; i++)
    {
        int x, y;
        cin>>x>>y;
        tree[x].push_back(y);
    }
    dfs(0);
    printSucc(N);
    
    /*for(int i=0;i<n;++i) 
    {
        cin>>a>>l>>r;
        nodes[i].val = a;
        if(l != -1) {
            nodes[i].left = &nodes[l];
        } else {
            nodes[i].left = NULL;
        }
        if(r != -1) {
            nodes[i].right = &nodes[r];
        } else {
            nodes[i].right = NULL;
        }
    }*/
}
