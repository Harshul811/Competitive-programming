#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const int MAX_N = 1e3 + 7;
int a[MAX_N];

void solve() {
	int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> ops;


    for (int b = 22; b >= 0; --b) {
	    for (int i = 0; i < n - 1; ++i) {
	        if (a[i + 1] >= (1 << (b + 1))) break;
	        if (!(a[i] & (1 << b))) continue;

	        if (!(a[i + 1] & (1 << b))) {
	            ops.push_back({i + 1, i});
	            a[i + 1] ^= a[i];
	        }
	        ops.push_back({i, i + 1});
	        a[i] ^= a[i + 1];
	    }
	}

    cout << ops.size() << endl;
    for (auto op : ops) {
        cout << op.first + 1 << " " << op.second + 1 << endl;
    }

    // for(auto k:a)
    // 	cout<<k<<" ";
}

int main() {
    fast_cin();
    ll t=1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
