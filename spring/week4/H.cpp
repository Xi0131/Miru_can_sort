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

int vis[2005];

int main()
{
    // ifstream cin("superbull.in");
    // ofstream cout("superbull.out");
    int n;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i == j) continue;
            pq.push(make_pair(arr[i] ^ arr[j], make_pair(arr[i], arr[j])));
        }
    }

    ll ans = 0;
    ans += pq.top().first;
    vis[pq.top().second.first] = 0;
    vis[pq.top().second.second] = pq.top().second.first;
    pq.pop();
    while(!pq.empty()){
        if(!vis[pq.top().second.first] || !vis[pq.top().second.second]){
            ans += pq.top().first;
            vis[pq.top().second.first] = true;
            vis[pq.top().second.second] = true;
        }
        pq.pop();
    }

    cout << ans;

	return 0;
}