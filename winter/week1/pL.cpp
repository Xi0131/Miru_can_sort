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

int n;

void find(int sz, int *arr, int *visited, int acc, int st){
    if(sz == 0){
        if(acc >= 0) cout << acc << " Kangaroo\n";
        else cout << acc << " Koala\n";
    }

    for(int i = st; i < n; i++){
        if(!visited[i]){
            visited[i] = 1;
            find(sz-1, arr, visited, acc + arr[i], i);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int visited[n], sum = 0;
    memset(visited, 0, sizeof(int) * n);

    for(int i = 0; i <= n; i++){
        find(i, arr, visited, sum, 0);
    }

	return 0;
}