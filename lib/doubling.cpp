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
  ll N, K; cin >> N >> K;
  vector<int> vec(N);
  rep(i,N) {
    cin >> vec[i];
    vec[i]--;
  }
  int logk = 1;
  while ((1LL << logk) <= K) logk++;
  vector<vector<int>> doubling(logk, vector<int>(N));  // doubling[k][i]：i番目から2^k進んだ町
  for(int i = 0; i < N; i++) {
    doubling[0][i] = vec[i];
  }
  // 前処理doublingの計算
  for(int k = 0; k < logk-1; k++) {
    for(int i = 0; i < N; i++) {
      doubling[k+1][i] = doubling[k][doubling[k][i]];
    }
  }
  int now = 0;
  for(int k = 0; K > 0; k++) {
    if(K & 1) now = doubling[k][now];
    K = K >> 1;
  }
  cout << now+1 << endl;
}

// https://algo-logic.info/doubling/