#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi " << __LINE__ << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const int maxn = 200005;
const int MAXN = 2e6 + 5;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    while(1){
        int n;
        string s;
        cin >> n;
        if(n == 0) break;
        cin >> s;
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        map<string, int> mp;
        // watch(s[n-1]);
        // watch(tmp[0]);
        // watch(s[n-1] + tmp[0]);
        string a;
        a.push_back(s[n-1]);
        a.push_back(tmp[0]);
        a.pop_back();
        mp[a]++;
    }

	return 0;
}