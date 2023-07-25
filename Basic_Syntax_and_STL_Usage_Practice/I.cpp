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
    int h, w;
    cin >> h >> w;
    char s;
    vector<pii> v;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s;
            if(s == 'o'){
                v.push_back(make_pair(i, j));
            }
            if(v.size() == 2) break;
        }
    }

    cout << abs(v[0].first - v[1].first) + abs(v[0].second - v[1].second);

	return 0;
}