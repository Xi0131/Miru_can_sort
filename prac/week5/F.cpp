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

int n;
vector<int> vec, in, ans;
vector<vector<int>> val;

int main()
{
    cin >> n;
    vec.resize(n+1);
    in.resize(n+1);
    ans.resize(n+1);
    for(int a, i = 2; i <= n; i++){
        cin >> a;
        in[a]++;
        vec[i] = a;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        in[vec[tmp]]--;
        ans[vec[tmp]] += ans[tmp] + 1;
        if(in[vec[tmp]] == 0) q.push(vec[tmp]);
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }

	return 0;
}