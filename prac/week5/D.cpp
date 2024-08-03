#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

int n, m, kingdom;
vector<vector<int>> vec, rvec;
vector<bool> vis, vis2;
vector<int> st, at;

void dfs1(int x){
    if(vis[x]) return;
    vis[x] = 1;
    for(int i : vec[x]){
        dfs1(i);
    }
    st.push_back(x);
}

void dfs2(int x){
    at[x] = kingdom;
    for(int i : rvec[x]){
        if(at[i] == 0) dfs2(i);
    }
}

int main()
{
    cin >> n >> m;
    vec.resize(n+1);
    rvec.resize(n+1);
    vis.resize(n+1, false);
    vis2.resize(n+1, false);
    at.resize(n+1, 0);

    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        rvec[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs1(i);
    }
    reverse(st.begin(), st.end());
    for(int i : st){
        if(at[i] == 0){
            kingdom++;
            dfs2(i);
        }
    }
    cout << kingdom << '\n';
    for(int i = 1; i <= n; i++){
        cout << at[i] << ' ';
    }

	return 0;
}