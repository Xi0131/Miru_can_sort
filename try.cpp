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
const int MAXN = 2e6 + 5;

void check(int x, vector<bool> &vis, vector<vector<int>> &g, vector<bool> &see, int take){
    vis[x] = 1;
    if(take == 1) see[x] = 1;
    for(int i : g[x]){
        if(vis[i]) continue;
        if(take == 1) check(i, vis, g, see, 0);
        else check(i, vis, g, see, 1);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> coin(n+1);
        for(int i = 1; i <= n; i++) cin >> coin[i];
        vector<vector<int>> g;
        g.resize(n+1);
        for(int i = 0, a, b; i < n-1; i++){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> vis(n+1, 0), take(n+1, 0);
        vector<int> rt = coin, bt = coin;
        check(1, vis, g, take, 1);
        ll red = 0, blk = 0;
        for(int i = 1; i <= n; i++){
            if(coin[i] > 0)
                if(take[i] == 1){
                    red += coin[i];
                    for(int j = 0; j < g[i].size(); j++){
                        rt[j] -= c;
                    }
                }
                else{
                    blk += coin[i];
                    for(int j = 0; j < g[i].size(); j++){
                        bt[j] -= c;
                    }
                }
        }
        watch(red);
        watch(blk);
        ll red1 = 0, blk1 = 0;
        for(int i = 1; i <= n; i++){
            if(take[i] == 0){
                
            }
        }

    }

	return 0;
}