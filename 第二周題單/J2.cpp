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

int n, m, longest;
ll ans = LONG_LONG_MAX;
// vector<vector<int>> adj_m(1e5+1, vector<int>(1e5+1, 1e9));
vector<vector<pii>> adj_l;
priority_queue<pii, vector<pii>, greater<pii>> q;
vector<int> visited, d, path;

void dijkstra(int x){
	visited[x] = true;
	for(int i : adj_l[x]){
		if(!visited[i]){
			path[i] = x;
			q.push({adj_m[x][i], i});
		}
	}
	if(!q.empty()){
		int tmp = q.top().second;
		q.pop();
		dijkstra(tmp);
	}
}

int main()
{
	cin >> n >> m;
	d.resize(n+1);
	path.resize(n+1);
	adj_l.resize(n+1);
	visited.resize(n+1);
	for(int i = 0, a, b, c; i < m; i++){
		cin >> a >> b >> c;
		adj_l[a].push_back({b, c});
		// adj_m[a][b] = c;
	}

	path[1] = 1;
	dijkstra(1);

	for(int i : path) watch(i);

	return 0;
}