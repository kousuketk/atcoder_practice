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
  ll T; cin >> T;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  vector<ll> mae;
  for(int i = 0; i < (1<<N/2); i++) {
    bitset<20> bits(i);
    ll val = 0;
    for(int j = 0; j < N/2; j++) {
      if(!bits.test(j)) continue;
      val += A[j];
    }
    mae.push_back(val);
  }
  vector<ll> ato;
  int m = 0;
  if(N % 2 == 1) m = 1;
  for(int i = 0; i < (1<<(N/2+m)); i++) {
    bitset<20> bits(i);
    ll val = 0;
    for(int j = 0; j < (N/2+m); j++) {
      if(!bits.test(j)) continue;
      val += A[N/2 + j];
    }
    ato.push_back(val);
  }
  sort(ALL(mae));
  sort(ALL(ato));
  int siz = mae.size();
  ll ans = 0;
  for(int i = 0; i < siz; i++) {
    ll val = mae[i];
    ll rest = T - val;
    // restに対して、atoのvectorの2分探索をしていく
    auto itr = lower_bound(ALL(ato), rest);
    if(*itr == rest) ans = T;  // val + *itr
    if(itr == ato.begin()) continue;
    ans = max(ans, *(itr-1)+val);
  }
  cout << ans << endl;
  return 0;
}