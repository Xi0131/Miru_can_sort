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
    string str1, str2;
    cin >> str1 >> str2;
    // int arr[2][str1.size() + 1];
    vector<int> arr[2];
    for(int i = 0; i <= str2.size(); i++){
        // arr[0][i] = 0;
        // arr[1][i] = 0;
        arr[0].push_back(0);
        arr[1].push_back(0);
    }
    watch(arr[0][0]);

    string ans, tmp;
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[j-1] == str2[i-1]){
                arr[1][j] = arr[0][j-1] + 1;
            }
            else{
                arr[1][j] = max(arr[0][j-1], arr[1][j]);
            }
        }
        for(int j = 1; j <= str2.size(); j++){
            if(arr[1][j] > arr[1][j-1]){
                tmp.push_back(str2[j-1]);
            }
        }
        swap(arr[0], arr[1]);
        ans = tmp;
        tmp.clear();
        debug;
    }
    cout << ans;

	return 0;
}