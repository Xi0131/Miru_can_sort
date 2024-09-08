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
const int maxn = 200005;

vector<int> val(maxn), vis(maxn);
vector<ll> dpp1(maxn), dpp2(maxn), dpp3(maxn), dpp4(maxn);

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first == b.first){
        
    }
    return a.first < b.first;
}

void dfs(int x, vector<ll> &dp1, vector<ll> &dp2, int prev, vector<vector<int>> &g){
    if(vis[x]) return;
    vis[x] = 1;
    int sz = g[x].size();
    watch(x);
    watch(sz);
    int qsz = sz;
    if(prev != 0) qsz--;
    if(qsz == 0){
        dp1[x] = 0;
        dp2[x] = val[x];
        // watch(dp1[x]);
        // watch(dp2[x]);
        return;
    }
    dp1[x] = 0;
    dp2[x] = val[x];
    vector<pair<ll, ll>> pq1(qsz, {0, 0}), pq2(qsz, {0, 0});
    vector<bool> seen1(g.size() + 1, 0), seen2(g.size() + 1, 0);
    for(int i = 0, j = 0; i < sz; i++){
        if(g[x][i] == prev) continue;
        dfs(g[x][i], dp1, dp2, x, g);
        pq1[j].first = dp1[g[x][i]];
        pq2[j].first = dp2[g[x][i]];
        pq1[j].second = pq2[j].second = g[x][i];
        watch(pq1[j].first);
        watch(pq2[j].first);
        watch(j);
        j++;
    }
    sort(pq1.rbegin(), pq1.rend());
    sort(pq2.rbegin(), pq2.rend());
    watch(x);
    watch(dp1[x]);
    watch(dp2[x]);
    for(int i = 0, j = 0, a = 0, b = 0, k = 0; k < qsz; k++){
        if(k%2){
            while(seen1[pq1[j].second]) j++;
            dp1[x] += pq1[j].first;
            seen1[pq1[j++].second] = 1;
            while(seen2[pq2[b].second]) b++; 
            dp2[x] += pq2[b].first;
            seen2[pq2[b++].second] = 1;
        }
        else{
            while(seen1[pq2[i].second]) i++;
            dp1[x] += pq2[i].first;
            seen1[pq2[i++].second] = 1;
            while(seen2[pq1[a].second]) a++;
            dp2[x] += pq1[a].first;
            watch(pq1[a].first);
            watch(pq1[a].second);
            seen2[pq1[a++].second] = 1;
        }
        watch(dp1[x]);
        watch(dp2[x]);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << 0 << '\n';
            continue;
        }
        vector<vector<int>> g;
        g.resize(n+1);
        for(int i = 1; i <= n; i++){
            cin >> val[i];
            dpp1[i] = dpp2[i] = dpp3[i] = dpp4[i] = vis[i] = 0;
        }
        for(int i = 0, a, b; i < n - 1; i++){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, dpp1, dpp2, 0, g);
        dfs(g[1][0], dpp3, dpp4, 0, g);
        cout << max(dpp1[1], dpp3[g[1][0]]) << '\n';
        // watch(dpp1[1]);
        // watch(dpp3[g[1][0]]);
        // if(n % 2){
            // cout << max(dpp1[1], dpp3[g[1][0]]) << '\n';
        // }
        // else{
            // cout << max(dpp1[1], dpp2[1]) << '\n';
            // cout << max(dpp1[1], dpp3[g[1][0]]) << '\n';
            // cout << dpp1[1] << '\n';
        // }
        // watch(dpp1[1]); watch(dpp2[1]);
    }

	return 0;
}