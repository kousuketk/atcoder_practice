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
  ll N; cin >> N;
  ll x, M; cin >> x >> M;
  if(x == 0 || M == 1) {
    cout << "0" << endl;
    return 0;
  } else if(x == 1) {
    cout << N << endl;
    return 0;
  }
  ll ans = 0;
  ll before_count = 0;
  rep(i,20) {
    if(x >= M || i >= N) break;
    ans += x;
    before_count++;
    x = x*x;
  }
  if(before_count >= N) {
    cout << ans << endl;
    return 0;
  }
  // mod Mの世界でループすることを考える
  vector<ll> vec;
  ll vec_sum = 0;
  rep(i,M) {
    x = x % M;
    if(i != 0 && x == vec[0]) break;
    vec.push_back(x);
    vec_sum += x;
    x = x*x;
  }
  ll roop_count = (N-before_count)/vec.size();
  ans += vec_sum*roop_count;
  ll over_count = (N-before_count) - roop_count*vec.size();
  rep(i,over_count) ans += vec[i];
  cout << ans << endl;
}