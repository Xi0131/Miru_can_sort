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
const int maxn = 10000005;

int ans, n, m, k;
ll v[maxn];

int main()
{
    cin >> n >> m >> k;
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		v[a] += 1;
		v[b+1] -= 1;
	}

	for(int i = 1; i < n+1; i++){
		v[i] += v[i-1];
	}

    int tmp = 0;
	for(int i = 1; i < n+1; i++){
        if(v[i] == 0){
            tmp++;
            if(tmp >= k) ans++;
        }
        else{
            tmp = 0;
        }
	}

    if(ans == 0) cout << -1;
    else cout << ans;

	return 0;
}