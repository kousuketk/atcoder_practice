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
  int N, M; cin >> N >> M;
  vector<P> vec_one(M);
  vector<P> vec_two(M);
  rep(i,M) cin >> vec_one[i].first >> vec_one[i].second;
  rep(i,M) cin >> vec_two[i].first >> vec_two[i].second;
  sort(ALL(vec_one));
  sort(ALL(vec_two));
  vector<int> A(N);
  rep(i,N) A[i] = i+1;
  do {
    // vec_twoに対してM回繰り返す. c, dがjだったらA[j-1]の番号にすり替える
    vector<P> vec_tmp(M);  // 大小, sortしてvec_oneと比較する
    rep(i,M) {
      int c = vec_two[i].first;
      int d = vec_two[i].second;
      vec_tmp[i].first = min(A[c-1], A[d-1]);
      vec_tmp[i].second = max(A[c-1], A[d-1]);
    }
    sort(ALL(vec_tmp));
    bool flag = true;
    rep(i,M) {
      int a = vec_one[i].first;
      int b = vec_one[i].second;
      int c = vec_tmp[i].first;
      int d = vec_tmp[i].second;
      if(!(a == c && b == d)) {
        flag = false;
        break;
      }
    }
    if(flag) {
      cout << "Yes" << endl;
      return 0;
    }
  } while(next_permutation(ALL(A)));
  cout << "No" << endl;
  return 0;
}