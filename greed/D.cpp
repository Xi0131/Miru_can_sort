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


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n], b[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        ll ans = 0;
        for(int i = 0; i < n; i++){
            int mx = 0, cho = 0, me = 0 ;
            if(i % 2){
                for(int j = 0; j < n; j++){
                    if(a[j] > mx && b[j] != 0){
                        mx = a[j];
                        cho = j;
                        me = b[j];
                    }
                    else if(a[j] == mx && b[j] > me){
                        mx = a[j];
                        cho = j;
                        me = b[j];
                    }
                }
                a[cho] = 0;
                b[cho]--;
                ans -= b[cho];
            }
            else{
                // debug;
                // cout << mx << ' ' << me << '\n';
                for(int j = 0; j < n; j++){
                    // cout << b[j] << ' ' << a[j] << '\n';
                    if(b[j] > mx && a[j] != 0){
                        // debug;
                        mx = b[j];
                        cho = j;
                        me = a[j];
                    }
                    else if(b[j] == mx && a[j] > me){
                        mx = b[j];
                        cho = j;
                        me = a[j];
                    }
                }
                b[cho] = 0;
                a[cho]--;
                ans += a[cho];
            }
            cout << mx << ' ' << cho << '\n';
            // debug;
        }
        cout << ans << '\n';
    }

    // 0 3 2 4 1 5
    // 2 1 0 1 0 0
    // 0 0 6 0 1 4

	return 0;
}

// 0 19 0 0
// 0 0 9 19