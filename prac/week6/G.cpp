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

int n, m;
int arr[maxn];
pair<int , int> vec[maxn * 4];

void build(int l, int r, int idx = 1){
    if(l == r){
        vec[idx].first = arr[l];
        vec[idx].second = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    vec[idx] = max(vec[idx << 1], vec[idx << 1 | 1]);
}

int query(int l, int r, int x, int idx = 1){
    if(vec[idx].first < x){
        return 0;
    }
    if(l == r){
        vec[idx].first -= x;
        return vec[idx].second;
    }
    int mid = (l + r) >> 1, ans;
    if(vec[idx << 1].first >= x){
        ans = query(l, mid, x, idx << 1);
    }
    else{
        ans = query(mid + 1, r, x, idx << 1 | 1);
    }
    vec[idx] = max(vec[idx << 1], vec[idx << 1 | 1]);
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    build(1, n);

    int x;
    while(m--){
        cin >> x;
        cout << query(1, n, x) << ' ';
    }

	return 0;
}