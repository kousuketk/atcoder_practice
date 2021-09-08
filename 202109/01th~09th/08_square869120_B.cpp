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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  int N, K; cin >> N >> K;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  ll ans = INF;
  for(int tmp = 0; tmp < (1<<N); tmp++) {
    bitset<15> bit(tmp);
    if(__builtin_popcount(tmp) != K) continue;
    if(!bit.test(0)) continue;


    ll max_h = vec[0]-1;
    ll cost = 0;
    for(int i = 0; i < N; i++) {
      if(bit.test(i)) {  // i番目の建物で計算する。(最小値を出す)
        if(vec[i] > max_h) {
          max_h = vec[i];
        } else {
          cost += max_h - vec[i] + 1;
          max_h = max_h + 1;
        }
      } else {
        max_h = max(max_h, vec[i]);
      }
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}