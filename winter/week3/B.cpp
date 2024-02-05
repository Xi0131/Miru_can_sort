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
    string s, t, ans = "\0", tmp = "\0";
    cin >> s >> t;
    vector<int> vec[2];
    for(int i = 0; i <= s.size(); i++){
        vec[0].push_back(0);
        vec[1].push_back(0);
    }
    watch(vec[0][0]);

    for(int i = 1; i <= t.size(); i++){
        cout << '\n';
        for(int j = 1; j <= s.size(); j++){
            if(s[j-1] == t[i-1]){
                vec[1][j] = vec[0][j-1] + 1;
            }
            else{
                vec[1][j] = max(vec[0][j], vec[1][j-1]);
            }
        }
        for(int j = 1; j <= s.size(); j++){
            if(vec[1][j] > vec[1][j-1]){
                tmp.push_back(s[j-1]);
            }
        }
        for(int j = 0; j <= s.size(); j++){
            cout << vec[1][j];
        } cout << '\n';
        swap(vec[0], vec[1]);
        watch(tmp);
        ans = tmp;
        tmp = "\0";
    }
    watch(vec[1][s.size()]);
    cout << ans << '\n';
    // for(int i = 0; i <= 1; i++){
    // }

	return 0;
}