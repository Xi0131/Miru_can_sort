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
    vector<pii> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end());

    int ans = 0;
    queue<pii> q;
    q.push(vec[0]);
    int end = vec[0].second;
    for(int i = 1; i < n; i++){
        if(vec[i].first > q.front().second){
            ans = max(ans, (int)q.size());
            while(vec[i].first > q.front().second && q.size() > 0){
                q.pop();
            }
        }
        q.push(vec[i]);
    }
    ans = max(ans, (int)q.size());

    cout << ans;

	return 0;
}