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
    cin >> n;
    for(int i = 0; i < n; i++){
        ll b, tmp, acc = 0;
        cin >> b;
        for(int j = 0; j < b; j++){
            cin >> tmp;
            acc += tmp;
        }
        ll l = 0, r = acc / 2, flag = 1;
        while(l <= r){
            ll mid = (r - l) / 2 + l;
            ll sq = mid * mid;
            if(sq == acc){
                flag = 0;
                cout << "YES\n";
                break;
            }
            else if(sq < acc){
                l = mid + 1;
            }
            else if(sq > acc){
                r = mid - 1;
            }
        }
        if(acc == 1) cout << "YES\n";
        else if(flag) cout << "NO\n";
    }

	return 0;
}