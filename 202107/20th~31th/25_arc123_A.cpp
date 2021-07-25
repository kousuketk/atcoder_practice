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
  int N = 3;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  ll b = vec[1] - vec[0];
  ll c = vec[2] - vec[1];
  ll ans;
  if(c <= b) {
    ans = b-c;
  } else {
    if((c-b) % 2 == 0) ans = (c-b)/2;
    else ans = (c-b)/2 + 1 + 1;
  }
  cout << ans << endl;
}