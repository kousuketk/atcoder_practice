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
  rep(i,N) cin >> X[i] >> Y[i];
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  ll x_max = X[N-1];
  ll x_second_max = X[N-2];
  ll x_second_min = X[1];
  ll x_min = X[0];
  ll y_max = Y[N-1];
  ll y_second_max = Y[N-2];
  ll y_second_min = Y[1];
  ll y_min = Y[0];
  if((x_max-x_min) == (y_max-y_min)) {
      cout << x_max-x_min << endl;
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