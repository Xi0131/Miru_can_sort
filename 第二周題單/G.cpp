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

vector<int> ans, visited;
vector<vector<int>> adj;
stack<int> tmp;
int n, m, flag;

void dfs(int x, int prev){
    tmp.push(x);
    visited[x] = true;
    for(int i : adj[x]){
        if(!visited[i]){
            dfs(i, x);
            if(flag){
                break;
            }
            else{
                tmp.pop();
            }
        }
        else if(visited[i] && i != prev){
            tmp.push(i);
            flag = 1;
            break;
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i, 0);
        if(flag) break;
    }

    if(flag){
        int x = tmp.top();
        ans.push_back(x);
        do{
            tmp.pop();
            ans.push_back(tmp.top());
        }while(tmp.top() != x);
        cout << ans.size() << endl;
        for(int i : ans) cout << i << ' ';
    }
    else{
        cout << "IMPOSSIBLE";
    }

	return 0;
}