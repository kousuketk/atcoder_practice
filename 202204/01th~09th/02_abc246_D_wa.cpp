#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
// const ll INF = 1000000000000000000;
// const ll INF = 999999999999999999;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll N;
bool check(ll a, ll b) {
  ll tmp = pow(a,3) + pow(a,2)*b + a*pow(b,2) + pow(b,3);
  return tmp >= N;
}

int main() {
  cin >> N;
  ll sanjocon = cbrt(N);  // max(10^9)
  ll root = sqrt(sanjocon)-1;  // max(10^5)
  ll ans = INF;
  cout << sanjocon << endl;
  cout << root << endl;
  // root~sanjoconの範囲がaが取る範囲(bはa以下で2分探索で求めていく)
  for(ll a = root; a <= 2*sanjocon; a++) {
    ll left = -1;
    ll right = a+100;
    ll b;
    while(left+1 < right) {
      b = (left+right)/2;
      // if(a == root) cout << b << endl;
      if(check(a, b)) right = b;
      else left = b;
    }
    if(b < 0 || b > a) continue;
    ll tmp = (ll)pow(a,3) + (ll)(pow(a,2)*b) + (ll)(a*pow(b,2)) + (ll)pow(b,3);
    if(tmp >= N) {
      ans = min(ans, tmp);
      if(tmp = 999999999989449216) cout << ans << " " << a << " " << b << endl;
    }
  }
  cout << ans << endl;
}

// a = 629963, b = 629959