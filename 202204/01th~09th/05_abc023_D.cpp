#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int N;
vector<P> vec;
// x以下にできるか？
bool f(ll x) {
  vector<ll> tmp(N);
  rep(i,N) {
    ll h = vec[i].first;
    ll s = vec[i].second;
    if(h > x) return false;
    tmp[i] = (x-h)/s;
  }
  sort(ALL(tmp));
  rep(i,N) if(tmp[i] < (ll)i) return false;
  return true;
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  ll ng = -1;
  ll ok = INF;
  while(ng+1 < ok) {
    ll mid = (ng+ok)/2;
    if(f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}