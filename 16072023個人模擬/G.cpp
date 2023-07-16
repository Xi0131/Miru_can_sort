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

int check(vector<pii> vec, int tgt, int accum, int pos, int num){
	if(accum > tgt){
		return 0;
	}
	else{
		if(check(vec, tgt, accum, pos, vec[pos].first) == 0){

		}
		accum += vec[pos].first;
		return check(vec, tgt, accum, pos, vec[pos].first);
	}
}

int main()
{
	vector<pii> vec;
	int n, x;
	for(int k = 0; k < n; k++){
		int a, b;
		cin >> a >> b;
		vec.push_back(pii(a, b));
	}



	return 0;
}