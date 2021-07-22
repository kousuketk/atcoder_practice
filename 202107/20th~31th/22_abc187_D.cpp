#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<ll,ll,ll>;
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
  vector<T> vec(N);
  ll aoki = 0;
  ll taka = 0;
  rep(i,N) {
    ll a, b, c; cin >> a >> b;
    c = a*2 + b;
    aoki += a;
    vec[i] = T(c, a, b);
  }
  sort(ALL(vec), greater<tuple<ll,ll,ll>>());
  int visited = 0;
  rep(i,N) {
    aoki -= get<1>(vec[i]);
    taka += get<1>(vec[i]) + get<2>(vec[i]);
    visited++;
    if(taka > aoki) break;
  }
  cout << visited << endl;
}