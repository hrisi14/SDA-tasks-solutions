#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


void dfs(long long v, long long& ccNum, long long& counter, unordered_map <long long, vector<long long>>& graph, vector<bool>& visited, vector<long long>& cc)
{
    visited[v] = true;  
    counter++;
    cc[ccNum] = counter;  
    
    for (const auto& w : graph[v])
    {        
        if (!visited[w])
        {
          dfs(w, ccNum, counter, graph, visited, cc);
        }
   }
}

void connectedComponents(unordered_map <long long, vector<long long>>& graph, long long& N, long long& ccNum, vector<bool>& visited, vector<long long>& cc)
{    
    for (long long i = 1; i<=N; i++)
    {
       if (!visited[i])
         {
            long long counter = 0;
            dfs(i, ccNum, counter, graph, visited, cc);
            ccNum++;          
        }
    }
}

long long finalSum(long long& N, long long& M, long long& K, long long& L, long long& ccNum, vector<long long>& cc)
{
    long long result = 0;

    for (long long i = 0; i < ccNum; i++)
    {
        long long totalPriceForDiskos = cc[i] * K;
        long long totalPriceForPaths = (cc[i] - 1) * L + K;

        result += min(totalPriceForDiskos, totalPriceForPaths);
  }
    return result;
    
}


int main()
{
    long long Q, N, M, K, L;
    cin >> Q;

    vector <long long> result;

    for (long long i = 0; i < Q; i++)
    {
        cin >> N >> M >> K >> L;
        
        unordered_map<long long, vector<long long>> g;
        vector<bool> visited(N+1, false);
        vector<long long> cc (N+1, 0);
  
        long long ccNum = 0;      

        for (long long j = 0; j < M; j++)
        {
            long long x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);            
       }
        connectedComponents(g, N, ccNum, visited, cc);
        result.push_back(finalSum(N, M, K, L, ccNum, cc));       
}
    
    size_t vSize = result.size();
    
    for (long long i = 0; i < vSize; i++)
    {
        cout << result[i] << endl;
    }
}
