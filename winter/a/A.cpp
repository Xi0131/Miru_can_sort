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
    string s;
    cin >> s;
    map<char, int> change = {{'B', 8}, {'E', 3}, {'I', 1}, {'O', 0}, {'S', 5}, {'Z', 2}};
    map<int, int> m;
    for(int i = 0; i < n; i++){
        // s[i];
        m[s[i]]++;
        if(m[s[i]] > 2){
            cout << "NO";
            return 0;
        }
        else if(m[s[i]] == 2){
            if(!change.count(s[i])){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        if(m[s[i]] == 2){
            cout << change[s[i]];
            m[s[i]]--;
        }
        else cout << s[i];
    }

	return 0;
}