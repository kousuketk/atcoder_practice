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
  vector<ll> vec_s(N);
  rep(i,N) cin >> vec_s[i];
  vector<ll> vec_ans(N);
  int min_idx = 0;
  ll min_val = INF;
  rep(i,N) {
    ll tmp; cin >> tmp;
    if(tmp < min_val) {
      min_val = tmp;
      min_idx = i;
    }
    vec_ans[i] = tmp; // 初期値を入れてく
  }
  // min_idxからO(N)で見ていく
  rep(i,N) {
    int idx = min_idx+i;
    if(idx >= N) idx -= N;
    if(idx == N-1) {
      vec_ans[0] = min(vec_ans[0], vec_ans[N-1]+vec_s[N-1]);
    } else {
      vec_ans[idx+1] = min(vec_ans[idx+1], vec_ans[idx]+vec_s[idx]);
    }
  }
  rep(i,N) cout << vec_ans[i] << endl;
}