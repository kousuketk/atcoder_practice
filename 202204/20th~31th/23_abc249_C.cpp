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
  int N, K; cin >> N >> K;
  vector<string> vec(N);
  rep(i,N) cin >> vec[i];
  int ans = 0;
  for(int i = 0; i < (1<<N); i++) {
    bitset<15> bits(i);
    int cnt = 0;
    for(char c = 'a'; c <= 'z'; c++) {
      int tmpCnt = 0;
      for(int j = 0; j < N; j++) {
        if(bits.test(j)) {
          // vec[j]にcが何種類あるか
          string str = vec[j];
          if(str.find(c) >= 0 && str.find(c) <= str.size()) tmpCnt++;
        }
      }
      if(tmpCnt == K) cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}