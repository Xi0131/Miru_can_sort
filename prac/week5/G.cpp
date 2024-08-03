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

int n;
vector<vector<int>> vec;
vector<vector<ll>> dp(MAXN, vector<ll>(2));
vector<bool> vis;

void dfs(int x, int back){
    vis[x] = 1;
    dp[x][0] = 1;
    dp[x][1] = 1;
    for(int u : vec[x]){
        if(!vis[u] && u != back){
            dfs(u, x);
        }
        if(u != back){
            dp[x][0] = (dp[x][0] * (dp[u][0] + dp[u][1])) % MOD;
            dp[x][1] = (dp[x][1] * dp[u][0]) % MOD;
        }
    }
}

int main()
{
    cin >> n;
    if(n == 1){
        cout << 2;
        return 0;
    }
    vec.resize(n+1);
    dp.resize(n+1);
    vis.resize(n+1);
    for(int i = 0, a, b; i < n - 1; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    ll ans;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
            ans = (dp[i][0] + dp[i][1]) % MOD;
        }
    }
    cout << ans;

	return 0;
}