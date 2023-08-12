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

int n,m,dp[20][1 << 20];
vector<int> g[20];
void solve()
{
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
    }
    dp[0][1] = 1; // 初始狀態
    for(int i = 0; i < (1 << n); ++i)
    {
        for(int u = 0; u < n; ++u)
        {
            if(!dp[u][i]) 
                continue;
            if(i & (1 << u))
            {
                // 有走到 u
                for(auto v: g[u])
                {
                    // 更新 u 能走到的 v
                    dp[v][i ^ (1 << v)] += dp[u][i];
                    dp[v][i ^ (1 << v)] %= MOD;
                }
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1] << '\n';
}

int main()
{
    

	return 0;
}