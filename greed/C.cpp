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
        int l[n], r[n], c[n];
        for(int i = 0; i < n; i++) cin >> l[i];
        for(int i = 0; i < n; i++) cin >> r[i];
        for(int i = 0; i < n; i++) cin >> c[i];

        sort(l, l + n);
        sort(r, r + n);
        sort(c, c + n);
        reverse(c, c + n);

        // for(int i = 0; i < n; i++){
        //     cout << l[i] << ' ';
        // } cout << '\n';

        int dif[n];
        for(int i = 0; i < n; i++) dif[i] = r[i] - l[i];

        sort(dif, dif + n);

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += c[i] * (dif[i]);
        }
        cout << ans << '\n';

    }

	return 0;
}