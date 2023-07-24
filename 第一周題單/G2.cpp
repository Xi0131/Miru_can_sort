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

bool check(vector<int> vec, ll mid, int n, int k){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += vec[i];
        if(sum > mid){
            sum = vec[i];
            k--;
        }
    }
    k--;
    if(k < 0){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    ll start = *max_element(vec.begin(), vec.end());
    ll end = 0;
    for(int i = 0; i < n; i++) end += vec[i];

    ll ans = 0;
    while(start <= end){
        ll mid = start + (end - start) / 2;
        if(check(vec, mid, n, k)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    cout << ans;

	return 0;
}