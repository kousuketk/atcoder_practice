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
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  sort(vec.begin(), vec.end());
  // 累積和をとっておく
  vector<int> S(N+1);
  rep(i,N) S[i+1] = S[i] + vec[i];
  int ans = 0;
  for(int i = 0; i < N; i++) {
    ll sum = vec[i];
    int before_idx;
    while(true) {
      auto itr = upper_bound(vec.begin(), vec.end(), sum*2);
      if(itr == vec.end()) {
        ans++;
        break;
      }
      int idx = itr - vec.begin();
      if(idx == before_idx) break;
      sum = S[idx];
      before_idx = idx;
    }
  }
  cout << ans << endl;
}