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
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    ll ans = 0;
    while(pq.size() > 1){
            int tmp = pq.top();
            pq.pop();
            int merge = tmp + pq.top();
            ans += merge;
            pq.pop();
            pq.push(merge);
    }

    if(pq.size() == 1 && ans == 0) ans = pq.top();

    cout << ans;

	return 0;
}