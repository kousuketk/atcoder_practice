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

bool is_prime(ll N) {
  if(N == 1) return false;
  for(ll i = 2; i*i <= N; i++) {
    if(N % i == 0) return false;
  }
  return true;
}

int main() {
  int N; cin >> N;
  int ans = 0;
  rep(i,N) {
    ll a; cin >> a;
    bool flag = is_prime(a);
    if(flag) ans++;
  }
  cout << ans << endl;
  return 0;
}