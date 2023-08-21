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
const ll INF = 1e17;
const ll NINF = -1e17;

int n, m;
vector<ll> dis;
vector<pair<int, pair<int, int>>> edge;

void bellman_ford(){
    for(int i = 1; i < n; i++){
        for(auto e : edge){
            int u = e.first;
            int v = e.second.first;
            int d = e.second.second;
            if(dis[u] == INF) continue;
            dis[v] = min(dis[v], dis[u] + d);
            dis[v] = max(dis[v], NINF);
        }
    }
    for(int i = 1; i < n; i++){
        for(auto e : edge){
            int u = e.first;
            int v = e.second.first;
            int d = e.second.second;
            if(dis[u] == INF) continue;
            dis[v] = max(dis[v], NINF);
            if(dis[u] + d < dis[v]){
                dis[v] = NINF;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    if(n == 1){
        cout << -1;
        return 0;
    }
    dis.resize(n+1);
    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        edge.push_back({a, {b, -c}});
    }
    for(int i = 2; i <= n; i++){
        dis[i] = INF;
    }
    bellman_ford();
    if(dis[n] == NINF) cout << -1;
    else cout << -dis[n];

	return 0;
}