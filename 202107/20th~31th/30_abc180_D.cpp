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

const ll con = 1000000000;

int main() {
  ll x, y; cin >> x >> y;
  ll a, b; cin >> a >> b;
  ll ans = 0;
  while(x <= con && x*a <= b && x*a < y) {
    x = x*a;
    ans++;
  }
  if(x+b < y) ans += (y-x-1) / b;
  cout << ans << endl;
}