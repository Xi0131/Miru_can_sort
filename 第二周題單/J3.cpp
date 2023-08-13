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

int n, m, longest = 1;
ll ans = LONG_LONG_MAX;
vector<vector<pii>> adj_l;
priority_queue<pii, vector<pii>, greater<pii>> q;
vector<int> visited, path;
vector<ll> d(1e5, LONG_LONG_MAX);

void dijkstra(int x){
	visited[x] = 1;
	// watch(x);
	for(pii i : adj_l[x]){
		int id = i.first;
		// watch(id);
		if(visited[id] == 1){
			if(d[id] > d[x] + adj_l[x][id].second){
				d[id] = d[x] + adj_l[x][id].second;
			}
		}
		if(!visited[id]){
			path[id] = x;
			d[id] = d[x] + i.second;
			q.push({i.second, id});
		}
	}
	if(!q.empty()){
		// watch(q.top().first);
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
	}

	path[1] = 1;
	d[1] = 0;
	dijkstra(1);

	// for(int i : path) watch(i);
	// for(int j : d) watch(j);
	int i = n;
	while(i != 1){
		longest = max(longest, (int)(d[i] - d[path[i]]));
		i = path[i];
	}
	// watch(longest);
	cout << d[n] - longest + (longest / 2);

	return 0;
}