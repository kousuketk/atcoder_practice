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
  ll N, K; cin >> N >> K;
  vector<ll> vec(N);
  vector<ll> vec2(N);
  rep(i,N) {
    ll tmp;
    cin >> tmp;
    vec[i] = tmp;
    vec2[i] = tmp;
  }
  ll all_count = K/N;
  ll K_after = K - (K/N)*N;
  sort(vec2.begin(), vec2.end());
  if(K_after == 0) {
    rep(i,N) {
      cout << all_count << endl;
    }
  } else {
    ll under_base = vec2[K_after-1];
    rep(i,N) {
      if(vec[i] <= under_base) cout << all_count + 1 << endl;
      else cout << all_count << endl;
    }
  }
  // vec2を通してk_afterがvec2[K_after-1]までが追加で受け取れる
  // 最後にfor文でvecを見る時、vec2[K_after-1]以下である要素は受け取れる
}