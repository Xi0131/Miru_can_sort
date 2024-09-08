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
        ll arr[n];
        cin >> arr[0];
        bool flag = 0;
        map<ll, int> mp;
        mp[arr[0]]++;
        for(int i = 1, tmp; i < n; i++){
            cin >> tmp;
            if(i % 2) tmp = -tmp;
            arr[i] = arr[i - 1] + tmp;
            mp[arr[i]]++;
            if(mp[arr[i]] > 1) flag = 1;
            if(arr[i] == 0) flag = 1;
        }

        // for(int i = 0; i < n; i++){
        //     cerr << arr[i] << ' ';
        // } cerr << '\n';

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

	return 0;
}