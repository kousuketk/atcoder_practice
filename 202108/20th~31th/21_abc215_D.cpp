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

int dp[100100];

int main() {
  // N*√Nで約数全部保持して
  // その要素についてエラトスして
  // O(M)で見ていく
  int N, M; cin >> N >> M;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  // 約数を全部入れる
  vector<int> vec_div;
  rep(i,N) {
    int tmp = vec[i];
    for(int j = 1; j*j <= tmp; j++) {
      if(tmp % j == 0) {
        vec_div.push_back(j);
        if(tmp/j != j) vec_div.push_back(tmp/j);
      }
    }
  }
  sort(ALL(vec_div));
  vec_div.erase(unique(ALL(vec_div)), vec_div.end());
  int size = vec_div.size();
  // エラトステネス
  for(int i = 1; i < size; i++) {
    int tmp = vec_div[i];
    for(int j = 1*tmp; j <= M; j += tmp) {
      dp[j]++;
    }
  }
  vector<int> vec_ans;
  vec_ans.push_back(1);
  for(int i = 2; i <= M; i++) {
    if(dp[i] == 0) vec_ans.push_back(i);
  }
  int vec_ans_size = vec_ans.size();
  cout << vec_ans_size << endl;
  rep(i,vec_ans_size) cout << vec_ans[i] << endl;
}