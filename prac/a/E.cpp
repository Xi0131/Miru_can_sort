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
    cin >> n;
    char arr[n][n], tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
        getchar();
    }
    cin >> m;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            if(i < n){
                for(int j = n-1-i, k = 0; j < n; j++, k++){
                    cout << arr[k][j];
                }
            }
            else{
                for(int j = 0, k = i-n+1; k < n; j++, k++){
                    cout << arr[k][j];
                }
            }
        }
        else{
            if(i < n){
                for(int j = n-1, k = i; k >= 0; j--, k--){
                    cout << arr[k][j];
                }
            }
            else{
                for(int j = n-2-(i-n), k = n-1; j >= 0; j--, k--){
                    cout << arr[k][j];
                }
            }
        }
    }

	return 0;
}