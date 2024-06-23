#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
pair <long long, long long> tourist;

class Compare
{
public:
    bool operator() (pair<long long, long long>& left, pair<long long, long long>& right)
    {
        long long distX1 = (tourist.first - left.first) * (tourist.first - left.first);
        long long distY1 = (tourist.second - left.second) * (tourist.second - left.second);

        long long distX2 = (tourist.first - right.first) * (tourist.first - right.first);
        long long distY2 = (tourist.second - right.second) * (tourist.second - right.second);
        
        bool answer = ((distX2 + distY2) < (distX1 + distY1)); 
        
        if (!answer)
        {
            if ((distX2 + distY2) == (distX1 + distY1))
            {
                return left>right;
            }            
        }
        return answer;
    }     
};
int main()
{
    long long X, Y, N, K;
    cin >> X >> Y >> N >> K;

    tourist.first = X;
    tourist.second = Y;

    // koi ne si zaklyuchva laptopa opaa
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, Compare> landmarks;
    for (long long i = 0; i < N; i++)
    {
        int landmarkX;
        int landmarkY;
        cin >> landmarkX >> landmarkY;
        pair<long long, long long> newPair(landmarkX, landmarkY);

        landmarks.push(newPair);
    }
    long long counter = 0;
    while (!landmarks.empty() && counter < K)
    {
        pair <long long, long long> topPair = landmarks.top();

        cout << topPair.first << " " << topPair.second << endl;
        landmarks.pop();

        counter++;
    }
}

