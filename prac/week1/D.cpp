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
    int t;
    cin >> t;
    while(t--){
        int n, flag = 1;
        ll sum = 0;
        set<ll> st;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        st.insert(0);
        for(int i = 0; i < n; i++){
            if(i % 2){
                sum -= arr[i];
            }
            else{
                sum += arr[i];
            }
            if(st.find(sum) != st.end()){
                cout << "YES\n";
                flag = 0;
                break;
            }
            st.insert(sum);
        }
        if(flag) cout << "NO\n";
    }

	return 0;
}