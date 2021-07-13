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
  int N, M; cin >> N >> M;
  vector<vector<int>> vec(N, vector<int>(M));
  rep(i,N)rep(j,M) {
    cin >> vec[i][j];
  }
  ll ans = 0;
  // 曲の選び方mC2(=N^2)
  for(int i = 0; i < M-1; i++) {
    for(int j = i+1; j < M; j++) {
      // 曲i,jを選択した時、グループの特典. それぞれvec[k][i], vec[k][j]
      ll group_score = 0;
      for(int k = 0; k < N; k++) {
        group_score += max(vec[k][i], vec[k][j]);
      }
      ans = max(ans, group_score);
    }
  }
  cout << ans << endl;
}