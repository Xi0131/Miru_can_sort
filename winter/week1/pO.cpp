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
    int n, t;
    cin >> n >> t;
    bool arr[n+1];
    int cnt = n;
    vector<vector<int>> vec(t+1);
    memset(arr, true, sizeof(bool) * n+1);
    for(int i = 0; i < n; i++){
        int size;
        cin >> size;
        for(int j = 0; j < size; j++){
            int tmp;
            cin >> tmp;
            vec[tmp].push_back(i);
        }
    }

    for(int i = 0; i < t; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            for(int j = 0; j < vec[i+1].size(); j++){
                if(arr[vec[i+1][j]]){
                    cnt--;
                    arr[vec[i+1][j]] = false;
                }
            }
        }
    }

    cout << cnt << '\n';
    for(int i = 0; i < n; i++){
        if(arr[i]) cout << i+1 << ' ';
    }

	return 0;
}