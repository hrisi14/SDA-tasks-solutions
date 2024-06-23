#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const unsigned MAX = 1000;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned N;
    cin >> N;
    vector<int> arr;
    vector <int> copy;
    for (unsigned i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        arr.push_back(number);    
        copy.push_back(number);
    }    
    int firstIndex = 0;
    int secondIndex = 0;
    
    sort(copy.begin(), copy.end());
    
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != copy[i])
        {
            firstIndex = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i] != copy[i])
        {
            secondIndex = i;
            break;
        }
    }

    if (firstIndex==0 && secondIndex==0)
    {
        cout<<0;
    }
    else
    {
        cout << secondIndex - firstIndex + 1;
}
    }
    
