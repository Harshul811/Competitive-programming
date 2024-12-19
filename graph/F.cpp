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

bool istrue(vector<pair<ld, ld>> s, ld t) 
{
    ld m1 = -1e18;
    ld m2 = 1e18;

    for (auto p : s) 
    {
        ld x = p.first;
        ld s = p.second;
        m1 = max(m1, x - t * s);
        m2 = min(m2, x + t * s);
    }

    return m1 <= m2;
}
void solve(){
	int N;
    ll L;
    cin >> N >> L;

    vector<pair<ld, ld>> s(N);
    for (auto& p : s) {
        cin >> p.first >> p.second;
    }

    ld l = 0.0, h = 1e9;
    while (h - l > 1e-7) 
    {
        ld mid = (l + h) / 2;
        if (istrue(s, mid)) 
        {
            h = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(7) << l << endl;
   
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