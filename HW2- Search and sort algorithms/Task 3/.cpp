#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned N;
    cin>>N;
    
    vector<pair<pair<double, int>, int>> v;
    
    for (unsigned i = 0; i<N; i++)
    {
        double di;
        double ti;
        cin>>di;
        cin>>ti;
        
        double r = di/2;
        double coeff = (r*r)/ti;
        
        pair<double, int> p1;
        p1.first = coeff;
        p1.second = di;
        pair<pair<double, int>, int> newP;
        newP.first = p1;
        newP.second = i;
        v.push_back(newP);        
    }
    
    sort(v.rbegin(), v.rend());
    for(unsigned i = 0; i<N; i++)
    {
        cout<<v[i].second+1<<" ";
    }
}
