#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int ARRSIZE = 1e5 + 5;

vector<vector<int>> vec, rvec, scc, svec;
vector<int> vis(ARRSIZE), at, st, coins, sccin;
vector<ll> scoin;

void dfs1(int x){
	if(vis[x]) return;
	vis[x] = 1;
	for(int y : vec[x]){
		dfs1(y);
	}
	st.push_back(x);
}

void dfs2(int x){
	at[x] = scc.size() - 1;
	scoin[scoin.size() - 1] += coins[x];
	for(int u : rvec[x]){
		if(at[u] == -1){
			dfs2(u);
		}
		else if(at[u] != (scoin.size() - 1)){
			// watch(x);
			// watch(u);
			svec[scoin.size() - 1].push_back(at[u]);
			sccin[at[u]]++;
		}
	}
	scc.back().push_back(x);
}

void topo(){

}

int main()
{
    int n, m;
	cin >> n >> m;
	coins.resize(n+1);
	vec.resize(n+1);
	rvec.resize(n+1);
	at.resize(n+1);
	for(int i = 1; i <= n; i++){
		cin >> coins[i];
	}
	fill(at.begin(), at.end(), -1);
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		vec[a].push_back(b);
		rvec[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]) dfs1(i);
	}
	reverse(st.begin(), st.end());
	for(int i : st){
		if(at[i] == -1){
			scc.resize(scc.size() + 1);
			scoin.resize(scoin.size() + 1);
			sccin.resize(sccin.size() + 1);
			svec.resize(svec.size() + 1);
			dfs2(i);
		}
	}

	queue<int> sq;
	for(int i = 0; i < sccin.size(); i++){
		if(sccin[i] == 0) sq.push(i);
	}
	
	vector<ll> dp(svec.size(), 0);
	ll ans = 0;
	while(!sq.empty()){
		int tmp = sq.front();
		sq.pop();
		dp[tmp] += scoin[tmp];
		for(int u : svec[tmp]){
			sccin[u]--;
			dp[u] = max(dp[u], dp[tmp]);
			if(sccin[u] == 0) sq.push(u);
		}
		ans = max(ans, dp[tmp]);
	}

	cout << ans;

	return 0;
}