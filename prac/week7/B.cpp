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

vector<int> is_factor(MAXN), is_arr(MAXN);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n), prime;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        is_arr[arr[i]]++;
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i = 1; i <= MAXN; i++){
        for(int j = i; j <= MAXN; j += i){
            if(is_arr[j]) is_factor[i] += is_arr[j];
        }
    }
    
    for(int i = arr[n-1]; i >= 1; i--){
        if(is_factor[i] > 1){
            ans = i;
            break;
        }
    }

    if(ans == 0) cout << 1;
    else cout << ans;

	return 0;
}