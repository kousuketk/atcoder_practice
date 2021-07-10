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
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  // 符号を決めると、その符号での操作回数のminがわかる
  // 最初がプラスの時(偶数がプラス, 奇数はマイナス)
  ll sum_plus = 0;
  ll count_plus = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) {
      // プラスでないといけない
      if((sum_plus + vec[i]) <= 0) {
        count_plus += abs(sum_plus + vec[i]) + 1;
        sum_plus = 1;
      } else {
        sum_plus += vec[i];
      }
    } else {
      // マイナスでないといけない
      if((sum_plus + vec[i]) >= 0) {
        count_plus += abs(sum_plus + vec[i]) + 1;
        sum_plus = -1;
      } else {
        sum_plus += vec[i];
      }
    }
  }
  // 最初がマイナスの時(偶数がマイナス, 奇数はプラス)
  ll sum_minus = 0;
  ll count_minus = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) {
      // マイナスでないといけない
      if((sum_minus + vec[i]) >= 0) {
        count_minus += abs(sum_minus + vec[i]) + 1;
        sum_minus = -1;
      } else {
        sum_minus += vec[i];
      }
    } else {
      // プラスでないといけない
      if((sum_minus + vec[i]) <= 0) {
        count_minus += abs(sum_minus + vec[i]) + 1;
        sum_minus = 1;
      } else {
        sum_minus += vec[i];
      }
    }
  }
  cout << min(count_plus, count_minus) << endl;
}