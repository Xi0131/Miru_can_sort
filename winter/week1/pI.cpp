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

int n, mx, ans, w1, w2;
vector<int> v;

void dfs1(int, int, int, int);
void dfs2(int, int, int, int);

void dfs1(int acc1, int acc2, int add, int idx){
    int flag = 0;
    if(idx >= v.size()-1) flag = 1;

    if(add == 1) acc1 += v[idx];
    else{
        acc1 += v[idx];
        if(!flag) acc1 += v[idx+1];
    }

    if(acc1 > mx || flag){
        if(acc1 > acc2) w1++;
        else w2++;
        return;
    }
    dfs2(acc1, acc2, 1, idx);
    dfs2(acc1, acc2, 2, idx);
}

void dfs2(int acc1, int acc2, int add, int idx){
    int flag = 0;
    if(idx >= v.size()-1) flag = 1;

    if(add == 1) acc2 += v[idx];
    else acc2 += v[idx] + v[idx+1];

    if(acc2 > mx || flag){
        if(acc2 > acc1) w2++;
        else w1++;
        return;
    }
    dfs1(acc1, acc2, 1, idx);
    dfs1(acc1, acc2, 2, idx);
}

int main()
{
    cin >> n >> mx;
    for(int i = 0, tmp; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    dfs1(0, 0, 1, 0);
    dfs1(0, 0, 2, 0);

    watch(w1);
    watch(w2);
    cout << (double)w2 / (double)w1;

	return 0;
}