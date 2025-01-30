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

int isgood(int num,int k)
{
	if(k==0)
		return 1;

	set<int> digits;
    while (num > 0) {
        int digit = num % 10;
        if (digit > k) {
            return 0; 
        }
        digits.insert(digit);
        num /= 10;
    }
    
    for (int i = 0; i <= k; i++) {
        if (digits.find(i) == digits.end()) {
            return 0; 
        }
    }
    return 1;
}
void solve(){
	int n,k;
	while (cin >> n) { // Remove k loop
        int res = 0;
        set<int> S;

        for (int j = 0; j <= k; ++j) {
            int x;
            cin >> x;
            while (x != 0) {
                if (S.count(x % 10)) {
                    break;
                }
                S.insert(x % 10);
                x /= 10;
            }

            res += (!S.size() ? 1 : 0);

            cout << res << '\n';
        }
    }

    return res;
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