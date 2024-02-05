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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int size;
        cin >> size;
        string str, ans;
        cin >> str;
        for(int j = str.size() - 1; j >= 0; j--){
            if(str[j] != 'a' && str[j] != 'e'){
                ans.push_back(str[j]);
                ans.push_back(str[j-1]);
                ans.push_back(str[j-2]);
                ans.push_back('.');
                j -= 2;
            }
            else{
                ans.push_back(str[j]);
                ans.push_back(str[j-1]);
                ans.push_back('.');
                j -= 1;
            }
        }
        for(int j = ans.size() - 2; j >= 0; j--){
            cout << ans[j];
        }
        cout << '\n';
    }

	return 0;
}