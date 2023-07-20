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
    vector<int> a, b;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    int ans = 0;
    for(int i = 0; i < a.size(); i++){
        int find_appart = a[i];
        int max_size = find_appart + k, min_size = find_appart - k;
        for(int j = 0; j < b.size(); j++){
            if(b[j] <= max_size && b[j] >= min_size){
                b.erase(b.begin() + j);
                ans++;
            }
        }
    }

    cout << ans;

	return 0;
}