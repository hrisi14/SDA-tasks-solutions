#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10^6;
struct Edge
{
    int from;
   int to;
};

vector<long long> parents;
vector<long long> depths;
long long ccNumber;

void fillParents(int V)
{
    parents.resize(V+1);
    depths.resize(V+1, 0);
    
   for (long long i = 1; i<V; i++)
   {
       parents[i] = i;
   }
}

long long Find(long long x)
{
    if (x==parents[x])
    {
        return x;
    }
    return parents[x] = Find(parents[x]);
}

bool Union(long long x, long long y)
{
    long long root1 = Find(x);
    long long root2 = Find(y);
    if (root1==root2)
    {
        return false;
    }
    
    if (depths[root1]<depths[root2])
    {
        swap(root1, root2);
    }
    
    if (depths[root1] == depths[root2])
    {
      depths[root1]++;
    }
    parents[root2] = root1;   
    return true;
}

bool checkForNewlyFormedCycle(long long x, long long y)
{
   long long parentX = Find(x); 
   long long parentY = Find(y);
    if (parentX==parentY)
    {
        return true;   //There already is a path between the given vertices. The current new edge forms a cycle.
    }
    return false;
}

int main() 
{
    long long V;
    cin>>V;
    ccNumber = V;
    
    vector<Edge> edges(V);
    fillParents(V);
    
    long long from, to;
    while(cin>>from>>to)
    {      
        bool cycle = false;
        
        if (checkForNewlyFormedCycle(from, to))
        {
            cycle = true;
        }
        if (Union(from, to))
        {
            ccNumber--;
        }
        
        cout<<ccNumber<<" ";
        
        if  (cycle)
        {
           cout<<"CYCLE FORMED!";
        }
        
        cout<<endl;
    }
    
}
