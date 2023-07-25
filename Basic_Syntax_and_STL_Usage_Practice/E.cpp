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
    map<string, int> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        m[s]++;
    }

    int cnt = 0;
    string ans;
    for(auto i : m){
        if(i.second > cnt){
            cnt = i.second;
            ans = i.first;
        }
    }

    cout << ans;

	return 0;
}