#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N, Q; cin >> N >> Q;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  vector<ll> K(Q);
  rep(i,Q) cin >> K[i];
  for(ll k : K) {
    auto itr = upper_bound(A.begin(), A.end(), k);
    ll before_lower_count = itr - A.begin();
    auto itr2 = upper_bound(A.begin(), A.end(), k+before_lower_count);
    ll next_lower_count = itr2 - A.begin();
    while(before_lower_count != next_lower_count) {
      auto itr3 = upper_bound(A.begin(), A.end(), k+next_lower_count);
      before_lower_count = next_lower_count;
      next_lower_count = itr3 - A.begin();
    }
    cout << k+next_lower_count << endl;
  }
}