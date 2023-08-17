#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

int n, m, a, b;
long long c, dis[2][100005]; 
vector <pair<long long, int> > v[100005];
  
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v[a].push_back({c, b});
    }
    for (int i = 1; i <= n; i++){
        dis[0][i] = 1e18;
        dis[1][i] = 1e18;
    }
    dis[0][1] = 0;
    priority_queue <pair<long long, pair<int, int> >, vector<pair<long long, pair<int, int> > >, greater<pair<long long, pair<int, int> > > > pq;
    pq.push({0, {1, 0}});
    while (!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if (now.first > dis[now.second.second][now.second.first]) continue;
        for (auto i:v[now.second.first]){
            if (dis[now.second.second][i.second] > now.first + i.first){
                dis[now.second.second][i.second] = now.first + i.first;
                pq.push({dis[now.second.second][i.second], {i.second, now.second.second}});
            }
            if (now.second.second == 0){
                if (dis[1][i.second] > now.first + i.first/2){
                    dis[1][i.second] = now.first + i.first/2;
                    pq.push({dis[1][i.second], {i.second, 1}});
                }
            }
        }
    }
    for(int a = 0; a < 2; a++){
        for(int b = 0; b <= n; b++){
            cout << dis[a][b] << ' ';
        } cout << endl;
    }
    cout << dis[1][n] << "\n";
}