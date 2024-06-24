#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> subseq;


int main()
{
    int M;
    cin>>M;
    vector<int> arr;
    for (int i = 0; i<M; i++)
   {
       int n;
       cin>>n;
       arr.push_back(n); 
    }
    
    int maxLength = 0;
    
    int start = 0;
    int size;
    
    for (int i = 0; i<M; i++)
    {       
        if (subseq.find(arr[i])==subseq.end() || subseq[arr[i]] < start)
        {
            subseq[arr[i]] = i;
            //maxLength = max(maxLength, (subseq[arr[i]] - start));
        }
        else
        {
            size = i - start;
            maxLength = max(maxLength, size);
            
            start = subseq[arr[i]] + 1;
            
            subseq[arr[i]] = i;
            
                  
        }       
    }
    maxLength = max(maxLength, M - start);
    cout<<maxLength;
}
