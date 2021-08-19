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
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  vector<int> vec_i(N);
  vector<int> vec_j(N);
  rep(i,N) vec_i[i] = i+vec[i];
  rep(i,N) vec_j[i] = i-vec[i];
  sort(ALL(vec_i));
  sort(ALL(vec_j));
  ll count = 0;
  rep(i,N) {
    // upper_bound - lower_boundで個数を取れる
    count += upper_bound(ALL(vec_j), vec_i[i]) - lower_bound(ALL(vec_j), vec_i[i]);
  }
  cout << count << endl;
}

// O(N^2)をO(NlogN)にする問題
// 2つ(i,j)の関係を条件式から計算式に落とし込み、変形することで計算量を落とすことができる