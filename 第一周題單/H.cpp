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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(make_pair(tmp, i));
    }

    sort(vec.begin(), vec.end());

    int pos1, pos2, impos = 1;

    int lhs = 0, rhs = vec.size() - 1;
    while(lhs != rhs){
        if(vec[lhs].first + vec[rhs].first == x){
            pos1 = vec[lhs].second;
            pos2 = vec[rhs].second;
            impos = 0;
            break;
        }
        else if(vec[lhs].first + vec[rhs].first > x){
            rhs--;
        }
        else{
            lhs++;
        }
    }

    if(impos){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << pos1 + 1 << " " << pos2 + 1;
    }

	return 0;
}