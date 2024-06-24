#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numbersCounter(vector<int>& x, int number)
{
    int counter = lower_bound(x.begin(), x.end(), number) - x.begin();
    
    return counter;
}

int main() 
{
    int size1, size2;
    cin>>size1>>size2;
    
    vector<int> x;
    vector<int> y;
    
    for (int i = 0; i<size1; i++)
    {
        int n;
        cin>>n;
        x.push_back(n);
    }
    sort(x.begin(), x.end());
     for (int i = 0; i<size2; i++)
    {
        int n;
        cin>>n;
        y.push_back(n);
    }
    
    size_t size = y.size();
    for (int i = 0; i<size2; i++)
    {
        cout<<numbersCounter(x, y[i])<<" ";
    }
}
