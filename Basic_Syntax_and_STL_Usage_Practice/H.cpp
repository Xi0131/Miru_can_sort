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

int n;
vector<vector<int>> big_v;
int cnt;

bool compare_vec(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

void dfs(int a, ll div){
    for(int i = 0; i < big_v[a].size(); i++){
        if(a == big_v.size() - 1){
            if((ld)div / (ld)big_v[a][i] == 1.0){
                cnt++;
            }
            continue;
        }
        if(div % big_v[a][i] == 0 && a < big_v.size() - 1){
            dfs(a+1, div / big_v[a][i]);
        }
    }
}

int main()
{
    ll x;
    cin >> n >> x;
    big_v.resize(n);
    for(int i = 0; i < n; i++){
        int size;
        cin >> size;
        vector<int> tmp(size);
        for(int j = 0; j < size; j++){
            cin >> tmp[j];
        }
        big_v[i] = tmp;
    }

    sort(big_v.begin(), big_v.end(), compare_vec);
    dfs(0, x);

    cout << cnt;

	return 0;
}