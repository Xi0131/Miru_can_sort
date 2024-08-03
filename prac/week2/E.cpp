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
    ll n, w;
    cin >> n >> w;
    vector<pair<int, pair<int, int>>> vec;
    for(int i = 0, a, b, c; i < n; i++){
        cin >> a >> b >> c;
        vec.push_back(make_pair(a, make_pair(b, c)));
    }
    sort(vec.begin(), vec.end());
    queue<pair<int, pair<int, int>>> q;
    for(int i = 0; i < n; i++){
        q.push(vec[i]);
    }

    int i = 0, flag = 0;
    ll acc = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    acc += q.front().second.second;
    pq.push(make_pair(q.front().second.first, q.front().second.second));
    i = q.front().first;
    q.pop();
    
    while(!pq.empty()){

        while(i == pq.top().first && !pq.empty()){
            acc -= pq.top().second;
            pq.pop();
        }

        while(i == q.front().first && !q.empty()){
            acc += q.front().second.second;
            pq.push(make_pair(q.front().second.first, q.front().second.second));
            q.pop();
        }
        
        if(acc > w){
            // watch(acc);
            cout << "No\n";
            return 0;
        }
        i++;
    }
    cout << "Yes\n";

	return 0;
}