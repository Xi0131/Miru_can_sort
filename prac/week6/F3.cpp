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
const int maxn = 100005;

int n, c;
ll tree[maxn << 2], lazy[maxn << 2];

void push(int l, int r, int idx){

    if(!lazy[idx]) return;
    
    tree[idx] += lazy[idx] * (r - l + 1);
    
    if(l != r){
        lazy[idx << 1] += lazy[idx];
        lazy[idx << 1 | 1] += lazy[idx];
    }
    
    lazy[idx] = 0;
}

void update(int l, int r, int p, int q, ll val, int idx = 1){
    
    push(l, r, idx);
    
    if(p > r || q < l) return;
    
    if(p <= l && q >= r){
        lazy[idx] = val;
        push(l, r, idx);
        return;
    }
    
    int mid = (l + r) >> 1;
    
    update(l, mid, p, q, val, idx << 1);
    update(mid + 1, r, p, q, val, idx << 1 | 1);
    
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

ll query(int l, int r, int p, int q, int idx = 1){
    
    push(l, r, idx);
    
    if(p > r || q < l) return 0;
    
    if(p <= l && q >= r) return tree[idx];
    
    int mid = (l + r) >> 1;
    
    return query(l, mid, p, q, idx << 1) + query(mid + 1, r, p, q, idx << 1 | 1);
}

void solve(){
    
    cin >> n >> c;
    
    while(c--){
        int x, p, q, v;
        cin >> x;
        if(x == 0){
            cin >> p >> q >> v;
            update(1, n, p, q, v);
        }
        else{
            cin >> p >> q;
            cout << query(1, n, p, q) << '\n';
        }
    }

    for(int i = 1; i <= (n << 2); i++){
        tree[i] = lazy[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
	return 0;
}