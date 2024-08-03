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
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> vec;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(vec.begin(), vec.end(), arr[i]);

        if(it == vec.end()){
            vec.push_back(arr[i]);
        }
        else{
            *it = arr[i];
        }
    }

    cout << vec.size();

	return 0;
}