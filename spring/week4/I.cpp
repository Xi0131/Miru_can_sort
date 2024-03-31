#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

int sz[2001], parent[2001];

int find(int a){
    if(a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

bool merge(int a, int b){
    int px = find(a);
    int py = find(b);
    if(px == py) return false;
    if(sz[px] < sz[py]){
        swap(px, py);
    }
    parent[py] = px;
    sz[px] += sz[py];
    return true;
}

ll mpow(ll x, ll y, int m ){
    if(y == 1) return x % m;
    else if(!(y % 2)) return (mpow(x, y/2, m) * mpow(x, y/2, m)) % m;
    else return (mpow(x, y - 1, m) * x) % m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        sz[i] = 1;
        parent[i] = i;
    }

    priority_queue<pair<ll, pair<int, int>>> pq;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i == j) continue;
            ll tmp = (mpow(arr[i], arr[j], m) + mpow(arr[j], arr[i], m)) % m;
            pq.push(make_pair(tmp, make_pair(i, j)));
        }
    }

    ll ans = 0;
    int cnt = 0;
    while(!pq.empty()){
        if(merge(pq.top().second.first, pq.top().second.second)){
            cnt++;
            ans += pq.top().first;
            if(cnt == n-1) break;
        }
        pq.pop();
    }

    cout << ans;

	return 0;
}