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
const int maxn = 200005;
const int MAXN = 2e6 + 5;

ll expo(ll a, ll b){
    if(b == 0) return 1;
    if(!(b % 2)){
        ll tmp = expo(a, b / 2);
        return (tmp * tmp) % (MOD - 1);
    }
    else{
        return (expo(a, b - 1) * a) % (MOD - 1);
    }
}

ll expo2(ll a, ll b){
    if(b == 0) return 1;
    if(!(b % 2)){
        ll tmp = expo2(a, b / 2);
        return (tmp * tmp) % (MOD);
    }
    else{
        return (expo2(a, b - 1) * a) % (MOD);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll tmp = expo(b, c);
        cout << expo2(a, tmp) << '\n';
    }

	return 0;
}