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

void solve()
{
	int  xa, ya, xb, yb;
	cin>> xa>>ya>> xb>> yb;

	set<pair<int,int>> v;
	for(int x=min(xa,xb);x<=max(xa,xb);x++)
	{
		v.insert({x,ya});
		v.insert({x,yb});
	}
	for(int y=min(ya,yb);y<=max(ya,yb);y++)
	{
		v.insert({xa,y});
		v.insert({xb,y});
	}

	// for(auto a:v)
	// {
	// 	cout<<a.first<<" "<<a.second<<endl;
	// }

	int n;
	cin>>n;
	// cout<<n<<endl;

	for(int f=1;f<=n;f++)
	{
		double xi=0,yi=0,ri=0;
		cin>>xi>>yi>>ri;
		vector<pair<int, int>> to_remove;

		for(auto a:v)
		{
			double d= sqrt((xi-a.first)*(xi-a.first)+(yi-a.second)*(yi-a.second));
			if(d<=ri)
			{
				to_remove.push_back(a);
			}
		}

		for (auto a : to_remove) {
            v.erase(a);
        }

	}

	cout<<v.size()<<endl;
   
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