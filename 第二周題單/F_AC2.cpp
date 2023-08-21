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
const int maxn = 100005;

const int m = (1 << 17) + 1;
int x[17], y[17], z[17], n;
ll dp[17][m];

ll cost(int a, int b){
    return abs(x[b] - x[a]) + abs(y[b] - y[a]) + max(0, z[b] - z[a]);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & 1 && i != (1 << n) - 1) continue;
            if((i >> j) & 1){
                for(int k = 0; k < n; k++){
                    dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + cost(k, j));
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][0];

	return 0;
}