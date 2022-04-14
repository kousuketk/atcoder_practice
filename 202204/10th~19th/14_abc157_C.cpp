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

int main() {
  int N, M; cin >> N >> M;
  map<int, int> mp;
  rep(i,M) {
    int s, c; cin >> s >> c;
    if(mp.count(s) && mp[s] != c) {
      cout << -1 << endl;
      return 0;
    } else {
      mp[s] = c;
    }
  }
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    int cnt = mp.count(i);
    int c = mp[i];
    if(ans == 0 && i != N && c == 0 && cnt) {
      cout << -1 << endl;
      return 0;
    }
    if(ans == 0 && i != N && c == 0) c = 1;
    ans += c*pow(10, N-i);
  }
  cout << ans << endl;
  return 0;
}