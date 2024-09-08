// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define debug cerr << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int maxn = 200005;
const int MAXN = 2e6 + 5;

int arr[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    
    int j = 0;
    vector<int> ans(x+1, INF32);
    for(int i = arr[0]; i <= x; i++){
        // watch(i);
        if(i == arr[j]){
            ans[i] = 1; 
            j++;
        }
        else{
            for(int k = 0; k < j; k++){
                // watch(k);
                ans[i] = min(ans[i], ans[i-arr[k]] + 1);
            }
            // watch(ans[i]);
        }
    }

    if(ans[x] == INF32) cout << -1 << '\n';
    else cout << ans[x] << '\n';

	return 0;
}