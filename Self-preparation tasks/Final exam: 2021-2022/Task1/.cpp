#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;


int main() 
{   
    int N, M;
    cin>>N>>M;
    int unique = 0;

    vector<vector<int>> matrix(N, vector<int>(M));
    map<vector<int>, int> rows;
    
    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<M; j++)
        {
            cin>>matrix[i][j];
        }
        rows[matrix[i]]++;
   }
   
     for (auto iter = rows.begin(); iter != rows.end(); iter++)
    {
        if (iter->second==1)
        {
            unique++;
        }
    }
    cout<<(unique)<<endl;
}
