#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;


void solve(){
    // input
    ll n, m;    cin >> n >> m;
    vector<ll> adj[n+1];
    vector<ll> id(n+1);

    while(m--){
        ll u, v;    cin >> u >> v;
        adj[u].push_back(v);
        id[v]++;
    }
    unordered_set<ll> topo;

    vector<ll> par(n+1, -1);
    queue<ll> bfs;

    for (ll i = 2; i<=n; i++){
        if (id[i] == 0) bfs.push(i);
    }
    // end of input

    // while any edge-in of a point = 0, exclude it from graph (not needed)
    while(bfs.size()){
        ll u = bfs.front();     bfs.pop();
        topo.insert(u);
        for (auto v: adj[u]){
            id[v]--;
            if (id[v] == 0) {
                bfs.push(v);
                par[v] = u;
            }
        }
    }

    // if nothing to search, end
    if (id[n] == 0 and topo.find(1) == topo.end())  {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // if there is thing to search, search from 1
    bfs.push(1);

    while(bfs.size()){
        ll u = bfs.front();     bfs.pop();
        topo.insert(u);
        for (auto v: adj[u]){
            id[v]--;
            if (id[v] == 0) {
                bfs.push(v);
                par[v] = u;
            }
        }
    }


    if (par[n] == -1)     cout << "IMPOSSIBLE\n";
    else{
        vector<ll> temp;
        temp.push_back(n);
        while(temp.back() != 1){
            temp.push_back(par[temp.back()]);
        }
        reverse(temp.begin(), temp.end());

        cout << temp.size() << endl;
        for (auto &i: temp){
            cout << i << " ";
        }
    }
}

int main()
{
    solve();

	return 0;
}