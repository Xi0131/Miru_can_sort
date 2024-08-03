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

int n, q;
vector<ll> bit(maxn), arr(maxn);

ll lowbit(int i){
    return i & (-i);
}

ll sum(int i){
    ll ret = 0;
    while(i){
        ret += bit[i];
        i -= lowbit(i);
    }
    return ret;
}

void add(int i, int x){
    while(i <= n){
        bit[i] += x;
        i += lowbit(i);
    }
}

void buildBIT(vector<ll> &bit, vector<ll> &arr, int n){
    for(int i = 1; i <= n; i++){
        add(i, arr[i]);
    }
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    buildBIT(bit, arr, n);
    for(int i = 0, c, a, b; i < q; i++){
        cin >> c >> a >> b;
        if(c == 2){
            cout << sum(b) - sum(a - 1) << '\n';
        }
        else{
            add(a, b - arr[a]);
            arr[a] = b;
        }
    }

	return 0;
}