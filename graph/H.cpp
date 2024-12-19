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
const ll max_cost = 1e10;

void solve()
{
	int n;
    cin >> n;
    
    vector<ll> h(n);
    for (int i = 0; i < n; i++) 
        cin >> h[i];
    
    //2^n*n
    vector<vector<ll>> dp(1 << n, vector<ll>(n, max_cost));
    dp[1][0] = 0; 

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int last = 0; last < n; ++last) {
            if (mask & (1 << last)) { 
                for (int next = 0; next < n; ++next) {
                    if (!(mask & (1 << next))) {
                        ll cost = abs(last - next) * abs(h[last] - h[next]);
                        dp[mask | (1 << next)][next] = min(dp[mask | (1 << next)][next], dp[mask][last] + cost);
                    }
                }
            }
        }
    }

    ll min_cost = max_cost;
    int fm = (1 << n) - 1;
    for (int last = 1; last < n; ++last) {
        ll cost_to_start = abs(last - 0) * abs(h[last] - h[0]);
        min_cost = min(min_cost, dp[fm][last] + cost_to_start);
    }
    cout << min_cost << endl;

    vector<int> path;
    int mask = fm, last = -1;

    for (int j = 1; j < n; ++j) {
        if (min_cost == dp[fm][j] + abs(j - 0) * abs(h[j] - h[0])) {
            last = j;
            break;
        }
    }

    while (mask > 0) {
        path.push_back(last + 1); 
        int pm = mask ^ (1 << last);
        for (int j = 0; j < n; ++j) {
            if (pm & (1 << j)) { 
                if (dp[mask][last] == dp[pm][j] + abs(last - j) * abs(h[last] - h[j])) {
                    last = j;
                    break;
                }
            }
        }
        mask = pm;
    }



    reverse(path.begin(), path.end());
    path.push_back(1);
    for (int i : path) {
        cout << i << ' ';
    }
    cout << endl;
    
    
}   
int main()
{
	fast_cin();
	ll t=1;
	// cin >> t;
	for(int it=1;it<=t;it++) {
	//cout << "Case #" << it << ": ";
		solve();
	}
	return 0;
}