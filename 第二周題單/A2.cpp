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
vector<int> in;
vector<vector<int>> adj;
vector<int> topo;

int main()
{
    cin >> n >> m;
    in.resize(n+1);
    adj.resize(n+1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for(int i = 2; i <= n; i++){
        if(in[i] == 0) q.push(i);
    }

    vector<int> path(n+1, -1); // use to record previous point
    unordered_set<int> k;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        k.insert(v);
        for(int i : adj[v]){
            in[i]--;
            if(in[i] == 0){
                q.push(i);
                path[i] = v;
            }
        }
    }

    if(in[n] == 0 && k.find(1) == k.end()){
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> tmp;
    q.push(1);
    while(!q.empty()){
        for(int i : adj[q.front()]){
            in[i]--;
            if(in[i] == 0){
                q.push(i);
                path[i] = q.front();
            }
        }

        tmp.push_back(q.front());
        q.pop();
    }

    if(path[n] == -1){
        cout << "IMPOSSIBLE";
    }
    else{
        vector<int> ans;
        ans.push_back(n);
        while(ans.back() != 1){
            ans.push_back(path[ans.back()]);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(int i : ans) cout << i << ' ';
    }

	return 0;
}