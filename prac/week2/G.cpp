#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<pii, vector<pii>, greater<pii>> vec;
        for(int i = 0, a, b; i < n; i++){
            cin >> a >> b;
            vec.push(make_pair(a, b));
        }
        ll ans = 0;
        ordered_set s;
        s.insert(vec.top().second);
        vec.pop();
        while(!vec.empty()){
            s.insert(vec.top().second);
            ans += s.order_of_key(vec.top().second);
            vec.pop();
        }
        cout << ans << '\n';
    }

	return 0;
}