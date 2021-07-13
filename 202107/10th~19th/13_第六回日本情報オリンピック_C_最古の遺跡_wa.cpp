#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  // それぞれの頂点に対してO(N)
  // 他の頂点を見ていくO(N)→O(N^2)
  // どうやって見ていくか, どうやって正方形の判定ができるか？
  // →各頂点の距離をvecでもって、sortして、同じ距離が2つあるandもう一つの点もある(大きい順から)
  // これで合計O(N^2longN)かかる.
  int N; cin >> N;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    vector<int> dist(N); // それぞれの頂点vec[i],vec[j]への距離を持つ
    for(int j = 0; j < N; j++) {
      dist[j] = pow(vec[i].first - vec[j].first, 2) + pow(vec[i].second - vec[j].second, 2);
    }
    sort(dist.begin(), dist.end());
    for(int j = N-1; j > 0; j--) {
      if(dist[j] == dist[j-1]) {
        // 同じ距離を持つ要素が2つあり、dist[j]*2を持つ要素があったら、正方形
        auto result = find(dist.begin(), dist.end(), dist[j]*2);
        if(result != dist.end()) {
          ans = max(ans, dist[j]);
        }
      }
    }
  }
  cout << ans << endl;
}