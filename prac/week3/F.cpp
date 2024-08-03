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
    int n;
    cin >> n;

    vector<ll> dp[2];
    dp[0].push_back(0);
    dp[1].push_back(0);
    for(int i = 1; i < 10; i++){
        dp[0].push_back(1);
        dp[1].push_back(1);
    }

    if(n <= 9) cout << dp[0][n];
    else{
        int i = 10, j = 0, k;
        while(i <= n){

            int tmp = i, digit = 0;
            while(tmp != 0){
                digit = max(tmp % 10, digit);
                tmp /= 10;
            }
            
            k = (i - digit) % 10;
            if(digit <= i % 10){
                dp[1][i % 10] = dp[1][k] + 1;
            }
            else {
                dp[1][i % 10] = dp[0][k] + 1;
            }
            
            i++;
            if(i % 10 == 0){
                swap(dp[0], dp[1]);
            }
        }

        if(n % 10 == 9) cout << dp[0][9];
        else cout << dp[1][n%10];
    }

	return 0;
}