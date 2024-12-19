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
	int n, k;
    cin >> n >> k;
    
    vector<int> d(n);
    vector<vector<int>> layers(n);  
    vector<pair<int, int>> edges;
    vector<int> degree(n + 1, 0); 

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        layers[d[i]].push_back(i + 1); 
    }

    int ans=-1;

    if (layers[0].size() != 1) {
        cout << -1 << endl;
        return;
    }

    // for(auto l : layers)
    // {
    // 	for(int i=0;i<l.size();i++)
    // 		cout<<l[i]<<" ";
    // 	cout<<endl;
    // }

    for (int dist = 1; dist < n; ++dist) 
    {

        int idx = 0;
        for (int node : layers[dist]) 
        {
            while (idx < layers[dist - 1].size()) 
            {
                int parent = layers[dist - 1][idx];
                if (degree[parent] < k && degree[node] < k) 
                {
                    edges.push_back({min(parent, node),max(parent, node)});
                    degree[parent]++;
                    degree[node]++;
                    break; 
                }
                idx++;
            }

            if (idx >= layers[dist - 1].size() && degree[node] < k) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << edges.size() << endl;
    sort(all(edges));

    for (auto &edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

   
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