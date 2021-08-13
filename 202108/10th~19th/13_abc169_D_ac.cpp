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
  ll N; cin >> N;
  // まずNの素因数分解をする
  vector<P> vec;
  for(ll i = 2; i*i <= N; i++) {
    if(N % i != 0) continue;
    ll ex = 0;
    while(N % i == 0) {
      ex++;
      N /= i;
    }
    vec.push_back({i,ex});
  }
  if(N != 1) vec.push_back({N,1});
  // 素因数分解した結果について条件を見ていく
  int ans = 0;
  for(auto e : vec) {
    int count = e.second;
    int tmp = 1;
    while(count-tmp >= 0) {
      count -= tmp;
      tmp++;
      ans++;
    }
  }
  cout << ans << endl;
}