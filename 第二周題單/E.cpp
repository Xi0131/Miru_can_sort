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

int n, m;
vector<int> adj[20];
ll dp[20][1 << 20];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
    }
    dp[0][1] = 1;
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(!dp[j][i]) continue;
            if(i & (1 << j)){
                for(auto k : adj[j]){
                    dp[k][i ^ (1 << k)] += dp[j][i];
                    dp[k][i ^ (1 << k)] %= MOD;
                }
            }
        }
    }
    cout << dp[n-1][(1 << n) - 1];

	return 0;
}