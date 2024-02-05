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
    for(int i = 0, tmp; i < n; i++){
        if(acc > 9){
            ans += 9;
            acc -= 9;
        }
        else if(acc){
            ans += acc;
            acc = 0;
        }
        cin >> tmp;
        acc += tmp;
        if(acc <= 7){
            if(acc == 0 && ans <= 7){
                ans = 0;
            }
            else if(acc == 0 && ans > 7){
                ans -= 7;
            }
            else{
                ans -= (7 - acc);
                acc = 0;
            }
        }
        else{
            acc -= 7;
            if(acc > 8){
                ans += 8;
                acc -= 8;
            }
            else{
                ans += acc;
                acc = 0;
            }
        }
    }
    
    if(acc) cout << "IMPOSSIBLE";
    else{
        cout << "YES\n";
        cout << ans;
    }

	return 0;
}