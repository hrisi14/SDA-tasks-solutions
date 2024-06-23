#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<iomanip>
using namespace std;

priority_queue <double, vector<double>, greater<double>> minHeap;
priority_queue<double> maxHeap;

void insert(int num)
{
   if (maxHeap.empty() || maxHeap.top()>num)
   {
       maxHeap.push(num);
   }
    else
    {
        minHeap.push(num);
    }
    
    if (maxHeap.size()>minHeap.size()+1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
     }
    else if (minHeap.size()>maxHeap.size()+1)
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
     }
}

double findMed()
{
    if (maxHeap.size()==minHeap.size())
    {
        if (maxHeap.empty())
        {
            return 0;
         }
        
        return (maxHeap.top() + minHeap.top())/2;
     }
    
    if (maxHeap.size()>minHeap.size())
    {
        return maxHeap.top();
    }
    return minHeap.top();
}


int main() 
{
    cout<<fixed<<setprecision(1);   
   long long N;
    cin>>N;
    for (long long i = 0; i<N; i++)
    {
        double num;
        cin>>num;
        insert(num);
        cout<<findMed()<<endl;
    }
    
    
    
}
