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
const int maxn = 200005;

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    cin >> arr[0];
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        arr[i] = arr[i] ^ arr[i-1];
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a == 0){
            cout << arr[b] << endl;
        }
        else{
            cout << (arr[b] ^ arr[a-1]) << endl;
        }
    }

	return 0;
}