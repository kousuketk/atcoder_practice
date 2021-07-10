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
  int ans = 1;
  for(int i = 0; i < N; i++) {
    // vec[N-1-i]で後ろから順に見ていく
    // iの前までの要素の和：S[N-1-i]*2 >= vec[N-1-i]じゃなかったらbreakする
    if(S[N-1-i]*2 < vec[N-1-i]) break;
    ans++;
  }
  cout << ans << endl;
}