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

// 
int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  if(N == 2) {
    if(vec[0] == 1) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
  }
  bool flag;  // 昇順：1, 降順：0
  if(abs(vec[0] - vec[1]) == 1) flag = (vec[1] > vec[0]);
  else flag = (vec[2] > vec[1]);
  int ans = N;
  if(flag) {  // 昇順の時、そのまま数えるor最初と最後に逆にする
    // そのまま数える(1がどこにあるか)
    int cnt;
    rep(i,N) {
      if(vec[i] == 1) {
        cnt = i;
        break;
      }
    }
    ans = min(ans, cnt);
    // 最初と最後に逆にする(配列を逆にして、Nがどこにあるか+2)
    reverse(ALL(vec));
    rep(i,N) {
      if(vec[i] == N) {
        cnt = i;
        break;
      }
    }
    ans = min(ans, cnt+2);
  } else {  // 降順の時、最初に逆するor最後に逆する
    // 最後に逆にする(Nがどこにあるか、最後に逆する+1)
    int cnt;
    rep(i,N) {
      if(vec[i] == N) {
        cnt = i;
        break;
      }
    }
    ans = min(ans, cnt+1);
    // 最初に逆する(最初に逆にして、1がどこにあるか+1)
    reverse(ALL(vec));
    rep(i,N) {
      if(vec[i] == 1) {
        cnt = i;
        break;
      }
    }
    ans = min(ans, cnt+1);
  }
  cout << ans << endl;
  return 0;
}