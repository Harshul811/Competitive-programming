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


struct Position {
    ll x, y, moves;
};

void solve() {
	ll x0, y0, x1, y1, k;
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> k;
    set<pair<ll,ll>> allowed_cells;

    for (ll i = 0; i < k; ++i) {
        ll r, a, b;
        cin >> r >> a >> b;
        for(ll j=a;j<=b;j++){
        	allowed_cells.insert({r, j});
        }
    }

    queue<Position> q;
    set<pair<ll, ll>> visited;
    q.push({x0, y0, 0});
    visited.insert({x0, y0});

    ll ans=-1;

    vector<pair<ll, ll>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    while (!q.empty()) 
    {
        auto q1 = q.front();
        q.pop();

        ll x=q1.x;
        ll y=q1.y;
        ll moves=q1.moves;

        if (x == x1 && y == y1) {
            ans=moves;
        }

        for (auto d : directions) {

            ll nx = x + d.first;
            ll ny = y + d.second;
            if (visited.find({nx, ny}) == visited.end() && allowed_cells.find({nx,ny}) != allowed_cells.end()) {
                        visited.insert({nx, ny});
                        q.push({nx, ny, moves + 1});
            }
        }
    }

    cout << ans << endl;
    
}



// void solve()
// {
// 	ll x0, y0, x1, y1, n;
//     cin >> x0 >> y0 >> x1 >> y1;
//     cin >> n;

//     map<ll, vector<pair<ll, ll>>> allowed_cells;

    
//     for (ll i = 0; i < n; ++i) {
//         ll r, a, b;
//         cin >> r >> a >> b;
//         allowed_cells[r].push_back({a, b});
//     }

//     queue<Position> q;
//     set<pair<ll, ll>> visited;
//     q.push({x0, y0, 0});
//     visited.insert({x0, y0});
//     ll ans=-1;

//     vector<pair<ll, ll>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

//     while (!q.empty()) 
//     {
//         auto q1 = q.front();
//         q.pop();

//         ll x=q1.x;
//         ll y=q1.y;
//         ll moves=q1.moves;

//         if (x == x1 && y == y1) {
//             ans=moves;
//         }

//         for (auto d : directions) {
//             ll nx = x + d.first;
//             ll ny = y + d.second;
//             if (visited.find({nx, ny}) == visited.end() && allowed_cells.find(nx) != allowed_cells.end()) {
//                 for (auto ny1: allowed_cells[nx]) {
//                 	ll a=ny1.first;
//                 	ll b=ny1.second;
//                     if (a <= ny && ny <= b) {
//                         visited.insert({nx, ny});
//                         q.push({nx, ny, moves + 1});
//                         break;
//                     }
//                 }
//             }
//         }
//     }

//     cout << ans << endl;
   
// }
int main()
{
	fast_cin();
	ll t=1;
	//cin >> t;
	for(int it=1;it<=t;it++) {
	//cout << "Case #" << it << ": ";
		solve();
	}
	return 0;
}