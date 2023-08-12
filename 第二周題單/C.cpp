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
const int maxn = 5e4 + 5;

vector<vector<int>> adj;
vector<int> in, ans;
bitset<maxn> bit[maxn];

int main()
{
	int n, m;
	cin >> n >> m;
	in.resize(n+1);
	adj.resize(n+1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
		in[a]++;
	}

	queue<int> q;
	for(int i = 1; i <= n; i++) bit[i][i] = true;
	for(int i = 1; i <= n; i++){
		if(in[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i : adj[tmp]){
			bit[i] |= bit[tmp];
			in[i]--;
			if(in[i] == 0) q.push(i);
		}
	}

	for(int i = 1; i <= n; i++){
		cout << bit[i].count() << ' ';
	}

	return 0;
}