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
    int n, m;
    string str1, str2, ans, tmp;
    cin >> str1 >> str2;
    if(str1.size() < str2.size()){
        tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
    n = str1.size(), m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    

    int i = n, j = m;
    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            ans.push_back(str2[j-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        }
        else j--;
    }
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i];
    }

	return 0;
}