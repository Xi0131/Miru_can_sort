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

ll dis[100005], parent[100005];
bool vis[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pii> vec[n+1];
    for(int i = 0, a, b, c ; i < m; i++){
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(b, c));
    }

    for(int i = 0; i <= n; i++) dis[i] = INF64;

    int tar = 0;
    bool update = false;
    for(int i = 0; i <= n + 1; i++){
        update = false;
        for(int j = 1; j <= n; j++){
            for(pii x : vec[j]){
                if(dis[x.first] > dis[j] + x.second){
                    dis[x.first] = dis[j] + x.second;
                    update = true;
                    parent[x.first] = j;
                    tar = x.first;
                }
            }
        }
    }

    if(update){
        cout << "YES\n";
        int tmp = parent[tar];
        stack<int> ss;
        while(!vis[tmp]){
            vis[tmp] = true;
            ss.push(tmp);
            tmp = parent[tmp];
        }
        cout << tmp << ' ';
        while(ss.top() != tmp){
            cout << ss.top() << ' ';
            ss.pop();
        }
        cout << tmp;
    }
    else{
        cout << "NO\n";
    }

	return 0;
}