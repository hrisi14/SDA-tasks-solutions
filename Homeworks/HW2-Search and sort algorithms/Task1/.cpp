#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const unsigned MAX = 1000;

void counting_sort(vector<int>& numbers, int n) 
{
   vector <int> numbers_copy;
    for (int i = 0; i < n; ++i) 
    {
        numbers_copy.push_back(numbers[i]);
    }
    int count[256] = { 0 };
    for (int i = 0; i < n; ++i) 
    {
        count[numbers[i]] = count[numbers[i]] + 1;
    }
    for (int i = 1; i <= 255; ++i) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) 
    {
        numbers[count[numbers_copy[i]] - 1] = numbers_copy[i];
        count[numbers_copy[i]] = count[numbers_copy[i]] - 1;
    }
}


void decode(int& number, char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        number = ch - '0' + 1;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        number = ch - 86;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        number = ch - 28;
    }
}
void encode(int num, char& ch)
{
    if (num >= 1 && num <= 10)
    {
        ch = num + '0' - 1;
    }
    else if (num >= 11 && num <= 36)
    {
        ch = num + 86;
    }
    else if (num >= 37 && num <= 62)
    {
        ch = num + 28;
    }
}


int main()
{
    unsigned N;
    cin >> N;
    vector <char> arr;

    for (unsigned i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        arr.push_back(ch);
    }
    vector<int> numbers;

    for (unsigned i = 0; i < N; i++)
    {
        int num;
        decode(num, arr[i]);
        numbers.push_back(num);
    }
    counting_sort(numbers, N);

    for (unsigned i = 0; i < N; i++)
    {
        encode(numbers[i], arr[i]);
    }

    for (unsigned i = 0; i < N; i++)
    {
        cout << arr[i];
    }

}
