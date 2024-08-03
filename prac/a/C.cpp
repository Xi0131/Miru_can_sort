#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;


int main()
{
    int n;
    cin >> n;
    vector<pii> vec, vec2;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }
    for(int i = n-1; i >= 0; i--){
        vec2.push_back(vec[i]);
    }
    vec2.push_back(vec[n-1]);

    ll x = 0, y = 0;
    for(int i = 0; i < n; i++){
        x += vec2[i].first * vec2[i+1].second;
        y += vec2[i].second * vec2[i+1].first;
    }

    double ans = abs(x-y);
    cout << fixed << setprecision(6) << ans/2;

	return 0;
}