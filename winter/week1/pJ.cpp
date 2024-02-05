#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

ll mx;
int n, x, y;
vector<int> vec;
set<ll> s;

void dfs(int sz, int i, ll acc){
    if(i == sz / 2){
        s.insert(acc);
        return;
    }
    dfs(sz, i+1, acc);
    dfs(sz, i+1, acc + vec[i]);
}

void dfs2(int sz, int i, ll acc){
    if(i == sz){
        if(acc <= x){
            auto it = s.lower_bound(x - acc);
            if(it != s.begin()) it--;
            it++;
            if(!(it != s.end() && *it == x-acc)) it--;
            if(it != s.end()){
                mx = max(mx, acc + *it);
            } 
            else{
                mx = max(mx, acc);
            }
        }
        return;
    }
    dfs2(sz, i+1, acc);
    dfs2(sz, i+1, acc + vec[i]);
}

int main()
{
    cin >> n >> x >> y;
    int wine[n], alc[n];
    for(int i = 0, tmp; i < n; i++){
        cin >> wine[i];
    }
    for(int i = 0, tmp; i < n; i++){
        cin >> alc[i];
    }

    for(int i = 0; i < n; i++){
        if(alc[i] <= y) vec.push_back(wine[i]);
    }

    dfs(vec.size(), 0, 0);
    dfs2(vec.size(), vec.size()/2, 0);

    cout << mx;

	return 0;
}