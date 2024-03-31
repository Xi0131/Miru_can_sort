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

int in[300001];
int dp[300001][27];

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> vec[n+1];
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        dp[tmp][s[tmp-1] - 'a' + 1]++;
        for(int x : vec[tmp]){
            for(int i = 1; i <= 26; i++){
                dp[x][i] = max(dp[x][i], dp[tmp][i]);
            }
            in[x]--;
            if(in[x] == 0) q.push(x);
        }
        for(int i = 1; i <= 27; i++){
            dp[tmp][0] = max(dp[tmp][0], dp[tmp][i]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(in[i] != 0){
            cout << -1;
            return 0;
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(ans < dp[i][0]){
            ans = dp[i][0];
        }
    }
    cout << ans;

	return 0;
}