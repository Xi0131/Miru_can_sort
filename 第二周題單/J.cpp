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
const int maxn = 100005;

int n, m, a, b;
ll c;
ll dis[2][maxn];
vector<vector<pair<ll, int>>> adj;

int main()
{
	cin >> n >> m;
	adj.resize(n+1);
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	for(int i = 1; i <= n; i++){
		dis[0][i] = 1e18;
		dis[1][i] = 1e18;
	}
	dis[0][1] = 0;
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
	pq.push({0, {1, 0}});
	while(!pq.empty()){
		auto tmp = pq.top();
		pq.pop();
		if(tmp.first > dis[tmp.second.second][tmp.second.first]) continue;
		for(auto i : adj[tmp.second.first]){
			if(dis[tmp.second.second][i.second] > tmp.first + i.first){
				dis[tmp.second.second][i.second] = tmp.first + i.first;
				pq.push({dis[tmp.second.second][i.second], {i.second, tmp.second.second}});
			}
			if(tmp.second.second == 0){
				if(dis[1][i.second] > tmp.first + i.first / 2){
					dis[1][i.second] = tmp.first + i.first / 2;
					pq.push({dis[1][i.second], {i.second, 1}});
				}
			}
		}
	}
	cout << dis[1][n];

	return 0;
}