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

ll bit[maxn];
vector<int> salary(maxn);
int n, q;

int lowbit(int x){
	return x & -x;
}

void change(int i, int x, int n){
	while(i <= n){
		bit[i] += x;
		i += lowbit(i);
	}
}

int sum(int x){
	int ret = 0;
	while(x){
		ret += bit[x];
		x = lowbit(x);
	}
	return ret;
}

void decentralized(vector<int> &a){
	vector<int> b = a;
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for(int i = 0; i < n; i++){
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
	}
	// for(int i = 0; i < b.size(); i++){
	// 	watch(b[i]);
	// }
}

vector<int> decen(vector<int> a){
	vector<int> b = a;
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for(int i = 0; i < a.size(); i++){
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	salary.resize(n);
	for(int i = 0; i < n; i++){
		cin >> salary[i];
	}

	// decentralized(salary);
	vector<int> tmp = decen(salary);
	for(int i = 0; i < salary.size(); i++){
		cout << salary[i] << ' ';
	} cout << '\n';
	for(int i = 0; i < salary.size(); i++){
		cout << tmp[i] << ' ';
	} cout << '\n';

	// for(int i = 0, a, b; i < q; i++){
	// 	char c;
	// 	cin >> c >> a >> b;
	// 	if(c == '?'){
			
	// 	}
	// 	else{

	// 	}
	// }

	return 0;
}