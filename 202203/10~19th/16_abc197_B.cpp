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
// const ll MOD = 1100000007;
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
  for(int bit_i = 0; bit_i < (1<<(N-1)); bit_i++) {
    bitset<19> bit(bit_i);

    ll xor_val = 0;
    ll or_val = vec[0];
    for(int i = 0; i < N-1; i++) {
      if(bit.test(i)) {
        xor_val = xor_val ^ or_val;
        or_val = vec[i+1];
      } else {
        or_val = or_val | vec[i+1];
      }
    }
    xor_val = xor_val ^ or_val;
    ans = min(ans, xor_val);
  }
  cout << ans << endl;
  return 0;
}