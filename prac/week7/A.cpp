#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int maxn = 1000005;

int is_prime[maxn];
vector<ll> prime;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	for(ll i = 2; i * i <= 1000000000000; i++){
		if(is_prime[i] == 0){
			prime.push_back(i);
		}
		for(int j = 0; j < prime.size(); j++){
			if(i * prime[j] > maxn) break;
			is_prime[i * prime[j]] = 1;
		}
	}

	ll ans = 0;
	int sz = prime.size();
	for(int i = 0; i < sz; i++){
		if(prime[i] * prime[i] * prime[i] * prime[i] * prime[i] >= n) break;
		for(int j = i + 1; j < sz; j++){
			if(prime[i] * prime[i] * prime[j] * prime[j] * prime[j] >= n) break;
			for(int k = j + 1; k < sz; k++){
				if(prime[i] * prime[i] * prime[j] * prime[k] * prime[k] > n) break;
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}