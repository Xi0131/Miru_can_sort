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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int min_index = 0;
    for(int i = 0; i < a.size(); i++){
        int max = a[i] + k, min = a[i] - k;
        for(int j = min_index; j < b.size(); j++){
            if(b[j] >= min && b[j] <= max){
                min_index++;
                ans++;
                break;
            }
            else if(b[j] > max){
                break;
            }
            else{
                min_index++;
            }
        }
    }

    cout << ans;

	return 0;
}