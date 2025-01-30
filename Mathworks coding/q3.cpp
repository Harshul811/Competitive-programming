#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Problem Statement:
Given an array of strings `strArr` and an array of queries `query`, find the number of strings 
in each query range [l, r] (1-based indexing) such that the string starts and ends with a vowel 
('a', 'e', 'i', 'o', 'u').

Input:
- `strArr`: A vector of strings where each string is non-empty.
- `query`: A vector of strings where each string represents a range in the format "l-r".

Output:
- A vector of integers where each integer represents the count of strings that start and end 
  with vowels in the corresponding query range.

Example:
Input:
    strArr = {"aba", "bcb", "ece", "aa", "e"}
    query = {"1-3", "2-5", "2-2"}

Output:
    2
    3
    0
*/

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

vector<int> hasVowels(vector<string> strArr, vector<string> query) {
    int n = strArr.size();
    vector<int> prefixSum(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int m = strArr[i].size();
        if (isVowel(strArr[i][0]) && isVowel(strArr[i][m - 1])) {
            prefixSum[i + 1] = prefixSum[i] + 1;
        } else {
            prefixSum[i + 1] = prefixSum[i];
        }
    }
    
    vector<int> result;
    for (const string& q : query) {
        size_t dash = q.find('-');
        int l = stoi(q.substr(0, dash));
        int r = stoi(q.substr(dash + 1));
        result.push_back(prefixSum[r] - prefixSum[l - 1]);
    }
    
    return result;
}

int main() {
    vector<string> strArr = {"aba", "bcb", "ece", "aa", "e"};
    vector<string> query = {"1-3", "2-5", "2-2"};
    vector<int> result = hasVowels(strArr, query);
    
    for (int count : result) {
        cout << count << endl;
    }
    return 0;
}
