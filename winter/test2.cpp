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
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> dp[2];
    int n = str1.size(), m = str2.size();
    for(int i = 0; i <= m; i++){
        dp[0].push_back(0);
        dp[1].push_back(0);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[0][j] = dp[1][j-1] + 1;
            }
            else{
                dp[0][j] = max(dp[1][j], dp[0][j-1]);
            }
        }
            swap(dp[0], dp[1]);
    }
    string tmp;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j <= m; j++){
            cout << dp[i][j] << ' ';
            if(i == 1 && j > 0 && dp[i][j] > dp[i][j-1]){
                tmp.push_back(str2[j-1]);
            }
        }
        cout << '\n';
    }
    watch(tmp);
    cout << dp[1][m];

	return 0;
}