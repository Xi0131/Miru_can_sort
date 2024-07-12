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

int arr[1001][1001];

int main()
{
    int n, q;
    cin >> n >> q;
    char tmp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> tmp;
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            if(tmp == '*') arr[i][j]++;
        }
    }


    int x1, y1, x2, y2;
    while(q--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (arr[x2][y2] + arr[x1-1][y1-1] - arr[x2][y1-1] - arr[x1-1][y2]) << endl;
        watch(arr[x2][y2] + arr[x1-1][y1-1] - arr[x2][y1-1] - arr[x1-1][y2]);
    }

	return 0;
}