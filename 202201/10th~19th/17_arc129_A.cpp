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
  ll N, L, R; cin >> N >> L >> R;
  ll start = 1;
  rep(i,64) {
    if(start * 2 > L) break;
    start *= 2;
  }
  // startから初めて(最後に、もしstartがcountされるんだったら、L-startする)
  bool flag = false;
  ll ans = 0;
  rep(i,64) {
    // もしstartとNのxorで、その値が小さかったらflag=trueにして、次のstartまでの値をcntしていく
    ll tmp = start ^ N;
    flag = tmp < N;
    if(flag) {
      ans += start*2 - start;
      if(i == 0) ans -= L-start;
    }
    start *= 2;
    if(start > R) break;
  }
  if(flag) ans -= start-(R+1);
  cout << ans << endl;
}