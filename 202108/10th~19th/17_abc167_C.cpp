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

int main() {
  int N, M, X; cin >> N >> M >> X;
  vector<int> vec_money(N);
  vector<vector<int>> vec_score(N, vector<int>(M));
  // int vec_score[N][M];
  rep(i,N) {
    rep(j,M+1) {
      if(j == 0) cin >> vec_money[i];
      else cin >> vec_score[i][j-1];
    }
  }
  int ans = INF;
  for(int i = 0; i < (1<<N); i++) {
    bitset<12> bit(i);

    vector<int> vec_sum_score(M);
    int sum_money = 0;
    for(int k = 0; k < N; k++) {
      if(bit.test(k)) {
        sum_money += vec_money[k];
        for(int j = 0; j < M; j++) {
          vec_sum_score[j] += vec_score[k][j];
        }
      }
    }
    bool flag = true;
    rep(j,M) if(vec_sum_score[j] < X) flag = false;
    if(flag) ans = min(ans, sum_money);
  }
  if(ans == INF) ans = -1;
  cout << ans << endl;
}