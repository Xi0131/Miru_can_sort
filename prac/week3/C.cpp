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
    int item[n], weight[n];
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> item[i];
    }

    vector<ll> dp[2];
    for(int i = 0; i <= w; i++){
        dp[0].push_back(0);
        dp[1].push_back(0);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= w; j++){
            if(j < weight[i]){
                dp[1][j] = dp[0][j];
            }
            else{
                dp[1][j] = max(dp[0][j], dp[0][j-weight[i]] + item[i]);
            }
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][w];

	return 0;
}