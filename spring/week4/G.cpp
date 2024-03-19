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

ll dis[501][501];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dis[i][j] = INF64;
        }
    }

    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        dis[a][b] = min((ll)c, dis[a][b]);
        dis[b][a] = min((ll)c, dis[b][a]);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                dis[j][i] = min(dis[j][i], dis[j][k] + dis[k][i]);
            }
        }
    }

    for(int i = 0, a, b; i < q; i++){
        cin >> a >> b;
        if(a == b) cout << 0 << '\n';
        else if(dis[a][b] == INF64) cout << -1 << '\n';
        else cout << dis[a][b] << '\n';
    }

	return 0;
}