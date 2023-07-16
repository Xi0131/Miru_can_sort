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

vector<int> alp(26);

int main()
{
	string S;
	cin >> S;
	for(int i = 0; i < S.size(); i++){
		alp[S[i] - 'A']++;
	}

	if(S.size() % 2 == 0){
		for(int i = 0; i < 26; i++){
			if(alp[i] % 2 != 0){
				cout << "NO SOLUTION";
				return 0;
			}
		}
		for(int i = 0; i < 26; i++){
			if(alp[i] > 0){
				for(int j = 0; j < alp[i] / 2; j++){
					cout << char(i + 'A');
				}
			}
		}
		for(int i = 25; i >= 0; i--){
			if(alp[i] > 0){
				for(int j = 0; j < alp[i] / 2; j++){
					cout << char(i + 'A');
				}
			}
		}
	}
	else{
		int one_odd = 0, odd_pos;
		for(int i = 0; i < 26; i++){
			if(alp[i] % 2 != 0){
				odd_pos = i;
				one_odd++;
			}
		}

		if(one_odd != 1){
			cout << "NO SOLUTION";
			return 0;
		}

		for(int i = 0; i < 26; i++){
			if(alp[i] > 0){
				for(int j = 0; j < alp[i] / 2; j++){
					cout << char(i + 'A');
				}
			}
		}
		cout << char(odd_pos + 'A');
		for(int i = 25; i >= 0; i--){
			if(alp[i] > 0){
				for(int j = 0; j < alp[i] / 2; j++){
					cout << char(i + 'A');
				}
			}
		}
	}

	return 0;
}