#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  rep(i,N) cin >> A.at(i);
  rep(i,N) cin >> B.at(i);
  rep(i,N) cin >> C.at(i);
  ll count = 0;
  // Aをソートする, (N×logN)
  sort(A.begin(), A.end());
  for(ll i = 0; i < N; i++) {
    auto it_low = lower_bound(A.begin(), A.end(), B.at(C.at(i)-1));
    auto it_up = upper_bound(A.begin(), A.end(), B.at(C.at(i)-1));
    count += (it_up - it_low);
  }
  cout << count << endl;
}