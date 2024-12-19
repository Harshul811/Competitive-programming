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

bool istrue(vector<vector<int>>& M, int n) 
{
    vector<int> r = M[0];
    vector<int> c(n);
    
    for (int j = 0; j < n; ++j) {
        c[j] = 1 - r[j];
    }

    for (int i = 1; i < n; ++i) {
        if (M[i] != r && M[i] != c) {
            return false;
        }
    }

    return true;
}

void solve(){
	int n;
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> M[i][j];
        }
    }

    if (istrue(M, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
   
}
int main()
{
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++) {
	//cout << "Case #" << it << ": ";
		solve();
	}
	return 0;
}