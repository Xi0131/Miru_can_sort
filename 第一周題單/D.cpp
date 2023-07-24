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
    deque<ll> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());
    
    int ans = 0;
    while(vec.size() > 0){
        ans++;
        int i = vec.size() - 1;
        if(vec.size() == 1){
            vec.pop_back();
        }
        else if(vec[i] + vec[0] > x){
            vec.pop_back();
        }
        else{
            vec.pop_back();
            vec.pop_front();
        }
    }

    cout << ans;

	return 0;
}