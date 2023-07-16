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

int main()
{
    float t, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        float m1 = (y1 - y2)/(x1 - x2);
        float m2 = (y3 - y4)/(x3 - x4);
        watch(m1);
        watch(m2);
        if(m1 == m2){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
	return 0;
}