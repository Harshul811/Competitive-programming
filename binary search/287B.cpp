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

ll n,k;
int isgood(ll x)
{
	// ll q=0;
	// q+=k;
	// for(int i=2;i<=x;i++)
	// {
	// 	q+=k-(i);
	// }
	
	ll q = k * x - (x * (x + 1)) / 2 + 1;

	if(q==n)
		return 1;
	if(q<n)
		return 2;
	if(q>n)
		return 3;

	return -1;
}
void solve(){
	
	cin>>n>>k;

	if(n==1)
	{
		cout<<0<<endl;
		return;
	}

	ll l=1;
	ll r=k-1;
	ll ans=-1;

	while(l<=r)
	{
		ll mid=(l+r)/2;

		if(isgood(mid)==1)
		{
			r=mid-1;
			// cout<<mid<<endl;
			ans=mid;
		}
		else if(isgood(mid)==2)
		{
			l=mid+1;
		}
		else if(isgood(mid)==3)
		{
			r=mid-1;
			ans=mid;
		}
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