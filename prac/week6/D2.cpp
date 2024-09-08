#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

int n, q;
vector<int> arr(maxn);
vector<ll> bit(maxn * 4);
vector<int> ranked(maxn);

struct ele{
    char c;
    int a, b;
};

int lowbit(int x){
    return x & -x;
}

void update(int i, int x){
    int pos = upper_bound(ranked.begin(), ranked.end(), i) - ranked.begin();
    while(pos <= maxn * 4){
        bit[pos] += x;
        pos += lowbit(pos);
    }
}

ll query(int x){
    int pos = upper_bound(ranked.begin(), ranked.end(), x) - ranked.begin();
    ll ret = 0;
    while(pos){
        ret += bit[pos];
        pos -= lowbit(pos);
    }
    return ret;
}

vector<int> solve(vector<int> a){
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    // for(int i = 0; i < a.size(); i++)
    //     a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    return b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> q;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    ranked = arr;

    vector<ele> ques;
    char c;
    int a, b;
    for(int i = 0; i < q; i++){
        cin >> c >> a >> b;
        ques.push_back({c, a, b});
        if(c == '!'){
            ranked.push_back(b);
        }
    }
    ranked = solve(ranked);
    // for(int i = 0; i < ranked.size(); i++) watch(ranked[i]);

    for(int i = 0; i < n; i++){
        update(arr[i], 1);
    }
    // debug;
    
    for(int i = 0; i < q; i++){
        ques[i].a--;
        if(ques[i].c == '!'){
            update(arr[ques[i].a], -1);
            arr[ques[i].a] = ques[i].b;
            update(arr[ques[i].a], 1);
        }
        else{
            cout << query(ques[i].b) - query(ques[i].a) << '\n';
        }
    }

	return 0;
}