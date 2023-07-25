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
    string a, b;
    cin >> a >> b;
    
    bool flag = 1;
    int x = a.size() - 1, y = b.size() - 1;
    while(x >= 0 && y >= 0){
        if(a[x] - '0' + b[y] - '0' > 9){
            flag = 0;
            break;
        }
        else{
            x--;
            y--;
        }
    }

    if(flag == 1) cout << "Easy";
    else cout << "Hard";

	return 0;
}