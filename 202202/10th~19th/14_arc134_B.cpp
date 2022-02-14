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
  vector<ll> S(N);
  vector<ll> vec_tmp(N+2);
  rep(i,N) cin >> S[i];
  if(N < 3) {
    cout << "Yes" << endl;
    if(N == 1) cout << S[0] << " " << 0 << " " << 0 << endl;
    else cout << S[0] << " " << 0 << " " << 0 << " " << S[1] << endl;
    return 0;
  }
  ll a = 0, b = 0, c = 0;  // A0, A1, A2を仮に0と置く
  for(int i = 3; i < N+2; i++) {
    ll diff = vec_tmp[i-3] + S[i-2] - S[i-3];
    vec_tmp[i] = diff;  // 仮に0と置いたときのAiの値
    if(i % 3 == 0) a = min(a, diff);
    else if(i % 3 == 1) b = min(b, diff);
    else c = min(c, diff);
  }
  // それぞれ底上げをする
  for(int i = 0; i < N+2; i++) {
    if(i % 3 == 0) vec_tmp[i] -= a;
    else if(i % 3 == 1) vec_tmp[i] -= b;
    else vec_tmp[i] -= c;
  }
  ll diff_s = S[0] - (vec_tmp[0]+vec_tmp[1]+vec_tmp[2]);
  if(diff_s < 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  // aの要素だけ更に底上げする
  for(int i = 0; i < N+2; i++) {
    if(i % 3 == 0) vec_tmp[i] += diff_s;
  }
  rep(i,N+2) cout << vec_tmp[i] << " ";
  return 0;
}

// 最初にある制限は無視して仮に変数で置いて、最後にその変数が制約を満たしているかを判断する