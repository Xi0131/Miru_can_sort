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

vector<vector<int>> adj;
vector<int> yen;

int main()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n+1);
    yen.resize(n+1);
	vector<int> max_yen(n+1, -1e9);
    for(int i = 1; i <= n; i++) cin >> yen[i];
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	int ans = -1e9;
	for(int i = n; i >= 1; i--){
		for(int j : adj[i]){
			max_yen[i] = max(max_yen[i], max_yen[j]);
		}
		ans = max(ans, max_yen[i] - yen[i]);
		max_yen[i] = max(max_yen[i], yen[i]);
	}

	cout << ans;

	return 0;
}