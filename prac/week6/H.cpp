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

int n, q;
vector<ll> prefix(maxn), ori(maxn);
vector<ll> segs(maxn << 2), lazy(maxn << 2);


void push(int l, int r, int idx){
    if(lazy[idx]){
        segs[idx << 1] += lazy[idx];
        lazy[idx << 1] += lazy[idx];
        segs[idx << 1 | 1] += lazy[idx];
        lazy[idx << 1 | 1] += lazy[idx];
        lazy[idx] = 0;
    }
}

void build(int l, int r, int idx = 1){
    if(l == r){
        segs[idx] = prefix[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    segs[idx] = max(segs[idx << 1], segs[idx << 1 | 1]);
}

void update(int l, int r, int pos, ll val, int idx = 1){
    // watch(idx);
    push(l, r, idx);
    if(l == r && r == pos){
        segs[idx] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid){
        segs[idx << 1 | 1] += val;
        lazy[idx << 1 | 1] += val;
        update(l, mid, pos, val, idx << 1);
    }
    else{
        update(mid + 1, r, pos, val, idx << 1 | 1);
    }
    segs[idx] = max(segs[idx << 1], segs[idx << 1 | 1]);
}

ll query(int l, int r, int p, int q, int idx = 1){
    // if(l > q || r < p) return segs[idx];
    // cout << l << ' ' << r << endl;
    push(l, r, idx);
    if(l >= p && r <= q){
        return segs[idx];
    }
    int mid = (l + r) >> 1;
    ll tmp1 = -INF64, tmp2 = -INF64;
    if(p <= mid){
        tmp1 = query(l, mid, p, q, idx << 1);
    }
    if(q > mid){
        tmp2 = query(mid + 1, r, p, q, idx << 1 | 1);
    }
    ll ans = max(tmp1, tmp2);
    // watch(ans);
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> ori[i];
        prefix[i] = ori[i];
    }
    for(int i = 2; i <= n; i++) prefix[i] += prefix[i-1];
    // for(int i = 1; i <= n; i++) cout << prefix[i] << ' '; cout << endl;

    build(1, n);
    // for(int i = 1; i <= n << 2; i++) cout << segs[i] << ' '; cout << endl;

    ll a, b, c;
    while(q--){
        cin >> a >> b >> c;
        if(a == 1){
            update(1, n, b, c - ori[b]);
            ori[b] = c;
        }
        else{
            ll ans = 0;
            if(b == 1)
                ans = query(1, n, b, c);
            else{
                ans = query(1, n, b, c) - query(1, n, b - 1, b - 1);
                // cout << query(1, n, b, c) - query(1, n, 1, b - 1) << endl;
                // ll tmp1 = query(1, n, b, c), tmp2 = query(1, n, b - 1, b - 1);
                // cout << tmp1 - tmp2;
                // watch(tmp1);
                // watch(tmp2);
                // watch(b-1);
                // watch(tmp1 - tmp2);
                // debug;
            }
            if(ans < 0)
                cout << 0 << '\n';
            else 
                cout << ans << '\n';
        }
        // for(int i = 1; i <= n << 2; i++) cout << segs[i] << ' '; cout << endl;
    }
    // for(int i = 1; i <= n; i++) cout << ori[i] << ' '; cout << endl;

	return 0;
}