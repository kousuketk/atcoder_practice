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
  int N; cin >> N;
  vector<ll> vec(N);
  vector<ll> S(N+1);
  rep(i,N) cin >> vec[i];
  sort(ALL(vec), greater());
  rep(i,N) S[i+1] = S[i] + vec[i];
  ll ans = 0;
  rep(i,N-1) {
    // N-iをかける, vec[i]*((N-1)-i) - (S[N]-S[i+1])
    ans += vec[i]*((N-1)-i) - (S[N]-S[i+1]);
  }
  cout << ans << endl;
}