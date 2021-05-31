#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<P> &vec) {
  for(auto V : vec) {
    cout << V.first << " " << V.second << endl;
  }
}

int main() {
  ll N, K;
  cin >> N >> K;
  vector<P> vec;
  for(ll i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    P tmp(a, b);
    vec.push_back(tmp);
  }
  sort(vec.begin(), vec.end());
  // printVec(vec);
  ll cash = K;
  ll place = 0;
  ll before_i = -1;
  while(cash > 0) {
    // placeより大きくdest以下にある街のB
    ll dest = place + cash;
    cash = 0;
    for(int i = before_i+1; i < N; i++) {
      if(vec[i].first > place && vec[i].first <= dest) {
        cash += vec[i].second;
        before_i = i;
      } else break;
    }
    place = dest;
  }
  cout << place << endl;
}