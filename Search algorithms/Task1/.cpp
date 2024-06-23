#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int abs(int n)
{
    if(n<0)
    {
        return -n;
    }
    return n;
}
int twoDiff(vector<int>& nums, int target, int givenNumber)
{
    int counter = 0;
 
    if(binary_search(nums.begin(), nums.end(), givenNumber - target))
    {
        counter++;
    }
        
        if(binary_search(nums.begin(), nums.end(), givenNumber + target))
        {
            counter++;
        }
        return counter;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int N; int D;
   vector<int> T;
    
    cin>>N;
    cin>>D;
    for (int i = 0; i<N; i++)
    {
        int number;
        cin>>number;
        T.push_back(number);
    }
    sort(T.begin(), T.end());  
    int counter = 0;
    
    for (int i = 0; i<N; i++)
    {
          counter+=twoDiff(T, D, T[i]);
        
    }
  
  
  counter/=2;
    cout<<counter;   
    
}
