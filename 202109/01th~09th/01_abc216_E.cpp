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
int tousa_sum(int start, int end, int n) {
  return (start+end)*n/2;
}

int main() {
  ll N, K; cin >> N >> K;
  vector<ll> vec(N+1);
  rep(i,N) cin >> vec[i];
  sort(ALL(vec), greater<ll>());
  ll ans = 0;
  for(int i = 1; i <= N; i++) {
    ll diff = vec[i-1] - vec[i];
    ll cnt = diff*i;
    if(cnt <= K) {
      K -= cnt;
      ans += tousa_sum(vec[i-1], vec[i]+1, diff)*i;
    } else {
      ll d = K / i;
      ll s = K % i;
      ans += tousa_sum(vec[i-1], vec[i-1]-d+1, d)*i;
      ans += (vec[i-1]-d)*s;
      K = 0;
    }
  }
  cout << ans << endl;
}