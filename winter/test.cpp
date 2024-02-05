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
    int dp[str1.size() + 1][str2.size() + 1];
    // vector<vector<int>> dp(str1.size() + 1, vector<int> (str2.size()));
    for (int i = 0; i <= str1.size(); i++)
        dp[i][0] = 0;
    for (int i = 0; i <= str2.size(); i++)
        dp[0][i] = 0;
    for (int i = 1; i <= str1.size(); i++)
        for (int j = 1; j <= str2.size(); j++)
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    cout << dp[str1.size()][str2.size()] << "\n";
    for(int i = str1.size() - 1; i <= str1.size(); i++){
        for(int j = 0; j <= str2.size(); j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

	return 0;
}