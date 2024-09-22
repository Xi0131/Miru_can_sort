#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int maxn = 200005;
const int MAXN = 2e6 + 5;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int g[n+1][n+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> g[i][j];
            }
        }
        while(k--){
            int ans = 0;
            int w, v, d;
            cin >> w >> v >> d;
            if(d < g[w][v]) ans++;
            else{
                cout << 0 << '\n';
                continue;
            }
            g[w][v] = d;
            g[v][w] = d;
            queue<pii> q;
            q.push({w, v});
            while(!q.empty()){
                int u, v;
                u = q.front().first;
                v = q.front().second;
                q.pop();
                for(int i = 1; i <= n; i++){
                    if(i == u || i == v) continue;
                    if(g[i][u] + g[u][v] < g[i][v]){
                        g[i][v] = g[i][u] + g[u][v];
                        g[v][i] = g[i][v];
                        q.push({i, v});
                        ans++;
                        // debug;
                    }
                }
                for(int i = 1; i <= n; i++){
                    if(i == u || i == v) continue;
                    if(g[u][v] + g[v][i] < g[u][i]){
                        g[u][i] = g[u][v] + g[v][i];
                        g[i][u] = g[u][i];
                        q.push({u, i});
                        ans++;
                        // debug;
                    }
                }
            }
            cout << ans << '\n';
            // debug;
        }
    }

	return 0;
}