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

int n, m;
vector<bool> vis, vis2;
vector<vector<int>> vec, rvec, scc;
vector<int> st;

void dfs1(int x){
	if(vis[x]) return;
	vis[x] = true;
	for(int u: vec[x]) dfs1(u);
	st.push_back(x);
}

void dfs2(int x){
	// at[x] = (int) scc.size() - 1;
	vis2[x] = true;
	for(int i: rvec[x]){
		if(!vis2[i]){
			dfs2(i);
		}
	}
	scc.back().push_back(x);
}

int main()
{
	cin >> n >> m;
	vis.resize(n+1, false);
	vec.resize(n+1);
	rvec.resize(n+1);
	vis2.resize(n+1, false);
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		vec[a].push_back(b);
		rvec[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		dfs1(i);
	}
	reverse(st.begin(), st.end());
	bool flag = false;
	int ans;
	for(int i: st){
		if(!vis2[i] && !flag){
			ans = i;
			flag = true;
			scc.resize(scc.size() + 1);
			dfs2(i);
		}
		else if(!vis2[i] && flag){
			cout << "NO\n";
			cout << i << ' ' << ans;
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}