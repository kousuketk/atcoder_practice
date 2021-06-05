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
  int T;
  cin >> T; // T回のforループを回す
  int X, Y, P, Q;
  cin >> X >> Y >> P >> Q;
  int train_a, train1_b, train2_b;
  train_a = 2*X+2*Y; train1_b = X; train2_b = X+Y;
  int sleep_a, sleep1_b, sleep2_b;
  sleep_a = P+Q; sleep1_b = P; sleep2_b = P+Q;
  // 傾きがおなじとき
  if(train_a == sleep_a) {
    // sleepのy切片のほうが大きいとき、条件に当てはまればsleepのy切片を出力
    if(sleep1_b >= train1_b && train2_b-1 >= sleep1_b) {
      cout << sleep1_b << endl;
      return 0;
    } else if(train1_b > sleep1_b && sleep2_b-1 >= train1_b) {
      cout << train1_b << endl;
      return 0;
    } else {
      cout << "infinity" << endl;
    }
  }
  // 傾きが違うとき, 切片が共通
  if(sleep1_b <= train1_b && sleep2_b-1 >= train1_b) {
    cout << train1_b << endl;
    return 0;
  } else if(train1_b <= sleep1_b && train2_b-1 >= sleep1_b) {
    cout << sleep1_b << endl;
    return 0;
  }
  // 傾きが違うとき, 切片も共通でない
  if(sleep1_b > train1_b) {
    // sleepのほうが大きいとき、trainのグラフ
    // train_a*n + train2_b = sleep1_b
    int n = (sleep1_b-train2_b)/train_a;
    for(int i = 0; i < 100; i++) {
      for(int j = n; j < 1000; j++) {
        // train_min, train_max, sleep_min, sleep_max
        // train_max-1 >= sleep_min だったらsleep_minを出力
        int sleep_max = sleep_a*i + sleep2_b;
        int sleep_min = sleep_a*i + sleep1_b;
        int train_max = train_a*j + train2_b;
        int train_min = train_a*j + train1_b;
        if(train_max-1 >= sleep_min) {
          cout << sleep_min << endl;
          return 0;
        }
        if(sleep_max <= train_min) break;
      }
    }
  } else if(train1_b > sleep1_b) {
    // trainのほうが大きいとき、sleepのグラフ
    // sleep_a*n + sleep2_b = train1_b
    int n = (train1_b-sleep2_b)/sleep_a;
    for(int i = 0; i < 100; i++) {
      for(int j = n; j < 1000; j++) {
        // train_min, train_max, sleep_min, sleep_max
        // train_max-1 >= sleep_min だったらsleep_minを出力
        int sleep_max = sleep_a*i + sleep2_b;
        int sleep_min = sleep_a*i + sleep1_b;
        int train_max = train_a*j + train2_b;
        int train_min = train_a*j + train1_b;
        if(sleep_max-1 >= train_min) {
          cout << train_min << endl;
          return 0;
        }
        if(train_max <= sleep_min) break;
      }
    }
  }
}