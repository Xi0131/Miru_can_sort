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
    int n;
    cin >> n;
    vector<ll> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    ll accum = 0, max_arr = INT_MIN;

    for(int i = 0; i < n; i++){
        accum = accum + vec[i];
        if(max_arr < accum){
            max_arr = accum;
        }
        if(accum < 0){
            accum = 0;
        }
    }

    cout << max_arr;

	return 0;
}