#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

long long exponents1[100000];
long long exponents2[100000];

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 1;
const int PRIME_NUMBER1 = 997;
const int PRIME_NUMBER2 = 31;

void calculatePowers() 
{
    long long current = 1;
    for (int i = 0; i < 100000; i++) 
    {
       exponents1[i] = current;
       current = (current * PRIME_NUMBER1) % MOD1;
    }

    current = 1;
    for (int i = 0; i < 100000; i++) 
    {
        exponents2[i] = current;
        current = (current * PRIME_NUMBER2) % MOD2;
    }
}


long long rollingHash(long long prevHash, long long length, char removed, char added, long long exponents[], int mod, int primeNumber) 
{
    prevHash = (prevHash - (removed - 'a' + 1) * exponents[length - 1]) % mod;
    if (prevHash < 0)
    {
        prevHash += mod;
    }

    return (prevHash * primeNumber + (added - 'a' + 1)) % mod;
}

long long computeHash(const string& str, long long length, long long exponents[], int mod) {
    long long hashResult = 0;

    for (long long i = 0; i < length; i++) 
    {
        hashResult += (str[i] - 'a' + 1) * exponents[length - 1 - i];
        hashResult %= mod;
    }

    return hashResult;
}

bool hasSubStr(const string& s1, const string& s2, long long length) 
{
    unordered_set<long long> substrings1, substrings2;

    long long currentHash1 = computeHash(s1, length, exponents1, MOD1);
    long long currentHash2 = computeHash(s1, length, exponents2, MOD2);
    substrings1.insert(currentHash1);
    substrings2.insert(currentHash2);
    
    long long firstStrLength = s1.size();
    
    for (long long j = 0; j < firstStrLength - length; j++) 
    {
        currentHash1 = rollingHash(currentHash1, length, s1[j], s1[length + j], exponents1, MOD1, PRIME_NUMBER1);
        substrings1.insert(currentHash1);

        currentHash2 = rollingHash(currentHash2, length, s1[j], s1[length + j], exponents2, MOD2, PRIME_NUMBER2);
        substrings2.insert(currentHash2);
    }

    long long currentS2Hash1 = computeHash(s2, length, exponents1, MOD1);
    long long currentS2Hash2 = computeHash(s2, length, exponents2, MOD2);
    if (substrings1.count(currentS2Hash1) > 0 && substrings2.count(currentS2Hash2) > 0) 
    {
        return true;
    }

    long long secondStrLength = s2.size();
    for (long long j = 0; j < secondStrLength - length; j++) 
    {
        currentS2Hash1 = rollingHash(currentS2Hash1, length, s2[j], s2[length + j], exponents1, MOD1, PRIME_NUMBER1);
        currentS2Hash2 = rollingHash(currentS2Hash2, length, s2[j], s2[length + j], exponents2, MOD2, PRIME_NUMBER2);
        if (substrings1.count(currentS2Hash1) > 0 && substrings2.count(currentS2Hash2) > 0) 
        {
            return true;
        }
    }

    return false;
}


long long findLongestCommonSubstring(const string& s1, const string& s2)
{
    long long left = 0, right = s2.size(), result = 0;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (hasSubStr(s1, s2, mid)) 
        {
            result = mid;
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

  return result;    
}

int main() 
{
    calculatePowers();
    string s1, s2;
    cin >> s1 >> s2;
     
    if (s1.size() < s2.size())
    {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
   
    cout<<findLongestCommonSubstring(s1, s2);
}
