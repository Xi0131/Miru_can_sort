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
vector<int> arr;
vector<ll> vec;

void build(int l, int r, int idx){
	// watch(idx);
	if(l == r){
		vec[idx] = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx << 1);
	build(mid + 1, r, idx << 1 | 1);
	vec[idx] = min(vec[idx << 1], vec[idx << 1 | 1]);
}

int query(int l, int r, int ql, int qr, int idx){
	// watch(idx);
	if(idx == 0) return -1;
	if(ql <= l && qr >= r)
		return vec[idx];
	int mid = (l + r) >> 1, ret = INF32;
	if(ql <= mid)
		ret = min(ret, query(l, mid, ql, qr, idx << 1));
	if(qr > mid)
		ret = min(ret, query(mid + 1, r, ql, qr, idx << 1 | 1));
	return ret;
}

void update(int l, int r, int idx, int pos, int val){
	if(l == r){
		vec[idx] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(l, mid, idx << 1, pos, val);
	else
		update(mid + 1, r, idx << 1 | 1, pos, val);
	vec[idx] = min(vec[idx << 1], vec[idx << 1 | 1]);
}

int main()
{
    cin >> n >> q;
	arr.resize(n + 1);
	vec.resize(n * 4);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	build(1, n, 1);

	int x, a, b;
	while(q--){
		cin >> x >> a >> b;
		if(x == 1){
			update(1, n, 1, a, b);
		}
		else{
			cout << query(1, n, a, b, 1) << '\n';
		}
	}

	return 0;
}