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


int main()
{
	int n, k;
	cin >> n >> k;
	priority_queue<tuple<int, int, int>> a;
	vector<ll> b(n);

	cin >> b[0];
	for(int i = 1; i < n; i++){
		int tmp;
		cin >> tmp;
		b[i] = b[i-1] + tmp;
	}
	a.push({b[n-1], 0, n-1});
	
	int ans = INT_MAX;
	for(int i = 0; i < k-1; i++){
		ll half = get<0>(a.top()) / 2;
		int bL = get<1>(a.top());
		int bR = get<2>(a.top());
		int L = get<1>(a.top());
		int R = get<2>(a.top());
		int cut_pos;
		while(bL < bR){
			int mid = bL + (bR - bL) / 2;
			watch(b[mid]);
			if(b[mid + 1] < half){
				bL = mid + 1;
			}
			else if(b[mid] > half){
				bR = mid;
			}
			else{
				cut_pos = mid;
				break;
			}
		}
		a.pop();
		if(L == 0) a.push({b[cut_pos], L, cut_pos});
		else a.push({b[cut_pos] - b[L-1], L, cut_pos});
		a.push({b[R] - b[cut_pos + 1], cut_pos + 1, R});
	}

	// for(auto i : b) watch(i);
	cout << get<0>(a.top());

	return 0;
}