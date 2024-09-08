// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
// #include <algorithm>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define debug cerr << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int maxn = 200005;
const int MAXN = 2e6 + 5;

char arr[1001][1001];
ll ans[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    if(arr[1][1] == '*'){
        cout << 0;
        return 0;
    }
    ans[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && j == 1) continue;
            if(arr[i][j] == '*') ans[i][j] = 0;
            else ans[i][j] = (ans[i-1][j] + ans[i][j-1]) % MOD;
        }
    }

    cout << ans[n][n];

	return 0;
}