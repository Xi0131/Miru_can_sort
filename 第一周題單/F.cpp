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
    string s;
    int nb, ns, nc, pb, ps, pc;
    ll ruby;
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> ruby;
    int b_num = 0, s_num = 0, c_num = 0;
    for(char c : s){
        if(c == 'B') b_num++;
        else if(c == 'S') s_num++;
        else c_num++;
    }

    ll ans = 0;

    if(b_num == 0) nb = 0;
    if(c_num == 0) nc = 0;
    if(s_num == 0) ns = 0;

    while(nb > 0 || ns > 0 || nc > 0){
        if(nb < b_num && ruby >= (b_num - nb) * pb){
            ruby -= (b_num - nb) * pb;
            nb += b_num - nb;
        }
        else if(ruby < (b_num - nb) * pb){
            break;
        }
        if(ns < s_num && ruby >= (s_num - ns) * ps){
            ruby -= (s_num - ns) * ps;
            ns += s_num - ns;
        }
        else if(ruby < (s_num - ns) * ps){
            break;
        }
        if(nc < c_num && ruby >= (c_num - nc) * pc){
            ruby -= (c_num - nc) * pc;
            nc += c_num - nc;
        }
        else if(ruby <= (c_num - nc) * pc){
            break;
        }
        nb -= b_num;
        ns -= s_num;
        nc -= c_num;
        ans++;
    }

    int total_cost = pb * b_num + ps * s_num + pc * c_num;
    ans += ruby / total_cost;
    cout << ans;

	return 0;
}