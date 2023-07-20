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
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec.at(i);

    int lhs = 0, rhs = 0;
    int ans = 0;

    map<int, int> cnt;

    while(vec.size() - lhs >= ans){
        for(; rhs < vec.size(); rhs++){
            if(cnt[vec[rhs]] == 0) cnt[vec[rhs]]++;
            else if(vec[rhs] == vec[lhs]){
                ans = max((int)cnt.size(), ans);
                lhs++;
            }
            else{
                ans = max((int)cnt.size(), ans);
                for(; lhs < rhs;){
                    cnt.erase(vec[lhs]);
                    lhs++;
                    if(vec[lhs] == vec[rhs]){
                        lhs++;
                        rhs++;
                        break;
                    }
                }
                break;
            }
            if(rhs == vec.size() - 1){
                ans = max((int)cnt.size(), ans);
                lhs++;
            }
        }
    }

    cout << ans;

	return 0;
}