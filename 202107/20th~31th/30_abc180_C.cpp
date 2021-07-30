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

vector<ll> enum_divisors(ll N) {
  vector<ll> res;
  for(ll i = 1; i*i <= N; i++) {
    if(N % i == 0) {
      res.push_back(i);
      if(N/i != i) res.push_back(N/i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  ll N; cin >> N;
  const auto &res = enum_divisors(N);
  for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
}