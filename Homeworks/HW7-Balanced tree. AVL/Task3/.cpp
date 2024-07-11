#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

void findMinXor(set<int>& numbers, int addedEl, int& minXor)
{
    auto iter = numbers.find(addedEl);   
  
    if (iter == numbers.begin())
    {         
        minXor = min(minXor, *numbers.begin() ^ *(++numbers.begin())); 
             
   }
    else if (*iter == *(--numbers.end()))
    {
        auto temp = iter;
        --iter;
        int currentMin = *temp ^ *iter;     
       minXor = min(minXor, currentMin);      
  }
    else
    {   
        auto temp1 = iter;
        auto temp2 = iter;
        --temp1;
        minXor = min(minXor, *iter^*temp1);
        
        ++temp2; 
       minXor = min(minXor, *iter^*temp2);    
}
  
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set <int> numbers;

    int Q;
    cin >> Q;
    numbers.insert(0);

    int minXor = INT_MAX;
    
    for (int i = 0; i < Q; i++)
    {
        int n;
        cin >> n;
        numbers.insert(n);      
        findMinXor(numbers, n, minXor);       
     
      cout << minXor << endl;
    }
}
