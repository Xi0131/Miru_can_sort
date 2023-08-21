#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int maxn = 200005;

int n, q;
vector<vector<int>> adj, anc;
int parent[maxn][20];
vector<int> d;

int t = 0;

void build(int cur, int pre){
    for(int i : adj[cur]){
        if(i == pre) continue;
        parent[i][0] = cur;
        d[i] = d[cur] + 1;
        build(i, cur);
    }
}

int lca(int a, int b){
    int x = d[a], y = d[b];
    if(x > y) swap(a, b), swap(x, y);
    int diff = y - x;
    for(int i = 0; i < 20; i++){
        if(diff & (1 << i)){
            b = parent[b][i];
        }
    }
    if(a == b) return b;
    for(int i = 19; i >= 0; i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int main()
{
    cin >> n >> q;
    adj.resize(n+1);
    d.resize(n+1);
    for(int i = 0, a, b; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build(1, 0);
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << d[a] + d[b] - d[lca(a, b)] * 2 << endl;
    }

	return 0;
}