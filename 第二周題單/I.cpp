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
 
int n, m, loop;
ll ans = INT_MIN;
int adj[2501][2501];
vector<vector<int>> adj_list;
vector<int> visited, path;
vector<ll> d;
priority_queue<pii> q; // first is score, second is id
 
void dijkstra(int x){
    visited[x] = 1;
    for(int i : adj_list[x]){
        if(visited[i] == 1){
            if(d[x] + adj[x][i] > 0){
                loop = i;
                // ans = -1;
                return;
            }
            else return;
        }
        if(i == n){
            if(ans < d[x] + adj[x][i]){
                ans = d[x] + adj[x][i];
                path[i] = x;
            }
            continue;
        }
        else{
            path[i] = x;
        }
        q.push({adj[x][i], i});
        d[i] = d[x] + adj[x][i];
    }
    if(!q.empty()){
        int tmp = q.top().second;
        q.pop();
        dijkstra(tmp);
    }
    visited[x] = 2;
}
 
int main()
{
    cin >> n >> m;
    d.resize(n+1);
    path.resize(n+1);
    visited.resize(n+1);
    adj_list.resize(n+1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            adj[i][j] = 1e9;
    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        adj_list[a].push_back(b);
        adj[a][b] = c;
    }

    path[1] = 1;
    dijkstra(1);

    int flag = 0;
    if(loop){
        int tmp = n;
        while(tmp != 1){
            tmp = path[tmp];
            if(tmp == loop){
                cout << -1;
                flag = 1;
            }
        }
    }
    if(!flag) cout << ans;
 
	return 0;
}