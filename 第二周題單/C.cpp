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

vector<vector<int>> adj;
vector<int> in, ans;

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
		in[b]++;
	}

	queue<int> q;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i : adj[tmp]){
			in[i]--;
		}
	}

	return 0;
}