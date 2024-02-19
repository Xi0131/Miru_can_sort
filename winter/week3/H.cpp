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
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    vector<ll> dp;
    for(int i = 0; i <= x; i++){
        dp.push_back(0);
    }

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] > i) break;
            else if(arr[j] == i) dp[i]++;
            else{
                dp[i] += dp[i-arr[j]];
            }
        }
        dp[i] %= MOD;
    }
    cout << dp[x];

	return 0;
}