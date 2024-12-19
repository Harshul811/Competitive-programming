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


struct E {
    ld p; 
    int t;
};

bool operator<(const E& a, const E& b) {
    return a.p < b.p;
}

bool canMeet(vector<pair<ll, ll>>& s, ld t, ll k, ll L) {
    vector<E> ev;

    for (auto& p : s) 
    {
        ld l = p.first - t * p.second;
        ld r = p.first + t * p.second;
        if (l < 0) l = 0;
        if (r > L) r = L;
        // cout<<l<<" values "<<r<<endl;

        ev.push_back({l, +1});
        ev.push_back({r, -1});
    }

    sort(ev.begin(), ev.end());
    // for(auto e:ev)
    // 	cout<<e.p<<" "<<e.t<<endl;

    vector<E> mergedEv;

    for (const auto& e : ev) {
        if (mergedEv.empty() || mergedEv.back().p != e.p) {
            mergedEv.push_back(e);
        } else {
            mergedEv.back().t += e.t;
        }
    }
    for(auto e:mergedEv)
    	cout<<e.p<<" "<<e.t<<endl;

    ll cnt = 0;
    for (auto e : mergedEv) {
        cnt=cnt+e.t;
        //cout<<cnt<<endl;
        if(cnt<k && e.p!=L)
        	return false;
    }

    return true;
}
void solve(){
	ll N;
    ll L;
    ll K;
    cin >> N >> L >> K;

    vector<pair<ll, ll>> s(N);
    for (auto& p : s) {
        cin >> p.first >> p.second;
    }

    ld l = 0.0, h = 1e9;
    while (h - l > 1e-7) 
    {
        ld mid = (l + h) / 2;
        if (canMeet(s, mid, K, L)) 
        {
            h = mid;
            // cout<<mid<<endl<<endl;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(8) << l << endl;
   
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