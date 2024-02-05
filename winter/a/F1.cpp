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
    ll n, acc = 0, ans = 0;
    cin >> n;
    cin >> acc;
    for(int i = 9; i < 16; i++) if(acc) acc--;
    if(acc <= 8) ans += acc, acc = 0;
    else ans += 8, acc -= 8;
    for(int i = 1, tmp; i < n; i++){
        for(int j = 0; j < 9; j++) if(acc) ans++, acc--;
        cin >> tmp;
        for(int j = 9; j < 16; j++){
            if(tmp) tmp--;
            else if(ans) ans--;
            // else if(acc) acc--;
        }
        acc += tmp;
        for(int j = 16; j < 24; j++) if(acc) ans++, acc--;
    }
    
    if(acc) cout << "IMPOSSIBLE";
    else{
        cout << "YES\n";
        cout << ans;
    }

	return 0;
}