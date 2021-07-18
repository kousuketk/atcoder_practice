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

int main() {
  int N, K; cin >> N >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  vector<int> S(N+1);  // i番目までで重複している数
  vector<int> tmp(1);
  tmp.push_back(vec[0]);
  rep(i,N-1) {
    // tmpになかったらlower_boundで探し入れていく
    auto itr = lower_bound(ALL(tmp), vec[i+1]);
    if(*itr != vec[i+1]) {
      S[i+2] = S[i+1];
      tmp.push_back(vec[i+1]);
    } else {
      S[i+2] = S[i+1] + 1;
    }
    sort(ALL(tmp));
  }
  // printVec(S);
  int ans = 0;
  for(int i = 0; i < N-K+1; i++) {
    ans = max(ans, S[i+K]-S[i]);
  }
  cout << ans << endl;
}

// 前処理するのは難易度高いらしい、→mapで処理していく