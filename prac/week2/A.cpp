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
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll j = 0, ans = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        while(j < n){
            mp[arr[j]]++;
            if(mp.size() > k) break;
            j++;
        }
        
        mp[arr[j]]--;
        if(mp[arr[j]] == 0) mp.erase(arr[j]);

        mp[arr[i]]--;
        if(mp[arr[i]] == 0) mp.erase(arr[i]);
        ans += j - i;
    }
    cout << ans;

	return 0;
}