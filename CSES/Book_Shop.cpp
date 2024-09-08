// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define debug cerr << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int maxn = 200005;
const int MAXN = 2e6 + 5;

vector<int> vec[2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n, x;
    cin >> n >> x;
    vec[0].resize(x+1);
    vec[1].resize(x+1);
    
    // int h[n+1], s[n+1];
    // for(int i = 1; i <= n; i++) cin >> h[i];
    // for(int i = 1; i <= n; i++) cin >> s[i];

    vector<pair<int, int>> arr(n+1);
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());

    for(int i = 1; i <= n; i++){
        vec[0][arr[i].first] = arr[i].second;
    }
    

    for(int i = 1; i < x; i++){
        for(int j = 0; j < n; j++){
            
        }
        swap(vec[0], vec[1]);
    }

	return 0;
}