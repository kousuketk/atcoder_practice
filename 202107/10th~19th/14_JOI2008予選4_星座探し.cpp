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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int M, N;
  cin >> M;
  // Mを入れていく
  int star_x, star_y;
  cin >> star_x >> star_y;
  vector<int> origin_x(M);
  vector<int> origin_y(M);
  rep(i,M-1) {
    int tmp_x, tmp_y;
    cin >> tmp_x >> tmp_y;
    origin_x[i+1] = star_x - tmp_x;
    origin_y[i+1] = star_y - tmp_y;
  }
  // Nを入れていく
  cin >> N;
  vector<int> un_x(N);
  vector<int> un_y(N);
  rep(i,N) {
    cin >> un_x[i];
    cin >> un_y[i];
  }
  for(int i = 0; i < N; i++) {
    // i番目を見ていく
    vector<int> tmp_x(N);
    vector<int> tmp_y(N);
    for(int j = 0; j < N; j++) {
      tmp_x[j] = un_x[i] - un_x[j];
      tmp_y[j] = un_y[i] - un_y[j];
    }
    // ソートして、O(MlogN)にする
    sort(ALL(tmp_x));
    sort(ALL(tmp_y));
    // origin_x, origin_yにある配列が全部あったらok
    int tmp_count = 0;
    for(int j = 0; j < M; j++) {
      auto itr_x = lower_bound(ALL(tmp_x), origin_x[j]);
      auto itr_y = lower_bound(ALL(tmp_y), origin_y[j]);
      int idx = itr_x - tmp_x.begin();
      int idy = itr_y - tmp_y.begin();
      if(origin_x[j] == tmp_x[idx] && origin_y[j] == tmp_y[idy]) tmp_count++;
      if(tmp_count == M) {
        // 星座が見つかった
        // star_x, star_yと、un_x[i], un_y[i]を見比べる
        cout << (un_x[i] - star_x) << " " << (un_y[i] - star_y) << endl;
        return 0; 
      }
    }
  }
  cout << "No" << endl;
}

// →計算量O(N^2+NMlogN)で行ける
// sortしてlogNにしたけど、O(N^2logM)ぐらだったらいけそうだから、sortしなくても行けそう