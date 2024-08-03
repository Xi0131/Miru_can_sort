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
    int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		int fruit[n], height[n];
		for(int i = 0; i < n; i++) cin >> fruit[i];
		for(int i = 0; i < n; i++) cin >> height[i];

		ll l = 0, r = 0, ans = 0, acc = 0;

		while(r < n){

			while(r+1 < n && height[r] % height[r+1] == 0){
				r++;
			} 

			int m = l;
			acc = 0;
			while(m <= r){
				
				acc += fruit[m];
				if(acc <= k){
					ans = max(ans, m-l+1);
				}
				else{
					while(acc > k){
						acc -= fruit[l];
						l++;
					}
				}
				m++;
			}

			r++;
			l = r;
		}

		cout << ans << '\n';
	}

	return 0;
}