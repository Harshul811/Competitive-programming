#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const ll INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<vector<ll>> cost(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = abs(i - j) * abs(h[i] - h[j]);
        }
    }

    // Dijkstra's algorithm initialization
    vector<ll> min_cost(1 << n, INF);
    vector<int> parent(1 << n, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    min_cost[1] = 0; // Starting at skyscraper 1
    pq.push({0, 1}); // (cost, mask)

    while (!pq.empty()) {
        auto [current_cost, mask] = pq.top();
        pq.pop();

        for (int next = 0; next < n; next++) {
            if (!(mask & (1 << next))) { // If next skyscraper is not visited
                int next_mask = mask | (1 << next);
                ll jump_cost = cost[__builtin_ctz(mask)][next];
                if (min_cost[next_mask] > current_cost + jump_cost) {
                    min_cost[next_mask] = current_cost + jump_cost;
                    parent[next_mask] = mask;
                    pq.push({min_cost[next_mask], next_mask});
                }
            }
        }
    }

    ll min_energy = INF;
    int final_mask = (1 << n) - 1;
    for (int last = 1; last < n; last++) {
        ll return_cost = cost[last][0]; // Cost to return to the starting skyscraper
        min_energy = min(min_energy, min_cost[final_mask] + return_cost);
    }

    cout << min_energy << endl;

    // Backtrack to find the path
    vector<int> path;
    int mask = final_mask, last = -1;

    while (mask > 0) {
        path.push_back(__builtin_ctz(mask));
        last = mask;
        mask = parent[mask];
    }

    reverse(path.begin(), path.end());
    path.push_back(0); // Add the starting point

    for (int i : path) {
        cout << i + 1 << ' '; // Output 1-based index
    }
    cout << endl;
}

int main() {
    fast_cin();
    int t = 1;
    for (int it = 1; it <= t; it++) {
        solve();
    }
    return 0;
}
