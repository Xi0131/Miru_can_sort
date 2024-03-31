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

ll in[200005], cnt[200005];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec[n+1];
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    cnt[1] = 1;
    while(!q.empty()){
        for(int x : vec[q.front()]){
            cnt[x] += cnt[q.front()];
            cnt[x] %= MOD;
            in[x]--;
            if(in[x] == 0) q.push(x);
        }
        q.pop();
    }

    cout << cnt[n];

	return 0;
}