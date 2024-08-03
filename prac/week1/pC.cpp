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
    ll n, day, cnt = 1, tmp;
    cin >> n >> day;
    ll arr[day];
    cin >> arr[0];
    for(int i = 1; i < day; i++){
        cnt++;
        cin >> tmp;
        if(cnt > 2){
            arr[i] = arr[i-1];
        }
        else{
            arr[i] = arr[i-1] + tmp;
        }
        if(cnt == 7) cnt = 0;
    }
    
    for(int i = 0; i < n; i++){
        int flag = 1;
        cin >> tmp;
        int l = 0, r = day - 1;
        int mid;
        while(l <= r){
            mid = (r - l) / 2 + l;
            if(arr[mid] == tmp){
                for(int j = mid; j >= 0; j--){
                    if(arr[j-1] == tmp){
                        mid = j-1;
                    }
                }
                cout << mid+1 << '\n';
                flag = 0;
                break;
            }
            else if(arr[mid] < tmp){
                l = mid + 1;
            }
            else if(arr[mid] > tmp){
                r = mid - 1;
                flag = 0;
            }
        }
        if(flag) cout << -1 << '\n';
        else if(arr[mid] < tmp){
            int j = mid;
            for(; j < day; j++){
                if(arr[j] > tmp){
                    break;
                }
            }
            cout << j+1 << '\n';
        }
        else if(arr[mid] > tmp){
            int j = mid;
            for(; j >= 0; j--){
                if(arr[j] < tmp){
                    break;
                }
            }
            cout << j+2 << '\n';
        }
    }

	return 0;
}