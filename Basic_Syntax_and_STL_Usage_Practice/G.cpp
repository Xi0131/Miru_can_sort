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

vector<int> x, y, s, v;

int find(int a){
    if(a == s[a]) return a;
    else return s[a] = find(s[a]);
}

bool join(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return true;
    else{
        s[fa] = fb;
        return false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    v.resize(n+1);
    bool flag = false;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b]++;
        x.push_back(a);
        y.push_back(b);
    }

    s.resize(n);
    for(int i = 0; i < n+1; i++) if(v[i] > 2) flag = true;
    for(int i = 0; i < n+1; i++) s[i] = i;
    for(int i = 0; i < m; i++){
        if(join(x[i], y[i])){
            flag = true;
        }
    }

    if(flag) cout << "No";
    else cout << "Yes";

	return 0;
}