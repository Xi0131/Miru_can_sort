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

int n, q;
vector<int> vec;
int b_search(int x){
    int L = 0, R = n - 1;
    int tgt = 0;
    if(x < vec[L]) return n;
    if(vec[R] < x) return 0;
    while(L <= R){
        int mid = L + (R - L) / 2;
        if(vec[mid+1] >= x && vec[mid] < x){
            tgt = mid;
            break;
        }
        else if(vec[mid] < x){
            L = mid + 1;
        }
        else{
            R = mid - 1;
        }
    }
    return vec.size() - tgt - 1;
}

int main()
{
    cin >> n >> q;
    vec.resize(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        cout << b_search(x) << endl;
    }

	return 0;
}