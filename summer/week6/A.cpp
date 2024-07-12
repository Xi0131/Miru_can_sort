#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;


int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i != 0) arr[i] ^= arr[i-1];
    }

    for(int i = 0, a, b; i < q; i++){
        cin >> a >> b;
        if(a == 1) cout << arr[b-1] << '\n';
        else cout << ((arr[b-1]) ^ (arr[a-2])) << '\n';
    }

	return 0;
}