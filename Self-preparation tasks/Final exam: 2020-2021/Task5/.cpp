#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

multiset<int> numbers;
queue <int> q; 

int main() 
{
    int K, T, B, Q;
    cin>>K>>T>>B>>Q;
    
    
    for (int i = 1; i<=Q; i++)
    {
        int req;
        cin>>req;
        numbers.insert(req);
        
        if (i%T==0 && B!=0)
        {
            int size = numbers.size();
            if (size>=K)
            {
                B--;
                for (int j = 0; j<K; j++)
                {
                    q.push(*numbers.begin());
                   numbers.erase(numbers.begin());
                }
            }
        }
    }
    while (B)
    {
        if (numbers.size()>=K)
            {
                B--;
                for (int j = 0; j<K; j++)
                {
                     q.push(*numbers.begin());
                    numbers.erase(numbers.begin());
                }
            }
    }
    
    while (!q.empty())
    {
       cout<<q.front()<<" ";
        q.pop();
    }
    
    //managing tasks according to groups
   /*int startIndex = 0;   
    
    for (int i = 0; i<B - 1; i++)
    {
        partial_sort(requests.begin(),  requests.begin() + (startIndex + T)/2, requests.end());
        
        for (int j = startIndex; j<startIndex + K; j++)
      {
            pq.push(requests[j]);
            erasedEl.push_back(requests[i]);                      
        }
        startIndex+=T;    
    }
    
    for (size_t i = 0; i<erasedEl.size(); i++)
    {
         remove(requests.begin(), requests.end(), erasedEl[i]);  
    }
    
    sort(requests.begin(), requests.end());
    for (int i = 0; i<K; i++)
    {
        pq.push(requests[i]);
    }
    
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }*/
    
}
