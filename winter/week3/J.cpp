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

int arr[200006];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, counter = 0;
        ll dp[200006];
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];

        dp[0] = 0;
        if(arr[1] == 1){
            dp[1] = 1;
            counter = 2;
        }
        else dp[1] = 0;
        
        for(int i = 2; i <= n; i++){

            if(counter){
                counter--;
                dp[i] = dp[i-1];
            }
            else if(arr[i] == 1){
                if(arr[i-1] == 1 && arr[i-2] == 1){
                    dp[i] = dp[i-1] + 1;
                    counter = 2;
                }
                else{
                    dp[i] = dp[i-1];
                }
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        cout << dp[n] << '\n';
    }

	return 0;
}