#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAX = 200000;
unordered_map<int, vector<int>> graph;

int counter;

int  dfs(int& startV)
{
    if (graph[startV].size()==0)
    {
        return 0;
    }
    
    int counter = 0;
    for (auto neighbour: graph[startV])
    {
                 
      counter += neighbour + dfs(neighbour);
        
    }
   return counter;
}

int main() 
{
    int m, t;
    cin>>m>>t;
    
    for(int i = 0; i<m; i++)
  {
        int startV, endV;
        cin>>startV>>endV;
        graph[startV].push_back(endV);
     }
    
    vector<int> result;
    
     for(int i = 0; i<t; i++)
  {
        int requestV;
        cin>>requestV;
        counter = 0;
         counter = dfs(requestV);
         result.push_back(counter);
         
         
     }
    
    size_t size = result.size();
    for(size_t i = 0; i<size; i++)
  {
        cout<<result[i]<<endl;
    }
    
}
