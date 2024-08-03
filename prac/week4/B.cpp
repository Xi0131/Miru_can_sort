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

int visited[200005];
int ended[200005];
stack<int> st;

bool dfs(int x, vector<int> vec[]){
    // watch(x);
    visited[x] = 1;
    st.push(x);
    for(int next : vec[x]){
        if(!visited[next]){
            if(dfs(next, vec)){
                return 1;
            }
        }
        else{
            if(ended[next] != 1){
                st.push(next);
                return 1;
            }
        }
    }
    st.pop();
	ended[x] = 1;
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec[n+1];
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        vec[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            if(dfs(i, vec))
                break;
    }


    if(st.size() < 2){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int tmp = st.top();
    stack<int> ans;
    ans.push(st.top());
    st.pop();
    while(!st.empty() && st.top() != tmp){
        ans.push(st.top());
        st.pop();
    }
    cout << ans.size() + 1 << '\n';
    cout << tmp << ' ';
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }

	return 0;
}