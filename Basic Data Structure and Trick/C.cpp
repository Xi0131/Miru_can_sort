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

int n, w;
ll v[maxn];

int main()
{
	cin >> n >> w;
	for(int i = 0, a, b, c; i < n; i++){
		cin >> a >> b >> c;
		v[a] += c;
		v[b] -= c;
	}

	for(int i = 1; i < maxn; i++){
		v[i] += v[i-1];
	}

	for(int i = 0; i < maxn; i++){
		if(v[i] > w){
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";

	return 0;
}