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
    string arr1 = "QWERTYUIOP", arr2 = "ASDFGHJKL", arr3 = "ZXCVBNM";
    int q;
    cin >> q;
    char c;
    cin >> c;

    int idx, pt;
    if(arr1.find(c) != arr1.npos) idx = arr1.find(c), pt = 1;
    if(arr2.find(c) != arr2.npos) idx = arr2.find(c), pt = 2;
    if(arr3.find(c) != arr3.npos) idx = arr3.find(c), pt = 3;

    while(q--){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            int step;
            cin >> step;
            if(pt == 1){
                switch (step)
                {
                case 1:
                    if(idx > 0) idx--;
                    break;
                case 4:
                    if(idx < arr1.size()-1) idx++;
                    break;
                case 5:
                    if(idx != 0) pt++, idx--;
                    break;
                case 6:
                    if(idx != arr1.size()-1) pt++;
                    break;
                }
            }
            else if(pt == 2){
                switch (step)
                {
                case 1:
                    if(idx > 0) idx--;
                    break;
                case 2:
                    pt--;
                    break;
                case 3:
                    pt--, idx++;
                    break;
                case 4:
                    if(idx < arr2.size()-1) idx++;
                    break;
                case 5:
                    if(idx != 0) pt++, idx--;
                    break;
                case 6:
                    if(idx < arr2.size()-2) pt++;
                    break;
                }
            }
            else{
                switch (step)
                {
                case 1:
                    if(idx > 0) idx--;
                    break;
                case 2:
                    pt--;
                    break;
                case 3:
                    pt--, idx++;
                    break;
                case 4:
                    if(idx < arr3.size()-1) idx++;
                    break;
                }
            }
        }
        else{
            if(pt == 1){
                cout << arr1[idx];
            }
            else if(pt == 2){
                cout << arr2[idx];
            }
            else{
                cout << arr3[idx];
            }
        }
    }

	return 0;
}