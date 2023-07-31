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
    int Q;
    cin >> Q;
    map<int, int> m;
    for(int i = 0; i < Q; i++){
        int n, tmp;
        cin >> n;
        if(n == 1){
            cin >> tmp;
            m[tmp]++;
        }
        else if(n == 2){
            int cnt;
            cin >> tmp >> cnt;
            m[tmp] -= min(m[tmp], cnt);
            if(m[tmp] == 0) m.erase(tmp);
        }
        else{
            cout << m.rbegin()->first - m.begin()->first << endl;
        }
    }

	return 0;
}