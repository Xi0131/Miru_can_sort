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
bool flag = 0;
vector<vector<int>> adj;
vector<int> visited;
stack<int> tmp;

void dfs(int x){
    tmp.push(x);
    visited[x] = 1;
    for(int i : adj[x]){
        if(visited[i] == 0){
            dfs(i);
            if(flag) break;
            else{
                tmp.pop();
                visited[i] = 2;
            }
        }
        else{
            if(visited[i] != 2){
                tmp.push(i);
                flag = 1;
                break;
            }
        }
    }
    visited[x] = 2;
}

int main()
{
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1);
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i);
        if(flag) break;
        else{
            while (!tmp.empty()){
                tmp.pop();
            }
        }
    }

    if(flag){
        vector<int> ans;
        int top = tmp.top();
        ans.push_back(tmp.top());
        do{
            tmp.pop();
            ans.push_back(tmp.top());
        }while(tmp.top() != top);
        cout << ans.size() << endl;
        for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
    }
    else cout << "IMPOSSIBLE";

	return 0;
}