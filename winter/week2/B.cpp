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
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        int arr[t];
        for(int j = 0; j < t; j++) cin >> arr[j];

        ll ans = 0;
        int l = 0, r = 0;
        for(; l < t; l++){
            while(arr[r] >= r - l + 1 && r < t) r++;
            ans += r - l;
        }

        cout << ans << '\n';
    }

	return 0;
}