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
  int N; cin >> N;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  ll ans = INF;
  for(int tmp = 0; tmp < (1<<(N-1)); tmp++) {
    bitset<20> bit(tmp);
    ll vec_xor = 0;
    ll now = vec[0];
    for(int i = 0; i < N-1; i++) {
      if(bit.test(i)) {
        vec_xor = vec_xor ^ now;
        now = vec[i+1];
      } else {
        now = now | vec[i+1];
      }
    }
    vec_xor = vec_xor ^ now;
    ans = min(ans, vec_xor);
  }
  cout << ans << endl;
}