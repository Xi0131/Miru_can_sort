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

int n, m;
ll ans = LONG_LONG_MAX;
vector<vector<pii>> adj_l;
priority_queue<pii, vector<pii>, greater<pii>> q;
vector<int> visited, path, longest;
vector<ll> d(1e5, LONG_LONG_MAX);

void dijkstra(int x){
	visited[x] = 1;
	// watch(x);
	for(pii i : adj_l[x]){
		int id = i.first;
		int weight = i.second;
		// watch(id);
		if(weight > longest[x]){
				int tmp_longest = weight;
				ll tmp_d = d[x] + (weight / 2) - (longest[x] / 2) + longest[x];
				if(tmp_d < d[id]){
					
				}
			}
			else d[id] = d[x] + weight;
		if(visited[id] == 1){

			if(weight > longest[x]){

			}
			if(d[id] > d[x] + adj_l[x][id].second){
				d[id] = d[x] + adj_l[x][id].second;
			}
		}
		if(!visited[id]){
			path[id] = x;
			if(weight > longest[x])
			longest[id] = max(longest[x], weight);
			if(weight > longest[x]){
				longest[id] = weight;
				d[id] = d[x] + (weight / 2) - (longest[x] / 2) + longest[x];
			}
			else d[id] = d[x] + weight;
			watch(id);
			watch(d[id]);
			q.push({d[id], id});
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
	longest.resize(n+1);
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
	// int i = n;
	// while(i != 1){
	// 	longest = max(longest, (int)(d[i] - d[path[i]]));
	// 	i = path[i];
	// }
	// watch(longest);
	// cout << d[n] - longest + (longest / 2);
	cout << d[n];

	return 0;
}