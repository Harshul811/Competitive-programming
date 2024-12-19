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


void solve(){
   ll xs, ys, xe, ye;
   ll x1, y1, x2, y2;
   cin >> xs >> ys;
   cin >> xe >> ye;
   cin >> x1 >> y1;
   cin >> x2 >> y2;

    ll distance = abs(xs - xe) + abs(ys - ye);
    ll minX = min(x1, x2);
    ll maxX = max(x1, x2);
    ll minY = min(y1, y2);
    ll maxY = max(y1, y2);

    if ((xs <= minX && xe >= maxX) || (xs >= maxX && xe <= minX)) {
        if (ys > minY && ys < maxY && ye > minY && ye < maxY) {
            ll detour = min(abs(ys - minY) + abs(ye - minY), abs(ys - maxY) + abs(ye - maxY));
            distance = detour+ abs(xs - xe) ;
            
        }
    }
    else if ((ys <= minY && ye >= maxY) || (ys >= maxY && ye <= minY)) {
        if (xs > minX && xs < maxX && xe > minX && xe < maxX) {
            ll detour = min(abs(xs - minX) + abs(xe - minX), abs(xs - maxX) + abs(xe - maxX));
            distance = detour+ abs(ys - ye);
        }
    }

    cout << distance << endl;
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