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


int main()
{
    int n, w;
    cin >> n >> w;
    ll item[n], weight[n];
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> item[i];
    }

    vector<ll> dp[2];
    for(int i = 0; i < 100001; i++){
        dp[0].push_back(INF64);
        dp[1].push_back(INF64);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < dp[0].size(); j++){
            if(dp[0][j] != INF64){
                dp[1][j] = min(dp[1][j], dp[0][j]);
                dp[1][j + item[i]] = min(dp[0][j + item[i]], dp[0][j] + weight[i]);
            }
        }
        dp[1][item[i]] = min(weight[i], dp[1][item[i]]);
        swap(dp[0], dp[1]);
    }

    for(int i = dp[0].size() - 1; i >= 0; i--){
        if(dp[0][i] <= w){
            cout << i;
            return 0;
        }
    }

	return 0;
}