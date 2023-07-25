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
    int x, n;
    cin >> x >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    ll ans = 0;
    while(q.size() > 1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;
        q.push(a + b);
    }

    cout << ans;

	return 0;
}