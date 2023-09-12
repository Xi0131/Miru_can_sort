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

int arr[1001][1001];

int main()
{
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char c;
			cin >> c;
			if(c == '*'){
				arr[i][j] = arr[i-1][j] + arr[i][j-1] + 1 - arr[i-1][j-1];
			}
			else{
				arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
			}
		}
	}

	for(int i = 0; i < q; i++){
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << arr[y2][x2] - arr[y2][x1-1] - arr[y1-1][x2] + arr[y1-1][x1-1] << endl;
	}

	return 0;
}