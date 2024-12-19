#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n; 
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<pair<int, int>> ans;

    for (int bit = 21; bit >= 0; bit--) {
        for (int i = 0; i + 1 < n; i++) {
            if (arr[i] & (1LL << bit)) {
                if (arr[i + 1] & (1LL << bit)) {
                    ans.push_back({i + 1, i + 2});
                    arr[i] ^= arr[i + 1];
                } else {
                    ans.push_back({i + 2, i + 1});
                    ans.push_back({i + 1, i + 2});
                    arr[i + 1] ^= arr[i];
                    arr[i] ^= arr[i + 1];
                }
            }
        }
        if (n >= 1 && (arr[n - 1] & (1LL << bit))) {
            n--;
        }
    }

    cout << ans.size() << endl; 
    for (const auto& operation : ans) {
        cout << operation.first << " " << operation.second << endl; 
    }
}

int main() {
    fast_cin();
    ll t=1;
    //cin >> t;
    for (int it = 1; it <= t; it++) {
        // cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}
