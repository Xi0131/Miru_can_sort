#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

bool vis[100005];
ll dis[100005];

void dijkstra(int s, vector<pair<int, pair<int, int>>> vec[]){
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        pii st = pq.top();
        pq.pop();
        if(!vis[st.second]) vis[st.second] = true;
        else continue;
        for(pair<int, pair<int, int>> x : vec[st.second]){
            ll dep = st.first;
            if(st.first % x.second.second == 0){
                dep = st.first;
            }
            else if(st.first < x.second.second){
                dep = x.second.second;
            }
            else{
                dep = (dep / x.second.second + 1) * x.second.second;
            }

            if(dis[x.first] > dep + x.second.first){
                dis[x.first] = dep + x.second.first;
                pq.push(make_pair(dis[x.first], x.first));
            }
        }
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<int, pair<int, int>>> vec[n+1];
    for(int i = 0, a, b, t, k; i < m; i++){
        cin >> a >> b >> t >> k;
        vec[a].push_back(make_pair(b, make_pair(t, k)));
        vec[b].push_back(make_pair(a, make_pair(t, k)));
    }
    
    for(int i = 0; i <= n; i++){
        dis[i] = INF64;
    }

    dijkstra(x, vec);

    if(dis[y] == INF64){
        cout << -1;
    }
    else{
        cout << dis[y];
    }  

	return 0;
}