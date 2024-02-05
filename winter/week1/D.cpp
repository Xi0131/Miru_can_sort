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
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        vector<ll> v1, v2;
        int n, tmp;
        cin >> n;
        if(n == 1){
            cout << "NO\n";
            continue;
        }
        cin >> tmp;
        v1.push_back(tmp);
        cin >> tmp;
        v2.push_back(tmp);
        for(int j = 2; j < n; j++){
            cin >> tmp;
            if(j%2) v2.push_back(tmp + v2.back());
            else v1.push_back(tmp + v1.back());
        }
        int l1 = 0, r1 = v1.size()-1;
        int l2 = 0, r2 = v2.size()-1;
        ll sum = v2[r2] - v1[r1];
        if(sum == 0){
            
        }
    }

	return 0;
}