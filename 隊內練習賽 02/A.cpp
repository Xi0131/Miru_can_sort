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

int t, n;
ll h;

int main()
{
    cin >> t;
    while(t--){
        cin >> n >> h;
        priority_queue<int> pq;
        while(n--){
            int x;
            cin >> x;
            pq.push(x);
        }
        if(n == 1){
            if(h % pq.top() > 0){
                cout << h / pq.top() + 1;
            }
            else cout << h / pq.top();
        }
        else{
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ll sum = a + b;
            int tmp = h / sum;
            h -= sum * tmp;
            if(h > 0){
                if(h - a <= 0){
                    cout << tmp * 2 + 1 << endl;
                }
                else{
                    cout << tmp * 2 + 2 << endl;
                }
            }
            else{
                if(h + b <= 0){
                    cout << tmp * 2 - 1 << endl;
                }
                else{
                    cout << tmp * 2 << endl;
                }
            }
        }
    }

	return 0;
}