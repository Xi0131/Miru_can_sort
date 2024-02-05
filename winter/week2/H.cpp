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
    priority_queue<pii, vector<pii>, greater<pii>> vec;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        if(a < b) vec.push(make_pair(a, b));
        else vec.push(make_pair(b, a));
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = vec.top().first, acc = 1;
    pq.push(vec.top().second);
    vec.pop();
    while(!vec.empty()){

        while(vec.top().first == i && !vec.empty()){
            pq.push(vec.top().second);
            vec.pop();
        }

        while(pq.top() == i && !pq.empty()){
            while(!pq.empty()) pq.pop();
            ans.push_back(i);
        }

        i++;
    }
    if(!pq.empty()) ans.push_back(pq.top());

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';

	return 0;
}