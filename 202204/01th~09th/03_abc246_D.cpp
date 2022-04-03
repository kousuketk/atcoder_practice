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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll MAX_A = 1000100;
ll N;
ll f(ll a, ll b) {
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

// a >= bとして、aを0~10^6まで全探索, bを0~aまでで2分探索
int main() {
  cin >> N;
  ll ans = INF;
  for(ll a = 0; a <= MAX_A; a++) {
    ll left = -1;
    ll right = a+1;
    while(left+1 < right) {
      ll mid = (left+right)/2;
      if(N <= f(a, mid)) right = mid;
      else left = mid;
    }
    ll tmp = f(a, right);
    if(tmp >= N) ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}