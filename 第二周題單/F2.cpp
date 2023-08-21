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

int n;
vector<pair<int, pair<int, int>>> node;
ll dp[17][1 << 17];

ll dis(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return (abs(b.first - a.first) + abs(b.second.first - a.second.first) + max(0, b.second.second - a.second.second));
}

int main()
{
    cin >> n;
    for(int i = 0, a, b, c; i < n; i++){
        cin >> a >> b >> c;
        node.push_back({a, {b, c}});
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (1 << n); j++){
            dp[i][j] = 1e18;
        }
    }
    // memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & 1 && i != (1 << n) - 1) continue; // 走過起點但未走完全部點則跳過，不跳過的情況是算答案的時候
            if((i >> j) & 1){ // 當i要走的點和j都表示同一個點的時候
                for(int k = 0; k < n; k++){ // 計算k到j是否比較小
                    dp[j][i] = min(dp[j][i], dp[k][i - (1 << j)] + dis(node[k], node[j]));
                }
            }
        }
    }
    cout << dp[0][(1 << n) - 1];

	return 0;
}