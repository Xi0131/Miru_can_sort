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

int sz[2001], parent[2001];

int find(int a){
    if(a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

bool merge(int a, int b){
    int px = find(a);
    int py = find(b);
    if(px == py) return false;
    // watch(a);
    // watch(b);
    if(sz[px] < sz[py]){
        swap(px, py);
    }
    parent[py] = px;
    sz[px] += sz[py];
    return true;
}

int main()
{
    ifstream cin("superbull.in");
    ofstream cout("superbull.out");
    int n;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        sz[i] = 1;
        parent[i] = i;
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i == j) continue;
            pq.push(make_pair(arr[i] ^ arr[j], make_pair(i, j)));
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
    // debug;
    cout << ans;

	return 0;
}