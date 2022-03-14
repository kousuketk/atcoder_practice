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
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  map<ll, ll> mp;
  rep(i,N) {
    ll a = vec[i];
    mp[a]++;
  }
  ll sum = 0;
  rep(i,N) {
    if(mp[i+1] <= 1) continue;
    ll tmp = mp[i+1];
    sum += tmp * (tmp-1) / 2;
  }
  rep(i,N) {
    ll a = vec[i];
    ll diff = 0;
    if(mp[a] > 1) {
      ll tmp = mp[a];
      diff = (tmp*(tmp-1)/2) - ((tmp-1)*(tmp-2)/2);
    }
    cout << (sum - diff) << endl;
  }
  return 0;
}