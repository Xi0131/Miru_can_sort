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

pair<ll, ll> vec[maxn * 4];
int n, c, x;

void push(int l, int r, int idx){
    if(vec[idx].second){
        int mid = (l + r) >> 1;
        vec[idx << 1].first += vec[idx].second * (mid - (l - 1));
        vec[idx << 1].second += vec[idx].second;
        vec[idx << 1 | 1].first += vec[idx].second * (r - mid);
        vec[idx << 1 | 1].second += vec[idx].second;
        vec[idx].second = 0;
    }
}

void update(int l, int r, int p, int q, int x, int idx = 1){
    // debug;

    if(p <= l && q >= r){
        vec[idx].first += (ll)x * (r - (l - 1));
        vec[idx].second += x;
        return;
    }
    push(l, r, idx);
    int mid = (l + r) >> 1;
    if(p <= mid){
        update(l, mid, p, q, x, idx << 1);
    }
    if(q > mid){
        update(mid + 1, r, p, q, x, idx << 1 | 1);
    }
    vec[idx].first = vec[idx << 1].first + vec[idx << 1 | 1].first;
}

ll query(int l, int r, int p, int q, int idx = 1){
    
    if(p <= l && q >= r)
        return vec[idx].first;
    push(l, r, idx);
    ll mid = (l + r) >> 1, ret = 0;
    if(p <= mid){
        ret += query(l, mid, p, q, idx << 1);
    }
    if(q > mid){
        ret += query(mid + 1, r, p, q, idx << 1 | 1);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> c;
        for(int i = 1; i <= n * 4; i++){
            vec[i].first = 0;
            vec[i].second = 0;
        }
        while(c--){
            cin >> x;
            if(x == 0){
                int p, q, v;
                cin >> p >> q >> v;
                update(1, n, p, q, v);
            }
            else{
                int p, q;
                cin >> p >> q;
                cout << query(1, n, p, q) << '\n';
            }
        }
    }

	return 0;
}