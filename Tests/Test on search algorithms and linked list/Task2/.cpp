#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void binarySearch(vector<pair<size_t, size_t>>& arr, size_t& left, size_t& right, size_t X)
{
    while(left<right)
    {
        size_t sum = arr[left].first +arr[right].first;
        if (sum<X)
        {
            left = left+1;
         }
        else if (sum>X)
        {
            right = right-1;
        }
        else
        {
            break;
        }
    }
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    size_t T;
    cin>>T;
    
    for (size_t i = 0; i<T; i++)
    {
        size_t X, N;
        vector<pair<size_t, size_t>> arr;
        cin>>X;
        cin>>N;
        
        for (size_t i = 0; i<N; i++)
        {
            size_t n;
            cin>>n;
            pair<size_t, size_t> newPair;
            newPair.first = n;
            newPair.second = i+1;
            arr.push_back(newPair);
        }
       
        sort(arr.begin(), arr.end());
        size_t left = 0;
        size_t right = arr.size()-1;
        
        binarySearch(arr,  left, right,  X);
        size_t ind1 = arr[left].second;
        size_t ind2 = arr[right].second;
        
        if (ind1> ind2)
        {
            swap(ind1, ind2);
        }
        cout<<ind1<<" "<<ind2<<endl;
        
    }
}
