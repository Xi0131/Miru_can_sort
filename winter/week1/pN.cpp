#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;


int main()
{
    int n;
    ll acc = 0;
    cin >> n;
    for(ll i = 0, tmp; i < n; i++){
        cin >> tmp;
        if(tmp != 0) acc += tmp * tmp + 1;
    }
    if(acc == 0) cout << 1;
    else cout << acc;

	return 0;
}