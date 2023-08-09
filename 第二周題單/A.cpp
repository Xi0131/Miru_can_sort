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
vector<int> path;
vector<int> tmp;
vector<vector<int>> v;

void dfs(int idx){
    for(int i = 0; i < v[idx].size(); i++){
        tmp.push_back(v[idx][i]);
        if(v[idx][i] == n && tmp.size() > path.size()){
            path = tmp;
        }
        else{
            dfs(v[idx][i]);
        }
        tmp.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    v.resize(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    dfs(1);
    if(path.size() != 0){
        cout << path.size()+1 << endl;
        cout << 1 << ' ';
        for(auto i : path) cout << i << ' ';
    }
    else{
        cout << "IMPOSSIBLE";
    }

	return 0;
}