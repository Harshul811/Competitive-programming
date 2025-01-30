#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Problem Statement:
You are tasked with maximizing the revenue of a shop that sells 
`n` types of items. The shopkeeper has `m` customers, each of whom 
will buy exactly one item. 

The price of an item depends on the remaining quantity of that 
item in the shop:
1. Initially, the price of an item is equal to its quantity.
2. Each time an item is sold, its quantity decreases by 1, and 
   its price becomes equal to the new quantity.

Your goal is to determine the maximum revenue the shopkeeper can 
earn by selling items to all `m` customers.

Input:
- `n`: The number of item types.
- `m`: The number of customers.
- `quantity`: A vector of integers where `quantity[i]` is the 
  initial stock of the `i-th` item.

Output:
- An integer representing the maximum revenue.

Example:
Input: 
n = 3, m = 4
quantity = [3, 2, 1]

Output:
11

Explanation:
The shopkeeper sells items in this order:
1. Sell 1 item from the stock with quantity 3 (price 3).
2. Sell 1 item from the stock with quantity 2 (price 2).
3. Sell 1 item from the stock with quantity 2 (price 2).
4. Sell 1 item from the stock with quantity 1 (price 1).

Total revenue = 3 + 2 + 2 + 1 = 11.
*/

long long maximizeans(int n, int m, vector<int>& quantity) {
    priority_queue<int> q;
    for (int a : quantity) q.push(a);

    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int cp = q.top();
        q.pop();
        ans += cp;
        if (cp - 1 > 0) q.push(cp - 1);
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> quantity(n);
    for (int i = 0; i < n; ++i) cin >> quantity[i];
    cout << maximizeans(n, m, quantity) << endl;
    return 0;
}
