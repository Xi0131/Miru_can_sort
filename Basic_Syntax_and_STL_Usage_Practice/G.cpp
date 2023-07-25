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
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    bool flag = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
        if(mp[a] > 2 || mp[b] > 2){
            flag = 1;
            break;
        }
    }

    if(flag) cout << "No";
    else cout << "Yes";

	return 0;
}