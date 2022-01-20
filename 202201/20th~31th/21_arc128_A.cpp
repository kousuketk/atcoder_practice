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
  int flag = 0;  // 前のより高かったらflag = 1; 低かったらflag = -1;
  int idx = 0;
  vector<int> vec_ans(N);
  for(int i = 1; i < N; i++) {
    if(flag == 0) {
      if(vec[i-1] < vec[i]) flag = 1;
      else if(vec[i-1] > vec[i]) flag = -1, vec_ans[i-1] = 1;
      continue;
    }
    if(flag == 1) {
      if(vec[i-1] > vec[i]) {
        vec_ans[i-1] = 1;
        flag = -1;
      }
    } else if(flag == -1) {
      if(vec[i-1] < vec[i]) {
        vec_ans[i-1] = 1;
        flag = 1;
      }
    }
  }
  if(flag == -1) vec_ans[N-1] = 1;
  rep(i,N) cout << vec_ans[i] << " ";
  cout << endl;
}