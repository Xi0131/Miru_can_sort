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
    int n, m;
    cin >> n >> m;
    int maxpos[n+1], minpos[n+1], pos[n+1], real[n+1];
    for(int i = 0; i <= n; i++){
        real[i] = i;
        pos[i] = i;
        maxpos[i] = i;
        minpos[i] = i;
    }
    for(int i = 0, tmp; i < m; i++){
        cin >> tmp;
        int change = real[pos[tmp]-1];
        // watch(real[pos[tmp]]);
        if(pos[tmp] > 1){
            // debug;
            swap(real[pos[tmp]], real[pos[change]]);
            swap(pos[tmp], pos[change]);
            maxpos[tmp] = min(maxpos[tmp], pos[tmp]);
            minpos[tmp] = max(minpos[tmp], pos[tmp]);
            maxpos[change] = min(maxpos[change], pos[change]);
            minpos[change] = max(minpos[change], pos[change]);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << maxpos[i] << ' ' << minpos[i] << '\n';
    }

	return 0;
}