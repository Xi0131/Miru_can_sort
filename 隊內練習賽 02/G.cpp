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
const int maxn = 200005;

int n, tmp;
int planet[maxn], visited[maxn], ans[maxn];

void dfs(int x){
    visited[x] = 1;
    int next = planet[x];
    tmp++;
    if(!visited[next]){
        dfs(next);
    }
    if(!ans[x]){
        ans[x] = tmp;
    }
    visited[x] = 0;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> planet[i];
    }
    for(int i = 1; i <= n; i++){
        if(!ans[i]){
            tmp = 0;
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }

	return 0;
}