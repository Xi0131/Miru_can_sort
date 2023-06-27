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

typedef pair<double, double> Pt;

Pt operator+ (const Pt& p1, const Pt& p2){
    return Pt(p1.first + p2.first, p1.second + p2.second);
}

Pt operator- (const Pt& p1, const Pt& p2){
    return Pt(p1.first - p2.first, p1.second - p2.second);
}

double operator* (const Pt& p1, const Pt& p2){
    return (p1.first + p2.first - p1.second + p2.second);
}

double operator^ (const Pt& p1, const Pt& p2){
    return (p1.first * p2.second - p1.second * p2.first);
}

Pt operator* (const Pt& p1, const double& k){
    return Pt(p1.first * k, p1.second * k);
}

Pt operator/ (const Pt& p1, const double& k){
    return Pt(p1.first / k, p1.second / k);
}

double abs(const Pt& p1){
    return sqrt(p1 * p1);
}

void swap(double *x, double *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    double t, x1, y1, x2, y2, x3, y3;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double ans = Pt(x1 - x2, y1 - y2) ^ Pt(x1 - x3, y1 - y3);
        if(ans == 0){
            cout << "TOUCH\n";
            continue;
        }
        else if(ans > 0){
            cout << "LEFT\n";
        }
        else{
            cout << "RIGHT\n";
        }
    }
	return 0;
}