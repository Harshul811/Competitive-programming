#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given an array `a` of integers and a positive integer `d`, find the number of triplets `(i, j, k)` such that:
1. `i < j < k`
2. `(a[i] + a[j] + a[k]) % d == 0`

Input:
- An array `a` of integers.
- An integer `d` (the divisor).

Output:
- An integer representing the count of such triplets.

Example:
Input: a = [3, 3, 4, 7, 8], d = 5
Output: 4

Explanation:
The valid triplets are:
- (3, 3, 4) -> (3 + 3 + 4) % 5 = 0
- (3, 4, 8) -> (3 + 4 + 8) % 5 = 0
- (3, 3, 8) -> (3 + 3 + 8) % 5 = 0
*/

int divisibleTripletCount(vector<int> a, int d) {
    int n = a.size(), ans = 0;
    unordered_map<int, int> dupletSums;

    for (int k = 1; k < n; k++) {
        int expected = (d - (a[k] % d) + d) % d;
        ans += dupletSums[expected];
        for (int i = 0; i < k; i++) {
            int x = (a[i] + a[k]) % d;
            dupletSums[x]++;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {3, 3, 4, 7, 8};
    int d = 5;
    cout << divisibleTripletCount(a, d) << endl;
    return 0;
}
