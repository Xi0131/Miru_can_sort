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
    vector<pii> vec;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, 1});
        vec.push_back({b, -1});
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    int cnt = 0;
    for(auto i : vec){
        cnt += i.second;
        ans = max(ans, cnt);
    }
    
    cout << ans;

	return 0;
}