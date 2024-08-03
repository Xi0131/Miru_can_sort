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

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    if(a.first == b.first) return a.second.first > b.second.first;
    return a.first < b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> vec;
    vector<pair<int, pair<int, int>>> arr;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        arr.push_back(make_pair(a, make_pair(b, i+1)));
    }
    sort(arr.begin(), arr.end(), cmp);
    queue<pair<int, pair<int, int>>> vec;
    for(int i = 0; i < n; i++) vec.push(arr[i]);

    vector<int> ans;

    int end = vec.front().second.first;
    ans.push_back(vec.front().second.second);
    if(vec.front().first != 1){
        cout << "NO\n";
        return 0;
    }
    vec.pop();

    int pending = end, pendpos = ans[0];


    while(!vec.empty()){

        if(vec.front().first > end + 1){
            cout << "NO\n";
            return 0;
        }
        pending = end;
        while(vec.front().first <= end + 1 && !vec.empty()){
            if(vec.front().second.first > pending){
                pending = vec.front().second.first;
                pendpos = vec.front().second.second;
            }
            vec.pop();
        }
        end = pending;
        if(pendpos != ans[ans.size() - 1]) ans.push_back(pendpos);
    }

    if(end < m){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n" << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';

	return 0;
}