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

char arr[1001][1001];
ll ans[1001][1001];


ll find(int i, int j){
    if(i == 0 || j == 0){
        return 0;
    }
    if(arr[i][j] == '#'){
        return 0;
    }
    if(ans[i][j] != -1){
        return ans[i][j];
    }
    return ans[i][j] = (find(i-1, j) + find(i, j-1)) % MOD;
}

int main()
{
    int h, w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 1; i < 1001; i++){
        for(int j = 1; j < 1001; j++){
            ans[i][j] = -1;
        }
    }
    
    ans[1][1] = 1;
    cout << find(h, w) << '\n';

    return 0;
}