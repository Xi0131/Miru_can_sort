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

int search_lake(int **lake, int **is_checked, int i, int j){
	if(lake[i][j] > 0){
		is_checked[i][j] = 1;
		return search_lake(lake, is_checked, i, j);
	}
	else{
		is_checked[i][j] = 1;
		return 0;
	}
}

int main()
{
	int t;
	cin >> t;
	for(int k = 0; k < t; k++){
		int a, b;
		int ans = 0;
		cin >> a >> b;
		int **lake = (int**) malloc(sizeof(int) * a);
		int **is_checked = (int**) malloc(sizeof(int) * a);
		for(int i = 0; i < b; i++){
			lake[i] = (int*) malloc(sizeof(int));
			is_checked[i] = (int*) malloc(sizeof(int));
		}
		for(int i = 0; i < a; i++)
			for(int j = 0; j < b; j++)
				cin >> lake[i][j];

		int all_check = 0;
		while(all_check == 0){
			int tmp_ans = 0;
			for(int i = 0; i < a; i++){
				for(int j = 0; j < b; j++){
					if(is_checked[i][j] == 0 && lake[i][j] > 0){
						tmp_ans += lake[i][j];
						is_checked[i][j] = 1;
						if(is_checked[i+1][j] == 0 && lake[i][j] > 0){
							
						}
					}
				}
			}
		}
	}

	return 0;
}