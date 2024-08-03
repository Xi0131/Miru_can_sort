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
const ll INF64 = (1LL<<60) * -1;

ll dis[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    if(n == 1){
        cout << 0;
        return 0;
    }
    vector<pii> vec[n+1];
    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(b, c));
    }

    for(int i = 0; i <= n; i++) dis[i] = INF64;

    dis[1] = 0;
    ll rec, rec2;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= n; j++){
            for(pii x : vec[j]){
                if(dis[x.first] < dis[j] + x.second){
                    dis[x.first] = dis[j] + x.second;
                }
            }
        }
        if(i == n) rec = dis[n];
        if(i == n + 1) rec2 = dis[n]; 

    }

    if(rec != rec2) cout << "inf";
    else cout << dis[n];

	return 0;
}