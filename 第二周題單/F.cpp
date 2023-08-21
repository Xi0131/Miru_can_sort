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
        node.push_back({--a, {--b, --c}});
    }
    for(int i = 1; i < n; i++){
        dp[i][1] = dis(node[0], node[i]);
    }
    for(int i = 1; i < (1 << n); i++){
        for(int j = 1; j < n; j++){
            if(!dp[j][i]) continue;
            for(int k = 1; k < n; k++){
                dp[k][i ^ (1 << j)] = min(dp[k][i ^ (1 << j)], dp[j][i] + dis(node[j], node[k]));
            }
        }
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 1; i < n; i++){
        pq.push(dp[i][(1 << (n - 1)) - 1] + dis(node[i], node[0]));
    }
    cout << pq.top();

	return 0;
}