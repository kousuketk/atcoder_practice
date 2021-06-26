#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<ll,ll,ll>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N; cin >> N;
  vector<T> vec(N);
  rep(i,N) {
    ll t, l, r; cin >> t >> l >> r;
    vec[i] = T(l, r, t);
  }
  sort(vec.begin(), vec.end());
  ll count = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      ll ti = get<2>(vec[i]);
      ll li = get<0>(vec[i]);
      ll ri = get<1>(vec[i]);
      ll tj = get<2>(vec[j]);
      ll lj = get<0>(vec[j]);
      ll rj = get<1>(vec[j]);
      if(ti == 1 && tj == 1 || ti == 1 && tj == 2 
      || ti == 3 && tj == 1 || ti == 3 && tj == 2) {
        if(lj <= ri) count++;
      } else {
        if(lj < ri) count++;
      }
    }
  }
  cout << count << endl;
}