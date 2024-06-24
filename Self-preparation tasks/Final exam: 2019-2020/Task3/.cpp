#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// disjoint set
// if a Union is successfull -> ccTotal--; 
// in the beginning: ccTotal = |V|

const int MAX = 1000000;

int parents[MAX];
int depths[MAX];

void fillParents(int V)
{
   for (int i = 0; i<V; i++)
   {
       parents[i] = i;
       depths[i] = 1;
   }
}

int Find(int x)
{
    if (x==parents[x])
    {
        return x;
    }
    return parents[x] = Find(parents[x]);
}

bool Union(int x, int y)
{
    int root1 = Find(x);
    int root2 = Find(y);
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


int main() 
{
    int T;
    cin>>T;
    for (int i = 0; i<T; i++)
    {
        int V, E;
        cin>>V>>E;
        int ccTotal = V;
        fillParents(V);
        for (int i = 0; i<E; i++)
        {
            int from, to;
            cin>>from>>to;
            if (Union(from, to))
            {
                ccTotal--;
            }
        }
        cout<<ccTotal<<" ";
    }
}
