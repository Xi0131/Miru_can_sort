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
	vector<int> vec;
	int queries;
	cin >> queries;
	for(int k = 0; k < queries; k++){
		int type;
		cin >> type;
		if(type == 1){
			int add_num;
			cin >> add_num;
			vec.push_back(add_num);
			make_heap(vec.begin(), vec.end());
		}
		else if(type == 2){
			int del_num, cnt;
			cin >> del_num >> cnt;
			for(int i = 0; i < vec.size(); i++){
				if(vec[i] == del_num){
					for(int j = 0; j < cnt; j++){
						if(vec[i] == del_num && i < vec.size()){
							vec.erase(vec.begin() + i);
						}
						else{
							break;
						}
					}
					break;
				}
			}
		}
		else{
			cout << vec[0] - vec[vec.size() - 1] << endl;
		}
		// for(int i = 0; i < vec.size(); i++){
		// 	watch(vec[i]);
		// }
	}

	return 0;
}