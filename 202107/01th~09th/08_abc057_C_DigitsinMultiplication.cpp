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
  ll N; cin >> N;
  int ans = INF;
  for(ll a = 1; a < 1000100; a++) {
    ll b = N/a;
    if(a*b != N) continue;
    ll c = max(a, b);
    ans = min(ans, (int)to_string(c).length());
  }
  cout << ans << endl;
}