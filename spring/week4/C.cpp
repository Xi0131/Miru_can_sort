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

bool vis[100005];
ll dis[100005], parent[100005];

void print_parent(ll a){
    if(parent[a] != 0) print_parent(parent[a]);
    cout << a << ' ';
}

int dijkstra(int s, int e, vector<pii> vec[]){
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        // top.first = distance
        // top.second = id
        pii top = pq.top();
        pq.pop();
        for(pii node : vec[top.second]){
            // node.first = id
            // node.second = dis
            if(dis[node.first] > dis[top.second] + node.second){
                // debug;
                dis[node.first] = dis[top.second] + node.second;
                pq.push({dis[node.first], node.first});
                parent[node.first] = top.second;
            }
        }
    }
    return parent[e];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) dis[i] = INF64;
    vector<pii> vec[n+1];
    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(b, c));
        vec[b].push_back(make_pair(a, c));
    }

    dijkstra(1, n, vec);
    if(dis[n] == INF64){
        cout << -1;
        return 0;
    }
    print_parent(n);

	return 0;
}