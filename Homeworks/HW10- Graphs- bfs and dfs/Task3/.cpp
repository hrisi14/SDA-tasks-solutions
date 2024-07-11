#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

const int MAX_SIZE = 1000;
bool visited[MAX_SIZE];

unordered_map <char, set<char>> vocabulary;
stack<char> orderedVocabulary;

void dfs(const char& letter)
{
    visited[letter] = true;
    
    if (vocabulary.count(letter))
    {

    for (const auto& neighbour: vocabulary[letter])
    {
          if (!visited[neighbour])
           {
              dfs(neighbour);
            }
        
    }
    }
    orderedVocabulary.push(letter);
}

void topSort()
{
    for (auto letter: vocabulary)
    {
          if (!visited[letter.first]) 
          {
            dfs(letter.first);
        }
        
    }
}

void printSortedVocabulary()
{
    while(!orderedVocabulary.empty())
    {
        cout<<orderedVocabulary.top()<<" ";
        orderedVocabulary.pop();
    }
}

int main() 
{
    size_t N;
    cin>>N;
    
    string s1;
    cin>>s1;
    
    for (size_t i = 1; i<N; i++)
    {
        string s2;
        cin>>s2;
        
        for (size_t j = 0; j<s1.size() && j<s2.size(); j++)
        {
            if (s1[j]!=s2[j])
            {
                vocabulary[s1[j]].insert(s2[j]);
                break;
            }
        }
        s1 = s2;
    }
    
    topSort();
    printSortedVocabulary();
}
