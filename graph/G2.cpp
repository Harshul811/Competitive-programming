#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    vector<pair<int, int>> ans;

    for (int i = n - 1; i >= 0; i--) {
        int p = -1;
        for (int j = 0; j <= i; j++) {
            if (p == -1 || arr[p] < arr[j]) p = j;
            if (j) ans.push_back({j - 1, j});
        }
        for (int j = p + 1; j <= i; j++) ans.push_back({j, j - 1});
        for (int j = p - 2; j >= 0; j--) ans.push_back({j, j + 1});
        for (int j = p; j + 1 < n; j++) swap(arr[j], arr[j + 1]);
    }

    for (int i = n - 2; i >= 0; --i) ans.push_back({i, i + 1});

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.first + 1 << ' ' << x.second + 1 << '\n';

    for(auto k:arr)
        cout<<k<<" ";
}

int main() {
    fast_cin();
    ll t = 1;
    // cin >> t; // Uncomment if multiple test cases are needed
    for (int it = 1; it <= t; it++) {
        solve();
    }
    return 0;
}
