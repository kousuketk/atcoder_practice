#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<P>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
struct Edge {
  int s;
  int t;
  ll cost;
};

int main() {
  int N, M; cin >> N >> M;
  vector<Edge> vec(M);
  rep(i,M) {
    int s, t; cin >> s >> t;
    ll d; cin >> d;
    s--, t--;
    d = -d;
    vec[i] = Edge{s, t, d};
  }
  vector<ll> dist(N, INF);
  dist[0] = 0;
  rep(i,N) {
    rep(j,M) {
      Edge ed = vec[j];
      if(dist[ed.s] == INF) continue;
      if(dist[ed.t] <= dist[ed.s] + ed.cost) continue;
      dist[ed.t] = dist[ed.s] + ed.cost;
      if(i == N-1 && ed.t == N-1) {  // N回目頂点iを更新したらinf
        cout << "inf" << endl;
        return 0;
      }
    }
  }
  // if(negative[N-1]) cout << "inf" << endl;
  cout << -dist[N-1] << endl;
  return 0;
}

// 最初ベルマンフォードを使って、最大コストを出そうとしたが。
// ベルマンフォードは最小コスト, 最短経路を出すことしかできないため。
// (最大コストを出す)=(コストにマイナスを付けて最小コスト)でベルマンフォードを使用する。
// ↓
// 負の閉路があればinfを出してしまったが、それは頂点1からNにいくのに必要ないときもinfとしてしまったので。
// 別に頂点1からNにいくのに関係ない負の閉路があってもいいから。
// 頂点1からNにいくときに負の閉路だったときのみ(頂点Nが負の閉路を含むときのみ)infを出力するようにする。
// ↓
// V回目も頂点Nを更新したらinfを出力する