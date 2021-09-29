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
  ll K, a, b; cin >> K >> a >> b;
  ll i = 0;
  ll after_a = 0;
  while(a > 0) {
    ll tmp = a % 10;
    after_a += tmp*pow(K, i);
    a = a / 10;
    i++;
  }
  i = 0;
  ll after_b = 0;
  while(b > 0) {
    ll tmp = b % 10;
    after_b += tmp*pow(K, i);
    b = b / 10;
    i++;
  }
  ll ans = after_a * after_b;
  cout << ans << endl;
  return 0;
}