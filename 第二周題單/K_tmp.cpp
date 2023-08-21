#include <iostream>
#include <vector>
using namespace std;
  
int n, q, a, b, p[200005][20], d[200005];
vector <int> v[200005];
  
void dfs(int x, int pre){
    for (auto i:v[x]){
        if (i == pre) continue;
        p[i][0] = x;
        d[i] = d[x]+1;
        dfs(i, x);
    }
}
int solve(int a, int b){
    // 一定要前小後大
    int x = d[a], y = d[b], ret = x+y;
    if (x > y){
        swap(a, b);
        swap(x, y);
    }
    // calculate diff of depth of node a and b
    y -= x;
    // binary search in a very ugly and difficult to understand way, stop when depth of both node is same
    for (int i = 0; i < 20; i++){
        if (y & (1<<i)){
            b = p[b][i];
        }
    }
    // return bc a and b is same node, which means b is anc of a
    if (a == b) return ret-d[a]*2;
    // since depth of both node is same, watch anc of both node to find LCA
    // if found LCA, a and b will be same, p[a][i] and p[b][i] are same, hence (p[a][i] != p[b][i]) will always return false
    for (int i = 19; i >= 0; i--){
        if (p[a][i] != p[b][i]){
            a = p[a][i];
            b = p[b][i];
        }
    }

    ret -= d[p[a][0]]*2;
    return ret;
}
  
int main() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    while (q--){
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
}