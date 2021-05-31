#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
ll INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N);
  vector<ll> Y(N);
  // x_max, x_min, y_max, y_minだけ配列に入れて、
  P x_max(-INF,0), x_min(INF,0);
  P y_max(-INF,0), y_min(INF,0);
  ll x_second_max = -INF, x_second_min = INF;
  ll y_second_max = -INF, y_second_min = INF;
  rep(i,N) {
    ll x, y;
    cin >> x >> y;
    X[i] = x;
    Y[i] = y;
    if(x_max.first == x) {
      x_max.second++;
    } else if(x_max.first < x) {
      x_max.first = x;
      x_max.second = 1;
    } else if(x_max.first > x && x_second_max < x) {
      x_second_max = x;
    }
    if(x_min.first == x) {
      x_min.second++;
    } else if(x_min.first > x) {
      x_min.first = x;
      x_min.second = 1;
    } else if(x_min.first < x && x_second_min > x) {
      x_second_min = x;
    }
    if(y_max.first == y) {
      y_max.second++;
    } else if(y_max.first < y) {
      y_max.first = y;
      y_max.second = 1;
    } else if(y_max.first > y && y_second_max < y) {
      y_second_max = y;
    }
    if(y_min.first == y) {
      y_min.second++;
    } else if(y_min.first > y) {
      y_min.first = y;
      y_min.second = 1;
    } else if(y_min.first < y && y_second_min > y) {
      y_second_min = y;
    }
    // x_max, x_min, y_max, y_minにそれぞれの数とその個数を代入できた
  }
  cout << x_second_max << endl;
  cout << x_second_min << endl;
  cout << y_second_max << endl;
  cout << y_second_min << endl;
  // cout << x_max.first << " " << x_max.second << endl;
  // cout << x_min.first << " " << x_min.second << endl;
  // cout << y_max.first << " " << y_max.second << endl;
  // cout << y_min.first << " " << y_min.second << endl;
  // 同じ番号でなければ
  if((x_max.first-x_min.first) == (y_max.first-y_min.first)) {
      cout << x_max.first-x_min.first << endl;
      return 0;
  } else if((x_max.first-x_min.first) > (y_max.first-y_min.first) && 
  (x_max.second>1 || x_min.second>1)) {
    cout << x_max.first-x_min.first << endl;
    return 0;
  } else if((x_max.first-x_min.first) < (y_max.first-y_min.first) && 
  (y_max.second>1 || y_min.second>1)) {
    cout << y_max.first-y_min.first << endl;
    return 0;
  } else if((x_max.first-x_min.first) > (y_max.first-y_min.first)) {
    // x_max, x_minの組み合わせを除いた、(x_max-x_second_min), (x_second_max-x_min), (y_max-y_min)で比較(一番大きいものを出力)
  } else if((x_max.first-x_min.first) < (y_max.first-y_min.first)) {
    // y_max, y_minの組み合わせを除いた、(y_max-y_second_min), (y_second_max-y_min), (x_max-x_min)で比較(一番大きいものを出力)
  } else {
    cout << "例外" << endl;
    return 0;
  }
}