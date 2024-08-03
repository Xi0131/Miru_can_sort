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
        int n, cnt = 0;
        cin >> n;
        int x = INF32, y = INF32;
        for(int i = 0, tmp; i < n; i++){
            cin >> tmp;
            if(x > y) swap(x, y);
            if(tmp <= x) x = tmp;
            else if(tmp <= y) y = tmp;
            else{
                x = tmp;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }

	return 0;
}