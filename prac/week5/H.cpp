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
const int MAXN = 1e5 + 5;

ll dp0[MAXN], dp1[MAXN], l[MAXN], r[MAXN];
bool vis[MAXN];

void dfs(int x, int pa, vector<vector<int>> &vec){
    if(vis[x]) return;
    vis[x] = 1;
    for(int u : vec[x]){
        if(u != pa){
            dfs(u, x, vec);
            dp0[x] += max(abs(l[x] - l[u]) + dp0[u], abs(l[x] - r[u]) + dp1[u]);
            dp1[x] += max(abs(r[x] - l[u]) + dp0[u], abs(r[x] - r[u]) + dp1[u]);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    fill(vis, vis + n + 1, 0);
    fill(dp0, dp0 + n + 1, 0);
    fill(dp1, dp1 + n + 1, 0);
    vector<vector<int>> vec(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    for(int i = 0, a, b; i < n - 1; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1, -1, vec);
    cout << max(dp0[1], dp1[1]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

	return 0;
}