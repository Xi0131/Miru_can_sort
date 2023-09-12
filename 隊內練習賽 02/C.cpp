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

vector<pii> red, blue;
// priority_queue<pii, vector<pii>, greater<pii>> pq_red;
int n, ans;

int main()
{
    cin >> n;
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        // pq_red.push({x, y});
        red.push_back({x, y});
    }
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        blue.push_back({x, y});
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    for(int i = n - 1; i >= 0; i--){
        pii 
        for(int j = red.size() - 1; j >= 0; j--){

        }
    }

	return 0;
}