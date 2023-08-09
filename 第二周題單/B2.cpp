// took ac code as reference, but still dont understand why should ignore that part

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

vector<vector<int>> adj;
ll ans = 0;
int n, m;

int main()
{
    cin >> n >> m;
    adj.resize(n+1);
    vector<int> in(n+1, 0); 
    vector<ll> rec(n+1, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for(int i = 2; i < n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    // while(!q.empty()){
    //     int tmp = q.front();
    //     q.pop();
    //     for(int i : adj[tmp]){
    //         in[i]--;
    //         if(in[i] == 0) q.push(i);
    //     }
    // }

    for(int i : adj[1]){
        rec[i]++;
    }

    q.push(1);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i : adj[tmp]){
            in[i]--;
            rec[i] = (rec[i] + rec[tmp]) % MOD;
            if(in[i] == 0){
                q.push(i);
            }
        }
    }

    cout << rec[n] % MOD;

	return 0;
}