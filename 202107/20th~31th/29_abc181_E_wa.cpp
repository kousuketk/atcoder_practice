#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N, M; cin >> N >> M;
  vector<int> H(N);
  vector<int> W(M);
  
  rep(i,N) cin >> H[i];
  sort(H.begin(), H.end());
  rep(i,M) cin >> W[i];
  vector<ll> S1(N);
  vector<ll> S2(N);
  for(int i = 1; i < N; i++) {
    if(i % 2 == 1) S1[i] = S1[i-1] + abs(H[i]-H[i-1]);
    else S1[i] = S1[i-1];
  }
  for(int i = 1; i < N; i++) {
    if(i % 2 == 0) S2[i] = S2[i-1] + abs(H[i]-H[i-1]);
    else S2[i] = S2[i-1];
  }
  ll ans = INF;
  rep(i,M) {
    // W[i]を入れたときの順番が偶奇で場合分け
    int idx = lower_bound(H.begin(), H.end(), W[i]) - H.begin();
    ll tmp;
    if(idx % 2 == 0) {
      if(idx == 0) tmp = S2[N-1] + abs(W[i]-H[idx]);
      else tmp = S1[idx-1] + S2[N-1] - S2[idx] + abs(W[i]-H[idx-1]);
    } else {
      if(idx == 0) tmp = S2[N-1] + abs(W[i]-H[idx]);
      else if(idx == N) tmp = S1[N-1] + abs(W[i]-H[N-1]);
      else tmp = S1[idx-1] + S2[N-1] - S2[idx-1] + abs(W[i]-H[idx-1]);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}