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

vector<pair<ll,ll>> v;

void solve(){
	int n;
	cin>>n;
	
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll k,a;
		cin>>k>>a;
		ll kmax=0;
		kmax=max(kmax,k);
		v.push_back({k,a});

		ll m=0,s=1;
		while(s<a)
		{
			s=s*4;
			m++;
		}
		//cout<<m<<" "<<s<<" "<<a<<endl;
		ans=max(ans,k+m);

		if(ans==kmax)
			ans++;

	}

	

	cout<<ans<<endl;



   
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