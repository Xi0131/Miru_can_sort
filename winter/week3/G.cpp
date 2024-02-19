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
    ll ans, a = 1, b = 2, c = 4, d = 8, e = 16, f = 32;
    if(n == 1) cout << 1;
    else if(n == 2) cout << 2;
    else if(n == 3) cout << 4;
    else if(n == 4) cout << 8;
    else if(n == 5) cout << 16;
    else if(n == 6) cout << 32;
    else{
        for(int i = 7; i <= n; i++){
            ans = (a + b + c + d + e + f) % MOD;
            a = b;
            b = c;
            c = d;
            d = e;
            e = f;
            f = ans;
        }
        cout << ans;
    }

	return 0;
}