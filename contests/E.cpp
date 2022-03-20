#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int N, M;
Graph G;
// tmpの任意の点からはじめて、全ての頂点の最短距離を出す→その間の0は2倍する
ll rec(int tmp) {
  bitset<18> bit(tmp);
  int start = -1;
  int cnt_one = 0;
  rep(i,N) {
    if(bit.test(i)) {
      start = i;
      cnt_one++;
    }
  }
  if(start == -1) return 0;  // 空列のときは長さ0
  if(cnt_one == 1) return 1;  // 1つのときは長さ1
  // startからはじめて全部の最短距離
  vector<int> dist(N, -1);
  queue<int> que;
  dist[start] = 0;
  que.push(start);
  while(!que.empty()) {
    int v = que.front();
    que.pop();
    for(int nv : G[v]) {
      if(dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }
  int goal_dist = 0;
  rep(i,N) {
    if(bit.test(i)) {
      goal_dist = max(goal_dist, dist[i]);
    }
  }
} 

int main() {
  cin >> N >> M;
  G.resize(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int tmp = 0; tmp < (1<<N); tmp++) {
    bitset<18> bit(tmp);

    if()
  }
}

// bitが1立っている任意の頂点から、1が立つ頂点への最短経路を見つけて、その間に通る点の数を2倍にする方法を取ろうとした
// start(bitが1立っている任意の頂点)からの全ての最短経路を出して、最も遠いい1の場所より距離が短い頂点の個数を2倍にしようとした
// その距離だと、その間にある頂点だけでなく、それより外にある頂点数も出すことになってしまい....